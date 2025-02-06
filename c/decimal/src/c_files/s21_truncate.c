#include "../s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  s21_big_decimal temp;
  decimal_to_big(value, &temp);
  change_scale(&temp, 0);
  big_to_decimal(temp, result);
  return 0;
}
// удаляет дробную часть