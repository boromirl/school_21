#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  s21_decimal temp;  // для хранения временного результата после усечения
                     // десятичной части числа
  s21_truncate(src, &temp);  // усечение десятичной части числа
  unsigned int tempint = temp.bits[0];  // извлечение младших 32-х битов
  if (tempint > 0x7FFFFFFF) {  // проверка на переполнение
    tempint = 0x7FFFFFFF;  // Предельно допустимый int (т.е. 32 единицы)
  }
  int sign = get_sign(&temp);  // 0 = + || 1 = - здесь получам знак числа
  *dst = tempint;  // запись значения в дст
  if (sign == 1) {
    *dst *= -1;  // применение знака, если 1 то делаем отрацительным
  }
  return 0;
}