#include "../s21_matrix_test.h"

// ошибка: некорректная матрица
START_TEST(s21_transpose_1) {
  matrix_t A = {};
  int status = s21_transpose(&A, NULL);
  ck_assert_int_eq(status, INCORRECT_MATRIX);
}

// транспонирование матрицы нулей
START_TEST(s21_transpose_2) {
  matrix_t A = {};
  matrix_t T = {};
  matrix_t correct_matrix = {};

  s21_create_matrix(3, 4, &A);
  s21_create_matrix(4, 3, &correct_matrix);

  int status = s21_transpose(&A, &T);
  ck_assert_int_eq(status, OK);

  int result = s21_eq_matrix(&T, &correct_matrix);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&T);
  s21_remove_matrix(&correct_matrix);
}

// транспонирование заполненной матрицы
START_TEST(s21_transpose_3) {
  matrix_t A = {};
  matrix_t T = {};
  matrix_t correct_matrix = {};

  s21_create_matrix(100, 43, &A);
  s21_create_matrix(43, 100, &correct_matrix);

  fill_matrix(&A, 4.5);
  fill_matrix(&correct_matrix, 4.5);

  int status = s21_transpose(&A, &T);
  ck_assert_int_eq(status, OK);

  int result = s21_eq_matrix(&T, &correct_matrix);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&T);
  s21_remove_matrix(&correct_matrix);
}

// транспонирование матрицы, заполненной разными числами (1)
START_TEST(s21_transpose_4) {
  matrix_t A = {};
  matrix_t T = {};
  matrix_t correct_matrix = {};

  s21_create_matrix(4, 2, &A);
  s21_create_matrix(2, 4, &correct_matrix);

  A.matrix[0][0] = 3.1, A.matrix[0][1] = -723.3;
  A.matrix[1][0] = 14.2, A.matrix[1][1] = 1E-8;
  A.matrix[2][0] = 5.3, A.matrix[2][1] = 0.0;
  A.matrix[3][0] = -2.1, A.matrix[3][1] = 3.4E13;

  correct_matrix.matrix[0][0] = 3.1, correct_matrix.matrix[0][1] = 14.2,
  correct_matrix.matrix[0][2] = 5.3, correct_matrix.matrix[0][3] = -2.1;
  correct_matrix.matrix[1][0] = -723.3, correct_matrix.matrix[1][1] = 0,
  correct_matrix.matrix[1][2] = 0, correct_matrix.matrix[1][3] = 3.4E13;

  int status = s21_transpose(&A, &T);
  ck_assert_int_eq(status, OK);

  int result = s21_eq_matrix(&T, &correct_matrix);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&T);
  s21_remove_matrix(&correct_matrix);
}

// транспонирование матрицы, заполненной разными числами (2)
START_TEST(s21_transpose_5) {
  matrix_t A = {};
  matrix_t T = {};
  matrix_t correct_matrix = {};

  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &correct_matrix);

  A.matrix[0][0] = 1, A.matrix[0][1] = 4;
  A.matrix[1][0] = 2, A.matrix[1][1] = 5;
  A.matrix[2][0] = 3, A.matrix[2][1] = 6;

  correct_matrix.matrix[0][0] = 1, correct_matrix.matrix[0][1] = 2,
  correct_matrix.matrix[0][2] = 3;
  correct_matrix.matrix[1][0] = 4, correct_matrix.matrix[1][1] = 5,
  correct_matrix.matrix[1][2] = 6;

  int status = s21_transpose(&A, &T);
  ck_assert_int_eq(status, OK);

  int result = s21_eq_matrix(&T, &correct_matrix);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&T);
  s21_remove_matrix(&correct_matrix);
}

Suite *suite_transpose(void) {
  Suite *suite = suite_create(MAGENTA "[s21_transpose]" RESET);
  TCase *tcase_core = tcase_create(RED "s21_transpose_tc" RESET);

  if (suite != NULL && tcase_core != NULL) {
    tcase_add_test(tcase_core, s21_transpose_1);
    tcase_add_test(tcase_core, s21_transpose_2);
    tcase_add_test(tcase_core, s21_transpose_3);
    tcase_add_test(tcase_core, s21_transpose_4);
    tcase_add_test(tcase_core, s21_transpose_5);
    suite_add_tcase(suite, tcase_core);
  }
  return suite;
}