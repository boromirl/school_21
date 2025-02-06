#include "../s21_decimal.h"

// вспомогательные функции деления (static значит, что они используются только в
// этом си файле)
static int find_closest_shift(s21_big_decimal val_1, s21_big_decimal val_2);
static void s21_div_with_remainder(s21_big_decimal val_1, s21_big_decimal val_2,
                                   s21_big_decimal *result,
                                   s21_big_decimal *remainder);

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int return_code = 0;
  s21_big_decimal big_value_1, big_value_2, big_result;

  // перевод в рабочий формат
  decimal_to_big(value_1, &big_value_1);
  decimal_to_big(value_2, &big_value_2);
  zero_big_decimal(&big_result);

  // если у чисел одинаковый знак, то результат положительный
  if (big_value_1.sign == big_value_2.sign) big_result.sign = 0;
  // если разные, то отрицательный
  else
    big_result.sign = 1;

  // изначально устанавливаем у результата стпень вычитанием (затем она будет
  // изменяться)
  big_result.scale = big_value_1.scale - big_value_2.scale;
  // зануляем scale у рабочих чисел (это нужно для правильной работы
  // is_greater_number, для деления нужно знать какое число больше без scale)
  big_value_1.scale = 0;
  big_value_2.scale = 0;

  // переменная, хранящая остаток. Изначально хранит первое значение, затем
  // уменьшается по ходу выполнения деления
  s21_big_decimal remainder;
  remainder = big_value_1;

  // проверка на нули. Если второе значение = 0, то ошибка деления на ноль. Если
  // первое значение равно нулю, то результат всегда 0
  if (is_big_zero(big_value_2))  // если второе число 0
    return_code = 3;
  else if (is_big_zero(big_value_1))  // если первое - 0
    zero_big_decimal(&big_result);
  else {
    // Флаг для выхода из цикла деления
    int flag = 0;
    // 28-й знак после запятой последний, но предусмотрено его кругление вверх.
    // Для этого необходимы переменные, которые хранят последний и предпоследний
    // знаки (end и last_digit далее)
    int end = 0;
    while (!flag) {
      // для деления необходимо, чтобы делимое было больше делителя, поэтому
      // мы умножаем делимое на 10, пока оно не будет больше делителя, и за
      // каждое умножение меняем стпень результата (дописываем в результат
      // десятичный ноль) в качестве делимого выступает остаток. Остаток
      // изначально равен первому значению, а затем собственно остатку. деление
      // происходит подобно делению в столбик. Делим -> получаем целое значение
      // -> берем вместо делимого остаток -> если не хватает дописываем ноль к
      // остатку и к результату -> делим дальше
      while (s21_is_greater_number(big_value_2, remainder)) {
        mult_big_decimal_by_10(&remainder);
        change_scale(&big_result, big_result.scale + 1);
      }
      // временный результат деления. Хранит результат деления на данном круге
      // цикла. Прибавляем к общему результату
      s21_big_decimal temp;
      zero_big_decimal(&temp);
      // деление с остатком. Получаем результат деления в temp и  остаток от
      // деления в remainder
      s21_div_with_remainder(remainder, big_value_2, &temp, &remainder);
      // прибавляем результат деления на данном круге цикла к общему
      add_big_bits(temp, big_result, &big_result);
      // если нет остатка, нужно выходить и зцикла
      if (is_big_zero(remainder)) flag = 1;
      // Для обработки длинных и бесконечных дробных чисел
      if (big_result.scale > 28) {
        flag = 1;
        // получаем последнюю цифру числа, предпоследняя хранится в last_digit
        int last_digit = get_last_digit_of_big(big_result);
        // число десять в виде биг дециамал. Не 1, так как нужно изменить
        // предпоследнюю цифру, а не последнюю. Последняя удалится при
        // приведении к 28 scale
        s21_big_decimal ten = {{10, 0, 0, 0, 0, 0, 0}, 0, 0};
        // ten = shift_big_left(ten, big_result.scale - 27);

        // банковское округлние
        if (last_digit > 5 || (last_digit == 5 && end % 2 == 1)) {
          add_big_bits(big_result, ten, &big_result);
        }
        // приведение к допустимому scale
        change_scale(&big_result, 28);
      }
      end = get_last_digit_of_big(temp);
    }
    if (big_result.bits[3] != 0) {
      // обработка переполнения 3-го битса. Функция будет делить число на 10,
      // пока scale не дойдет до нуля или число не влезет в мантиссу
      handle_high_overflow(&big_result);
    }
    // если получился слишком большой scale, меняем его до допустимого
    if (big_result.scale > 28) change_scale(&big_result, 28);
    // в делении scale может оказаться отрицательным
    if (big_result.scale < 0) change_scale(&big_result, 0);

    // если результат равен нулю, зануляем степень (ноль хранится без степени,
    // но это можно изменить, тогда придется менять тестовые данные)
    if (is_big_zero(big_result)) big_result.scale = 0;
  }

  // если результат влезает
  if (does_big_fit_into_decimal(big_result)) {
    // перевод результата в децимал
    big_to_decimal(big_result, result);
  }
  // если не влезает и положительно -> слишком большое число
  else if (big_result.sign == 0) {
    return_code = 1;
  }
  // если не влезает и отрицательно -> слишком маленькое число
  else if (big_result.sign == 1) {
    return_code = 2;
  }
  return return_code;
}

// функция деления с остатком
static void s21_div_with_remainder(s21_big_decimal val_1, s21_big_decimal val_2,
                                   s21_big_decimal *result,
                                   s21_big_decimal *remainder) {
  zero_big_decimal(remainder);
  zero_big_decimal(result);

  // работаем в функции с остатком. Изначально он равен первому числу, затем
  // будет постепенно уменьшаться
  *remainder = val_1;

  // делать это, пока остаток не меньше делителя. Если остаток меньше делителя,
  // деление закончено (очевидно, что остаток в конце должен быть меньше
  // делителя)
  do {
    // на сколько влево можно сдинуть делитель, чтобы он не стал больше делимого
    int shift = find_closest_shift(*remainder, val_2);
    s21_big_decimal power_of_two, shifted_val_2;
    zero_big_decimal(&power_of_two);
    zero_big_decimal(&shifted_val_2);
    // если сдвигать можно
    if (shift > -1) {
      power_of_two.bits[0] = 1;
      power_of_two = shift_big_left(power_of_two, shift);
      // прибавляем к результату степень двойки
      add_big_bits(*result, power_of_two, result);
      // получаем сдвинутое значение делителя
      shifted_val_2 = shift_big_left(val_2, shift);
    }
    // вычитаем сдвинутый делитель из делимого
    subtract_big_bits(*remainder, shifted_val_2, remainder);
  } while (!s21_is_less_number(*remainder, val_2));
}

// сдвигаем второе число влево (умножаем на 2) пока не найдем самый большой
// сдвиг, при котором val_2 <= val_1
static int find_closest_shift(s21_big_decimal val_1, s21_big_decimal val_2) {
  int shift = 0;  // счетчик сдвигов
  while (!s21_is_greater_number(
      val_2, val_1)) {  // пока первое не станет больше второго
    val_2 = shift_big_left(val_2, 1);  // сдвиг второго числа на 1 бит влево
    shift++;                           // увеличиваем счетчик
  }
  return (shift - 1);  // возвращаем на 1 меньше, т.к. заключительный сдвиг
                       // сделал val2 больше val1
}