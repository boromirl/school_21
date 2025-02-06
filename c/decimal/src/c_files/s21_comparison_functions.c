#include "../s21_decimal.h"

/*для сравнения двух числе типа децимал, определения меньше
ли первое число второго, возвращает 1 если первое число меньше
второго, иначе - 0, если оба равны - тоже 0*/
int s21_is_less(
    s21_decimal num1,
    s21_decimal num2) {  // два числа (структуры) типа децимал, локальные копии
                         // структур, чтобы случайно не повредить оригинал и
                         // избежать утечек памяти
  int result = -1;  // переменная для результата сравнения, -1 неопределенность

  s21_big_decimal big_num1, big_num2;  // создаем большие переменные

  decimal_to_big(num1, &big_num1);  // переводим числа в большие (рабочие) числа
  decimal_to_big(num2, &big_num2);

  if (s21_is_equal(
          num1, num2)) {  // если числа равны, то меньшим быть не может ни одно
    result = 0;
  } else if ((big_num1.sign == big_num2.sign) &&
             (big_num1.sign == 0)) {  // если оба числа положительные
    result = s21_is_less_number(big_num1, big_num2);  // сравниваем их
  } else if (big_num1.sign == 1 &&
             big_num2.sign == 0) {  // если первое число отрицательное, а второе
                                    // положительное
    result = 1;  // очевидно, что отрицательное всегда меньше
  } else if (big_num1.sign == 0 &&
             big_num2.sign ==
                 1) {  // если первое положительное, а второе отрицательное
    result = 0;  // очевидно, что первое больше как положительное
  } else if ((big_num1.sign == big_num2.sign) &&
             (big_num1.sign == 1)) {  // если оба числа отрицательные
    result = !s21_is_less_number(big_num1, big_num2);
  }
  return result;
}

/*проверка меньше или равно*/
int s21_is_less_or_equal(s21_decimal num1, s21_decimal num2) {
  int res = 0;  // инициализация результата нулем (т.е. по умолчанию num1 не
                // меньше и не равно num2)
  if (s21_is_less(num1, num2) || s21_is_equal(num1, num2)) {
    res = 1;  // это и означает, что меньше либо равно
  }
  return res;
}

/*для сравнения двух числе, определения больше ли первое
число второго. Возвращает 1, если первое число больше второго
иначе - 0*/
int s21_is_greater(s21_decimal num1,
                   s21_decimal num2) {  // два числа (структуры) типа децимал
  int result =
      -1;  // переменная для результата сравнения, -1 - т.к. неопределенность

  s21_big_decimal big_num1, big_num2;  // создаем большие переменные

  decimal_to_big(num1, &big_num1);  // переводим числа в большие (рабочие) числа
  decimal_to_big(num2, &big_num2);

  if (s21_is_equal(
          num1, num2)) {  // если числа равны, то меньшим быть не может ни одно
    result = 0;
  } else if ((big_num1.sign == big_num2.sign) &&
             (big_num1.sign == 0)) {  // если оба числа положительные
    result = s21_is_greater_number(big_num1, big_num2);  // сравниваем их
  } else if (big_num1.sign == 1 &&
             big_num2.sign == 0) {  // если первое число отрицательное, а второе
                                    // положительное
    result = 0;  // очевидно, что второе число больше
  } else if (big_num1.sign == 0 &&
             big_num2.sign == 1) {  // если второе число отрицательное, а превое
                                    // положительное
    result = 1;  // очевидно, что первое больше
  } else if ((big_num1.sign == big_num2.sign) &&
             (big_num1.sign == 1)) {  // если оба числа отрицательные
    result = !s21_is_greater_number(big_num1, big_num2);
  }
  return result;
}

/*проверка на больше либо равно*/
int s21_is_greater_or_equal(s21_decimal num1, s21_decimal num2) {
  int res = 0;
  if (s21_is_greater(num1, num2) || s21_is_equal(num1, num2)) {
    res = 1;
  }
  return res;
}

/*для сравнения двух чисел, возвращает 1 если равны,
0 - если не равны*/
int s21_is_equal(s21_decimal num1, s21_decimal num2) {
  int res = 0;  // инициализация результата сравнения

  s21_big_decimal big_num1, big_num2;  // создаем большие переменные

  decimal_to_big(num1, &big_num1);  // переводим числа в большие (рабочие) числа
  decimal_to_big(num2, &big_num2);

  if (big_num1.sign != big_num2.sign) {  // сравнение знаков
    res = 0;  // если не совпадают - возврат 0
  } else {
    normalize(&big_num1,
              &big_num2);  // выравнивание скейлов двух десятичных чисел
    res = equal_bits(big_num1, big_num2);  // проверка равенства битов чисел
  }
  return res;
}

/*для проверки неравенства двух чисел*/
int s21_is_not_equal(s21_decimal num1, s21_decimal num2) {
  return !s21_is_equal(num1, num2);
  // просто возвращаем отрицание результата функции s21_is_equal
}