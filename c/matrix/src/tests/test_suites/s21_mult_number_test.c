#include "../s21_matrix_test.h"

// ошибка: некорректная матрица
START_TEST(s21_mult_number_1) {
  matrix_t A = {};
  int status = s21_mult_number(&A, 10, NULL);
  ck_assert_int_eq(status, INCORRECT_MATRIX);
}

// умножение зануленной матрицы на число
START_TEST(s21_mult_number_2) {
  matrix_t A = {};
  matrix_t C = {};
  matrix_t correct_matrix = {};

  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &correct_matrix);

  int status = s21_mult_number(&A, 5.0, &C);
  ck_assert_int_eq(status, OK);

  int result = s21_eq_matrix(&C, &correct_matrix);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&correct_matrix);
}

// умножение матрицы, заполненной одинаковыми положительными числами, на
// положительное число
START_TEST(s21_mult_number_3) {
  matrix_t A = {};
  matrix_t C = {};
  matrix_t correct_matrix = {};

  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &correct_matrix);

  fill_matrix(&A, 3.11);
  fill_matrix(&correct_matrix, 15.55);

  int status = s21_mult_number(&A, 5.0, &C);
  ck_assert_int_eq(status, OK);

  int result = s21_eq_matrix(&C, &correct_matrix);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&correct_matrix);
}

// умнжение матрицы, заполненной одинаковыми положительными числами, на
// отрицательное число
START_TEST(s21_mult_number_4) {
  matrix_t A = {};
  matrix_t C = {};
  matrix_t correct_matrix = {};

  s21_create_matrix(50, 50, &A);
  s21_create_matrix(50, 50, &correct_matrix);

  fill_matrix(&A, 5.0);
  fill_matrix(&correct_matrix, -0.01);

  int status = s21_mult_number(&A, -0.002, &C);
  ck_assert_int_eq(status, OK);

  int result = s21_eq_matrix(&C, &correct_matrix);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&correct_matrix);
}

// умножение матрицы, заполненной одинаковыми отрицательными числами, на
// отрицателььное число
START_TEST(s21_mult_number_5) {
  matrix_t A = {};
  matrix_t C = {};
  matrix_t correct_matrix = {};

  s21_create_matrix(50, 50, &A);
  s21_create_matrix(50, 50, &correct_matrix);

  fill_matrix(&A, -700.4);
  fill_matrix(&correct_matrix, 35020);

  int status = s21_mult_number(&A, -50.0, &C);
  ck_assert_int_eq(status, OK);

  int result = s21_eq_matrix(&C, &correct_matrix);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&correct_matrix);
}

// умножение матрицы, заполненной разными числами, на число (1)
START_TEST(s21_mult_number_6) {
  matrix_t A = {};
  matrix_t C = {};
  matrix_t correct_matrix = {};

  s21_create_matrix(3, 4, &A);
  s21_create_matrix(3, 4, &correct_matrix);

  A.matrix[0][0] = 3.2, A.matrix[0][1] = -440, A.matrix[0][2] = -0.0,
  A.matrix[0][3] = 5E20;
  A.matrix[1][0] = 140, A.matrix[1][1] = 8.2, A.matrix[1][2] = 0.0000001,
  A.matrix[1][3] = 24000;
  A.matrix[2][0] = 81, A.matrix[2][1] = 0.0, A.matrix[2][2] = 0.00000001,
  A.matrix[2][3] = 500000;

  correct_matrix.matrix[0][0] = 12.8, correct_matrix.matrix[0][1] = -1760,
  correct_matrix.matrix[0][2] = 0.0, correct_matrix.matrix[0][3] = 2E21;
  correct_matrix.matrix[1][0] = 560.0, correct_matrix.matrix[1][1] = 32.8,
  correct_matrix.matrix[1][2] = 0.0000004, correct_matrix.matrix[1][3] = 96000;
  correct_matrix.matrix[2][0] = 324.0, correct_matrix.matrix[2][1] = 0.0,
  correct_matrix.matrix[2][2] = 0.0, correct_matrix.matrix[2][3] = 2000000;

  int status = s21_mult_number(&A, 4.0, &C);
  ck_assert_int_eq(status, OK);

  int result = s21_eq_matrix(&C, &correct_matrix);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&correct_matrix);
}

// умножение матрицы, заполненной разными числами, на число (1)
START_TEST(s21_mult_number_7) {
  matrix_t A = {};
  matrix_t C = {};
  matrix_t correct_matrix = {};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &correct_matrix);

  A.matrix[0][0] = 0.000000001, A.matrix[0][1] = 0.0000001;
  A.matrix[1][0] = 5E20, A.matrix[1][1] = -0.0000001;

  correct_matrix.matrix[0][0] = 0.0, correct_matrix.matrix[0][1] = 0.0;
  correct_matrix.matrix[1][0] = -5E19, correct_matrix.matrix[1][1] = 0.0;

  int status = s21_mult_number(&A, -0.1, &C);
  ck_assert_int_eq(status, OK);

  int result = s21_eq_matrix(&C, &correct_matrix);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&correct_matrix);
}

// ошибка: бесконечное значение
START_TEST(s21_mult_number_8) {
  matrix_t A = {};
  matrix_t C = {};
  matrix_t correct_matrix = {};

  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &correct_matrix);

  A.matrix[3][1] = INFINITY;

  int status = s21_mult_number(&A, 5.2, &C);
  ck_assert_int_eq(status, CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&correct_matrix);
}

// ошибка: Nan
START_TEST(s21_mult_number_9) {
  matrix_t A = {};
  matrix_t C = {};
  matrix_t correct_matrix = {};

  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &correct_matrix);

  A.matrix[3][1] = NAN;

  int status = s21_mult_number(&A, 5.2, &C);
  ck_assert_int_eq(status, CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&correct_matrix);
}

// ошибка: бесконечный множитель
START_TEST(s21_mult_number_10) {
  matrix_t A = {};
  matrix_t C = {};
  matrix_t correct_matrix = {};

  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &correct_matrix);

  fill_matrix(&A, 1.0);

  int status = s21_mult_number(&A, INFINITY, &C);
  ck_assert_int_eq(status, CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&correct_matrix);
}

Suite *suite_mult_number(void) {
  Suite *suite = suite_create(MAGENTA "[s21_mult_number]" RESET);
  TCase *tcase_core = tcase_create(RED "s21_mult_number_tc" RESET);

  if (suite != NULL && tcase_core != NULL) {
    tcase_add_test(tcase_core, s21_mult_number_1);
    tcase_add_test(tcase_core, s21_mult_number_2);
    tcase_add_test(tcase_core, s21_mult_number_3);
    tcase_add_test(tcase_core, s21_mult_number_4);
    tcase_add_test(tcase_core, s21_mult_number_5);
    tcase_add_test(tcase_core, s21_mult_number_6);
    tcase_add_test(tcase_core, s21_mult_number_7);
    tcase_add_test(tcase_core, s21_mult_number_8);
    tcase_add_test(tcase_core, s21_mult_number_9);
    tcase_add_test(tcase_core, s21_mult_number_10);
    suite_add_tcase(suite, tcase_core);
  }
  return suite;
}