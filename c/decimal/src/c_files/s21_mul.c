#include "../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int return_code = 0;
  s21_big_decimal big_value_1, big_value_2, big_result;

  decimal_to_big(value_1, &big_value_1);
  decimal_to_big(value_2, &big_value_2);
  zero_big_decimal(&big_result);

  // если у чисел одинаковый знак, то результат положительный
  if (big_value_1.sign == big_value_2.sign) big_result.sign = 0;
  // если разные, то отрицательный
  else
    big_result.sign = 1;

  // если в бите первого числа 1, то второе число умножаем на 2 в i-ой степени
  // (т. е. по факту сдвигаем на i влево) и прибавляем это к результату
  for (int i = 0; i < 96; i++) {
    if (get_mantissa(value_1, i) == 1) {
      s21_big_decimal shifted_big = shift_big_left(big_value_2, i);
      add_big_bits(big_result, shifted_big, &big_result);
    }
  }
  // вычисляем положение запятой
  big_result.scale = big_value_1.scale + big_value_2.scale;

  // если получился слишком большой scale, меняем его до допустимого
  if (big_result.scale > 28) change_scale(&big_result, 28);

  // если число не влезает в мантиссу
  if (big_result.bits[3] != 0) {
    // обработка переполнения 3-го битса. Функция будет делить число на 10, пока
    // scale не дойдет до нуля или число не влезет в мантиссу
    handle_high_overflow(&big_result);
  }
  // change_scale(&big_result, big_result.scale - scale_diffenrence);

  if (is_big_zero(big_result)) big_result.sign = 0;

  // если результат влезает
  if (does_big_fit_into_decimal(big_result)) {
    // перевод результата в децимал
    big_to_decimal(big_result, result);
    return_code = 0;
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