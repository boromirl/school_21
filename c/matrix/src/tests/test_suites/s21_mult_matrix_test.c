#include "../s21_matrix_test.h"

// ошибка: некорректная матрица
START_TEST(s21_mult_matrix_1) {
  matrix_t A = {};
  matrix_t B = {};
  int status = s21_mult_matrix(&A, &B, NULL);
  ck_assert_int_eq(status, INCORRECT_MATRIX);
}

// ошибка: не подходят размеры матриц
START_TEST(s21_mult_matrix_2) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t C = {};
  s21_create_matrix(5, 10, &A);
  s21_create_matrix(5, 10, &B);
  int status = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(status, CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}

// умножение зануленных матриц
START_TEST(s21_mult_matrix_3) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t C = {};
  matrix_t correct_matrix = {};

  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_create_matrix(5, 5, &correct_matrix);

  int status = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(status, OK);

  int result = s21_eq_matrix(&C, &correct_matrix);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&correct_matrix);
}

// умножение матриц, заполненных одинаковыми положительными числами
START_TEST(s21_mult_matrix_4) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t C = {};
  matrix_t correct_matrix = {};

  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_create_matrix(5, 5, &correct_matrix);

  fill_matrix(&A, 3.0);
  fill_matrix(&B, 6.0);
  fill_matrix(&correct_matrix, 90.0);

  int status = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(status, OK);

  int result = s21_eq_matrix(&C, &correct_matrix);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&correct_matrix);
}

// умножение матриц, заполненных одинаковыми отрицательными числами
START_TEST(s21_mult_matrix_5) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t C = {};
  matrix_t correct_matrix = {};

  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 4, &B);
  s21_create_matrix(2, 4, &correct_matrix);

  fill_matrix(&A, -2.3);
  fill_matrix(&B, -15.22);
  fill_matrix(&correct_matrix, 105.018);

  int status = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(status, OK);

  int result = s21_eq_matrix(&C, &correct_matrix);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&correct_matrix);
}

// умножение матриц, заполненных одинаковыми отрицательными/положительными
// числами
START_TEST(s21_mult_matrix_6) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t C = {};
  matrix_t correct_matrix = {};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &correct_matrix);

  fill_matrix(&A, -3.2);
  fill_matrix(&B, 1);
  fill_matrix(&correct_matrix, -6.4);

  int status = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(status, OK);

  int result = s21_eq_matrix(&C, &correct_matrix);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&correct_matrix);
}

// умножение матриц, заполненных разными числами 1
START_TEST(s21_mult_matrix_7) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t C = {};
  matrix_t correct_matrix = {};

  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);
  s21_create_matrix(3, 3, &correct_matrix);

  A.matrix[0][0] = 1.0, A.matrix[0][1] = 4.0;
  A.matrix[1][0] = 2.0, A.matrix[1][1] = 5.0;
  A.matrix[2][0] = 3.0, A.matrix[2][1] = 6.0;

  B.matrix[0][0] = 1.0, B.matrix[0][1] = -1.0, B.matrix[0][2] = 1.0;
  B.matrix[1][0] = 2.0, B.matrix[1][1] = 3.0, B.matrix[1][2] = 4.0;

  correct_matrix.matrix[0][0] = 9.0, correct_matrix.matrix[0][1] = 11.0,
  correct_matrix.matrix[0][2] = 17.0;
  correct_matrix.matrix[1][0] = 12.0, correct_matrix.matrix[1][1] = 13.0,
  correct_matrix.matrix[1][2] = 22.0;
  correct_matrix.matrix[2][0] = 15.0, correct_matrix.matrix[2][1] = 15.0,
  correct_matrix.matrix[2][2] = 27.0;

  int status = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(status, OK);

  int result = s21_eq_matrix(&C, &correct_matrix);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&correct_matrix);
}

// умножение матриц, заполненных разными числами 2
START_TEST(s21_mult_matrix_8) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t C = {};
  matrix_t correct_matrix = {};

  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 4, &B);
  s21_create_matrix(2, 4, &correct_matrix);

  A.matrix[0][0] = 0.0001, A.matrix[0][1] = 100, A.matrix[0][2] = 5E20;
  A.matrix[1][0] = 5E-10, A.matrix[1][1] = 14, A.matrix[1][2] = 1;

  B.matrix[0][0] = 1, B.matrix[0][1] = 2, B.matrix[0][2] = 4,
  B.matrix[0][3] = 56;
  B.matrix[1][0] = 5E12, B.matrix[1][1] = -7.2, B.matrix[1][2] = 0.00001,
  B.matrix[1][3] = 800;
  B.matrix[2][0] = 4, B.matrix[2][1] = 6, B.matrix[2][2] = 5,
  B.matrix[2][3] = 20;

  correct_matrix.matrix[0][0] = 2000000500000000049152.0,
  correct_matrix.matrix[0][1] = 3E21, correct_matrix.matrix[0][2] = 25E20,
  correct_matrix.matrix[0][3] = 1E22;
  correct_matrix.matrix[1][0] = 70000000000004.0,
  correct_matrix.matrix[1][1] = -94.8, correct_matrix.matrix[1][2] = 5.00014,
  correct_matrix.matrix[1][3] = 11220;

  int status = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(status, OK);

  int result = s21_eq_matrix(&C, &correct_matrix);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&correct_matrix);
}

// ошибка: бесконечное значение
START_TEST(s21_mult_matrix_9) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t C = {};
  matrix_t correct_matrix = {};

  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &B);
  s21_create_matrix(4, 4, &correct_matrix);

  A.matrix[3][1] = INFINITY;

  int status = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(status, CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&correct_matrix);
}

// ошибка: Nan
START_TEST(s21_mult_matrix_10) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t C = {};
  matrix_t correct_matrix = {};

  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &B);
  s21_create_matrix(4, 4, &correct_matrix);

  A.matrix[3][1] = NAN;

  int status = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(status, CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&correct_matrix);
}

Suite *suite_mult_matrix(void) {
  Suite *suite = suite_create(MAGENTA "[s21_mult_matrix]" RESET);
  TCase *tcase_core = tcase_create(RED "s21_mult_matrix_tc" RESET);

  if (suite != NULL && tcase_core != NULL) {
    tcase_add_test(tcase_core, s21_mult_matrix_1);
    tcase_add_test(tcase_core, s21_mult_matrix_2);
    tcase_add_test(tcase_core, s21_mult_matrix_3);
    tcase_add_test(tcase_core, s21_mult_matrix_4);
    tcase_add_test(tcase_core, s21_mult_matrix_5);
    tcase_add_test(tcase_core, s21_mult_matrix_6);
    tcase_add_test(tcase_core, s21_mult_matrix_7);
    tcase_add_test(tcase_core, s21_mult_matrix_8);
    tcase_add_test(tcase_core, s21_mult_matrix_9);
    tcase_add_test(tcase_core, s21_mult_matrix_10);
    suite_add_tcase(suite, tcase_core);
  }
  return suite;
}