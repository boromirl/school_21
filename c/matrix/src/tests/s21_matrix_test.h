#ifndef S21_MATRIX_TEST_H
#define S21_MATRIX_TEST_H

#include <check.h>
#include <stdio.h>

#include "../s21_matrix.h"

// цвета вывода сообщений в терминале
#define RESET "\e[0m"
#define RED "\e[31m"
#define GRAY_BG "\e[100m"
#define GREEN_BG "\e[42m"
#define MAGENTA "\e[35m"
#define RED_BG "\e[41m"
#define WHITE "\e[97m"

Suite *suite_create_matrix();
Suite *suite_remove_matrix();

Suite *suite_eq_matrix();

Suite *suite_sum_matrix();
Suite *suite_sub_matrix();

Suite *suite_mult_number();
Suite *suite_mult_matrix();

Suite *suite_transpose();

Suite *suite_calc_complements();

Suite *suite_determinant();

Suite *suite_inverse_matrix();

#endif