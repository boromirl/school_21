#include "../s21_matrix_test.h"

// неинициализированные матрицы
START_TEST(s21_eq_matrix_1) {
  matrix_t A = {};
  matrix_t B = {};
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

// инициализированные, зануленные матрицы
START_TEST(s21_eq_matrix_2) {
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &B);
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

// ошибка: отличающиеся размеры
START_TEST(s21_eq_matrix_3) {
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(1, 4, &A);
  s21_create_matrix(5, 4, &B);
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

// матрицы, заполненные одним числом
START_TEST(s21_eq_matrix_4) {
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  fill_matrix(&A, 14.0);
  fill_matrix(&B, 14.0);
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

// матрицы, заполненные разными числами
START_TEST(s21_eq_matrix_5) {
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  fill_matrix(&A, -3.0);
  fill_matrix(&B, 14.0);
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

// матрицы, заполненные разными числами с разницей в восьмом знаке после запятой
START_TEST(s21_eq_matrix_6) {
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  fill_matrix(&A, -1E-8);
  fill_matrix(&B, 0.0);
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

// матрицы, заполненные разными числами с разницей в седьмом знаке после запятой
START_TEST(s21_eq_matrix_7) {
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  fill_matrix(&A, 1E-7);
  fill_matrix(&B, 0.0);
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

// ошибка: одна из матриц не инициализированна
START_TEST(s21_eq_matrix_8) {
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(5, 5, &A);
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);
  s21_remove_matrix(&A);
}

// матрицы,которые совпадают по содержанию, но не по размеру
START_TEST(s21_eq_matrix_9) {
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 4, &B);
  fill_matrix(&A, 3);
  fill_matrix(&B, 3);
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

// последний элемент матрицы отличается в седьмом знаке
START_TEST(s21_eq_matrix_10) {
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  fill_matrix(&A, 3);
  fill_matrix(&B, 3);
  B.matrix[2][2] = 3.0000001;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

// последний элемент матрицы отличается в восьмом знаке
START_TEST(s21_eq_matrix_11) {
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  fill_matrix(&A, 3);
  fill_matrix(&B, 3);
  B.matrix[2][2] = 3.00000001;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

Suite *suite_eq_matrix(void) {
  Suite *suite = suite_create(MAGENTA "[s21_eq_matrix]" RESET);
  TCase *tcase_core = tcase_create(RED "s21_eq_matrix_tc" RESET);

  if (suite != NULL && tcase_core != NULL) {
    tcase_add_test(tcase_core, s21_eq_matrix_1);
    tcase_add_test(tcase_core, s21_eq_matrix_2);
    tcase_add_test(tcase_core, s21_eq_matrix_3);
    tcase_add_test(tcase_core, s21_eq_matrix_4);
    tcase_add_test(tcase_core, s21_eq_matrix_5);
    tcase_add_test(tcase_core, s21_eq_matrix_6);
    tcase_add_test(tcase_core, s21_eq_matrix_7);
    tcase_add_test(tcase_core, s21_eq_matrix_8);
    tcase_add_test(tcase_core, s21_eq_matrix_9);
    tcase_add_test(tcase_core, s21_eq_matrix_10);
    tcase_add_test(tcase_core, s21_eq_matrix_11);
    suite_add_tcase(suite, tcase_core);
  }
  return suite;
}
