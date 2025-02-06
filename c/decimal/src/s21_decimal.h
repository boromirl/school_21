#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#define MAX32INT \
  0xffffffff  // самое большое значение uint32 (32 единицы), в шестнадцатеричной
              // (для укорачивания)
#define HIGHBITS 0xffffffff00000000  // старшие 32 бита в uint64
#define LOWBITS 0x00000000ffffffff   // младшие 32 бита в uint64

#define SIGN_POS \
  127  // 127 т.к. в числе типа децимал знак находится на 127 позиции (128 бите)
#define TRUE 1
#define FALSE 0

#define is_inf(x) \
  __builtin_isinf(x)  // макрос, который проверяет, является ли значение x
                      // бесконечностью возвращает ненулевое значение или 0
#define is_nan(x) \
  __builtin_isnan(x)  // макрос, проверяет, является ли значение х не числом

#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>  // для работы с инт32, инт64
#include <stdio.h>
#include <stdlib.h>  // для atoi
#include <string.h>

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  uint64_t bits[7];
  int sign;
  int scale;
} s21_big_decimal;

// Арифметические операции
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// Функции сравнения
int s21_is_less(s21_decimal, s21_decimal);
int s21_is_less_or_equal(s21_decimal, s21_decimal);
int s21_is_greater(s21_decimal, s21_decimal);
int s21_is_greater_or_equal(s21_decimal, s21_decimal);
int s21_is_equal(s21_decimal, s21_decimal);
int s21_is_not_equal(s21_decimal, s21_decimal);

// Преобразователи
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

// Округление до ближайшего целого в сторону отрицательной бесконечности
int s21_floor(s21_decimal value, s21_decimal *result);

// Округление до ближайшего целого числа
int s21_round(s21_decimal value, s21_decimal *result);

// Целая часть числа
int s21_truncate(s21_decimal value, s21_decimal *result);

// Умножение на -1
int s21_negate(s21_decimal value, s21_decimal *result);

// Вспомогательные функции

// Получить значение одного бита в интеджере по индексу
int get_bit(unsigned int src, int ind);

// Установить значение бита по индексу
void set_bit(unsigned int *src, int ind, int value);

// Получить значение одного бита в мантиссе (трёх битах, в которых хранится само
// числовое значение) по индексу
int get_mantissa(s21_decimal decimal, int ind);

// Установить значение одного бита в мантиссе по индексу
void set_mantissa(s21_decimal *src, int ind, int value);

int get_sign(s21_decimal *num);

// установление знака в decimal
void set_sign(s21_decimal *decimal, int sign);

bool test_bit(unsigned int value, int BitNumber);

// получить степень decimal
int get_scale(s21_decimal decimal);

// установить степень decimal
void set_scale(s21_decimal *decimal, unsigned int scale);

// Заполнение децимала нулями
void zero_decimal(s21_decimal *decimal);

// заполнение big decimal нулями
void zero_big_decimal(s21_big_decimal *big_decimal);

// перевод big_decimal в decimal
void big_to_decimal(s21_big_decimal src, s21_decimal *dst);

// перевод decimal в big_decimal
void decimal_to_big(s21_decimal src, s21_big_decimal *dst);

// обработка переполнения (перенос в старшие биты)
void handle_overflow(s21_big_decimal *b_dec);

// обработка переполнения старших бита (деление на 10, пока не влезет в decimal)
void handle_high_overflow(s21_big_decimal *b_dec);

// умножение big_decimal на число
void mult_big_decimal_by_10(s21_big_decimal *b_dec);

// деление big_decimal на число БЕЗ ИЗМЕНЕНИЯ SCALE
void div_big_decimal_by_10(s21_big_decimal *b_dec);

// изменение scale числа с умножением/делением на 10
void change_scale(s21_big_decimal *b_dec, int new_scale);

// Нормализация чисел (приведение к одинаковому scale)
void normalize(s21_big_decimal *b_dec1, s21_big_decimal *b_dec2);

// перевести число в дополнительную двоичную форму (перевернуть биты и прибавить
// 1)
void make_bid_decimal_compliment(s21_big_decimal *b_dec);

/* сравнение двух биг децимал чисел без учета знака, но с приведением к одной
экспоненте (ТОЛЬКО ВНУТРИ ФУНКЦИИ, ЧИСЛА ИЗМЕНЯЮТСЯ И СРАВНИВАЮТСЯ ВНУТРИ, ЗА
ПРЕДЕЛАМИ ФУНКЦИИ ОНИ ОСТАЮТСЯ НЕИЗМЕННЫМИ)*/
int s21_is_less_number(s21_big_decimal num1, s21_big_decimal num2);

/*для сравнения несовпавших битов, возвращает 1 если 1-й бит
меньше второго, иначе 0*/
int compare_not_equal_bit(uint64_t bit1, uint64_t bit2);

/* Функция подобная s21_is_less_number, только наоборот
сравнение двух биг децимал чисел без учета знака, но с приведением к одной
экспоненте (ТОЛЬКО ВНУТРИ ФУНКЦИИ! ЧИСЛА ИЗМЕНЯЮТСЯ И СРАВНИВАЮТСЯ ВНУТРИ,А ЗА
ПРЕДЕЛАМИ ФУНКЦИИ ОНИ ОСТАЮТСЯ НЕИЗМЕННЫМИ)*/
int s21_is_greater_number(s21_big_decimal num1, s21_big_decimal num2);

int equal_bits(s21_big_decimal num1, s21_big_decimal num2);

void set_bit1(s21_decimal *num, int ind);
/*для установки определенного бита в структуре децимал, еще одна функция,
нужна конкретно для моей функции конвертации из инт в децимал*/

void set_zero(s21_decimal *num);
/*для заполнения всех битов с структуре децимал нулями,
нужно чтобы сбросить значение в структуре для ее дальнейшего
использования - установки нового значения*/

int s21_from_float_string(int whole, float fraction, s21_decimal *value);
/*для преобразования целового и дробного числа, разделенных
на отдельные элементы в строковое представление, затем
оно используется для создания числа децимал*/

// сложение всех bits в big_decimal друг с другом с обработкой переполнений
void add_big_bits(s21_big_decimal big_value_1, s21_big_decimal big_value_2,
                  s21_big_decimal *result);

// получение последнего десятичного символа биг децимал
// функция проверяет все биты биг децимал, и использует периодичность последних
// знаков степеней двойки
int get_last_digit_of_big(s21_big_decimal b_dec);

// получение значение бита во всем биг децимал по индексу
int get_bit_big(s21_big_decimal b_dec, int ind);

// проверяет, вместится ли биг децимал в децимал
int does_big_fit_into_decimal(s21_big_decimal b_dec);

// проверяет, является ли биг децимал нулем
int is_big_zero(s21_big_decimal b_dec);

// сдвигает биг децимал на определенное количество бит влево
s21_big_decimal shift_big_left(s21_big_decimal b_dec, int shift);

// вычитание битс через сложение
void subtract_big_bits(s21_big_decimal val_1, s21_big_decimal val_2,
                       s21_big_decimal *result);

#endif