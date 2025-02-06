#include "../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int scale = get_scale(value);  // сначала определим скейл
  if (scale <= 0) {  // Если scale <= 0, то дробной части уже нет.
    *result = value;  // число и так целое
  } else {
    int sign = get_sign(&value);     // проверяем знак
    s21_decimal temp_small = value;  // временная переменная
    s21_decimal one = {{0x00000001, 0x00000000, 0x00000000, 0x00000000}};  // 1
    if (sign == 1) {  // Сделаем из отрицательного положительное ради упрощения
      s21_negate(temp_small, &temp_small);
    }
    s21_big_decimal temp;
    decimal_to_big(temp_small, &temp);
    change_scale(&temp, 1);  // устанавливаем скейл 1 для удобства округления

    int last_digit =
        get_last_digit_of_big(temp);  // получить последнюю цифру большого числа
    if (last_digit ==
        0) {  // 115.0 == 115, если последняя цифра 0, то число уже целое
      *result = value;
    } else {
      if (sign == 0) {  // Если позитивное, то просто обрезаем
        s21_truncate(value, result);
      } else {  // Если знак был минус - надо прибавить единицу и поменять знак
        change_scale(&temp, 0);
        big_to_decimal(temp, &temp_small);
        s21_add(temp_small, one, &temp_small);
        s21_negate(temp_small, &temp_small);
        *result = temp_small;
      }
    }
  }
  return 0;
}
// округление вниз до ближайшего целого