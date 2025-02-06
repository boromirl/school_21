#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int sign = 0;  // для хранения знака числа
  if (src < 0) {
    sign = 1;
    src *= -1;  // умножение на -1, чтобы сделать отрицатеельным числом
  }
  unsigned int uns_src =
      src;  // присвоение уже положительного числа новой переменной
  zero_decimal(dst);  // заполнение структуры децимал нулями
  dst->bits[0] = uns_src;  // число записывается в 1-й массив битс
  set_sign(dst, sign);  // установка знака
  return 0;
}