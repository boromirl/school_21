#include "../s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int scale = get_scale(value);
  if (scale <= 0) {  // Если scale <= 0, то дробной части уже нет.
    *result = value;
  } else {
    int sign = get_sign(&value);
    s21_decimal temp_small = value;
    s21_decimal one = {{0x00000001, 0x00000000, 0x00000000, 0x00000000}};  // 1
    if (sign == 1) {  // Сделаем из отрицательного положительное ради упрощения
      s21_negate(temp_small, &temp_small);
    }
    s21_big_decimal temp;
    decimal_to_big(temp_small, &temp);
    change_scale(&temp, 1);

    int last_digit = get_last_digit_of_big(temp);
    if (last_digit == 0) {  // 115.0 == 115
      *result = value;
    } else {
      if (sign == 0) {  // П0зитивное
        if (last_digit >= 5) {
          change_scale(&temp, 0);
          big_to_decimal(temp, &temp_small);
          s21_add(temp_small, one, &temp_small);
          *result = temp_small;
        } else {
          change_scale(&temp, 0);
          big_to_decimal(temp, &temp_small);
          *result = temp_small;
        }
      } else {  // Hegативнoe
        if (last_digit >= 5) {
          change_scale(&temp, 0);
          big_to_decimal(temp, &temp_small);
          s21_add(temp_small, one, &temp_small);
          s21_negate(temp_small, &temp_small);
          *result = temp_small;
        } else {
          change_scale(&temp, 0);
          big_to_decimal(temp, &temp_small);
          s21_negate(temp_small, &temp_small);
          *result = temp_small;
        }
      }
    }
  }
  return 0;
}
// округление до ближайшего целого числа