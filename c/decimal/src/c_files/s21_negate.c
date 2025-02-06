#include "../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  *result = value;
  if (value.bits[0] == 0 && value.bits[1] == 0 &&
      value.bits[2] == 0) {  // проверяем является ли число нулевым
    if (get_sign(&value))  // Если отрицательное (знак == 1)
    {
      set_sign(result, 0);
    }  // Если положительное, то меняем. Нет минус нулю!
  } else {
    if (get_sign(&value))  // Если отрицательное ( == 1)
    {
      set_sign(result, 0);  // устанавливаем положительный знак
    } else                  // Если положительное
    {
      set_sign(result, 1);  // устанавливаем отрицательный знак
    }
  }

  return 0;
}
/*меняет знак числа на противоположный*/