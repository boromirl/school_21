#include "../s21_matrix_test.h"

// ошибка: некорректная матрица
START_TEST(s21_inverse_matrix_1) {
  matrix_t A = {};
  int status = s21_inverse_matrix(&A, NULL);
  ck_assert_int_eq(status, INCORRECT_MATRIX);
}

// ошибка: неквадратная матрица
START_TEST(s21_inverse_matrix_2) {
  matrix_t A = {};
  matrix_t C = {};
  s21_create_matrix(2, 5, &A);
  int status = s21_inverse_matrix(&A, &C);
  ck_assert_int_eq(status, CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}

// обратная матрица 1x1
START_TEST(s21_inverse_matrix_3) {
  matrix_t A = {};
  matrix_t C = {};
  matrix_t correct_matrix = {};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &correct_matrix);

  A.matrix[0][0] = 5;
  correct_matrix.matrix[0][0] = 0.2;

  int status = s21_inverse_matrix(&A, &C);
  ck_assert_int_eq(status, OK);
  int result = s21_eq_matrix(&C, &correct_matrix);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&correct_matrix);
}

// матрица 2x2
START_TEST(s21_inverse_matrix_4) {
  matrix_t A = {};
  matrix_t C = {};
  matrix_t correct_matrix = {};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &correct_matrix);

  A.matrix[0][0] = -1, A.matrix[0][1] = 2;
  A.matrix[1][0] = 0, A.matrix[1][1] = 1;

  correct_matrix.matrix[0][0] = -1, correct_matrix.matrix[0][1] = 2;
  correct_matrix.matrix[1][0] = 0, correct_matrix.matrix[1][1] = 1;

  int status = s21_inverse_matrix(&A, &C);
  ck_assert_int_eq(status, OK);
  int result = s21_eq_matrix(&C, &correct_matrix);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&correct_matrix);
}

// матрица 3x3
START_TEST(s21_inverse_matrix_5) {
  matrix_t A = {};
  matrix_t C = {};
  matrix_t correct_matrix = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &correct_matrix);

  A.matrix[0][0] = 2, A.matrix[0][1] = 5, A.matrix[0][2] = 7;
  A.matrix[1][0] = 6, A.matrix[1][1] = 3, A.matrix[1][2] = 4;
  A.matrix[2][0] = 5, A.matrix[2][1] = -2, A.matrix[2][2] = -3;

  correct_matrix.matrix[0][0] = 1, correct_matrix.matrix[0][1] = -1,
  correct_matrix.matrix[0][2] = 1;
  correct_matrix.matrix[1][0] = -38, correct_matrix.matrix[1][1] = 41,
  correct_matrix.matrix[1][2] = -34;
  correct_matrix.matrix[2][0] = 27, correct_matrix.matrix[2][1] = -29,
  correct_matrix.matrix[2][2] = 24;

  int status = s21_inverse_matrix(&A, &C);
  ck_assert_int_eq(status, OK);
  int result = s21_eq_matrix(&C, &correct_matrix);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&correct_matrix);
}

// матрица 5x5
START_TEST(s21_inverse_matrix_6) {
  matrix_t A = {};
  matrix_t C = {};
  matrix_t correct_matrix = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &correct_matrix);

  A.matrix[0][0] = 0, A.matrix[0][1] = -1, A.matrix[0][2] = 0,
  A.matrix[0][3] = 0, A.matrix[0][4] = -1;
  A.matrix[1][0] = -1, A.matrix[1][1] = 0, A.matrix[1][2] = 0,
  A.matrix[1][3] = 0, A.matrix[1][4] = 1;
  A.matrix[2][0] = 0, A.matrix[2][1] = 0, A.matrix[2][2] = 1,
  A.matrix[2][3] = 0, A.matrix[2][4] = -1;
  A.matrix[3][0] = 0, A.matrix[3][1] = 0, A.matrix[3][2] = 0,
  A.matrix[3][3] = -1, A.matrix[3][4] = 0;
  A.matrix[4][0] = -1, A.matrix[4][1] = 1, A.matrix[4][2] = -1,
  A.matrix[4][3] = 0, A.matrix[4][4] = -1;

  correct_matrix.matrix[0][0] = -0.25, correct_matrix.matrix[0][1] = -0.75,
  correct_matrix.matrix[0][2] = -0.25, correct_matrix.matrix[0][3] = 0,
  correct_matrix.matrix[0][4] = -0.25;
  correct_matrix.matrix[1][0] = -0.75, correct_matrix.matrix[1][1] = -0.25,
  correct_matrix.matrix[1][2] = 0.25, correct_matrix.matrix[1][3] = 0,
  correct_matrix.matrix[1][4] = 0.25;
  correct_matrix.matrix[2][0] = -0.25, correct_matrix.matrix[2][1] = 0.25,
  correct_matrix.matrix[2][2] = 0.75, correct_matrix.matrix[2][3] = 0,
  correct_matrix.matrix[2][4] = -0.25;
  correct_matrix.matrix[3][0] = 0, correct_matrix.matrix[3][1] = 0,
  correct_matrix.matrix[3][2] = 0, correct_matrix.matrix[3][3] = -1,
  correct_matrix.matrix[3][4] = 0;
  correct_matrix.matrix[4][0] = -0.25, correct_matrix.matrix[4][1] = 0.25,
  correct_matrix.matrix[4][2] = -0.25, correct_matrix.matrix[4][3] = 0,
  correct_matrix.matrix[4][4] = -0.25;

  int status = s21_inverse_matrix(&A, &C);
  ck_assert_int_eq(status, OK);
  int result = s21_eq_matrix(&C, &correct_matrix);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&correct_matrix);
}

// ошибка: определитель равен нулю
START_TEST(s21_inverse_matrix_7) {
  matrix_t A = {};
  matrix_t C = {};
  s21_create_matrix(3, 3, &A);

  fill_matrix(&A, 5.2);

  int status = s21_inverse_matrix(&A, &C);
  ck_assert_int_eq(status, CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}

Suite *suite_inverse_matrix(void) {
  Suite *suite = suite_create(MAGENTA "[s21_inverse_matrix]" RESET);
  TCase *tcase_core = tcase_create(RED "s21_inverse_matrix_tc" RESET);

  if (suite != NULL && tcase_core != NULL) {
    tcase_add_test(tcase_core, s21_inverse_matrix_1);
    tcase_add_test(tcase_core, s21_inverse_matrix_2);
    tcase_add_test(tcase_core, s21_inverse_matrix_3);
    tcase_add_test(tcase_core, s21_inverse_matrix_4);
    tcase_add_test(tcase_core, s21_inverse_matrix_5);
    tcase_add_test(tcase_core, s21_inverse_matrix_6);
    tcase_add_test(tcase_core, s21_inverse_matrix_7);
    suite_add_tcase(suite, tcase_core);
  }
  return suite;
}