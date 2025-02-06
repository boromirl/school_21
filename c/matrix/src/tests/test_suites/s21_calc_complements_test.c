#include "../s21_matrix_test.h"

// ошибка: некорректная матрица
START_TEST(s21_calc_complements_1) {
  matrix_t A = {};
  int status = s21_calc_complements(&A, NULL);
  ck_assert_int_eq(status, INCORRECT_MATRIX);
}

// ошибка: неквадратная матрица
START_TEST(s21_calc_complements_2) {
  matrix_t A = {};
  matrix_t C = {};
  s21_create_matrix(2, 5, &A);
  int status = s21_calc_complements(&A, &C);
  ck_assert_int_eq(status, CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}

// алгебраическое дополнение матрицы 1x1 равно 1
START_TEST(s21_calc_complements_3) {
  matrix_t A = {};
  matrix_t C = {};
  matrix_t correct_matrix = {};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &correct_matrix);

  correct_matrix.matrix[0][0] = 1;

  int status = s21_calc_complements(&A, &C);
  ck_assert_int_eq(status, OK);
  int result = s21_eq_matrix(&C, &correct_matrix);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&correct_matrix);
}

// матрица 2x2
START_TEST(s21_calc_complements_4) {
  matrix_t A = {};
  matrix_t C = {};
  matrix_t correct_matrix = {};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &correct_matrix);

  A.matrix[0][0] = 4.1, A.matrix[0][1] = 7;
  A.matrix[1][0] = 2.2, A.matrix[1][1] = -3;

  correct_matrix.matrix[0][0] = -3, correct_matrix.matrix[0][1] = -2.2;
  correct_matrix.matrix[1][0] = -7, correct_matrix.matrix[1][1] = 4.1;

  int status = s21_calc_complements(&A, &C);
  ck_assert_int_eq(status, OK);
  int result = s21_eq_matrix(&C, &correct_matrix);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&correct_matrix);
}

// матрица 3x3
START_TEST(s21_calc_complements_5) {
  matrix_t A = {};
  matrix_t C = {};
  matrix_t correct_matrix = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &correct_matrix);

  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 4, A.matrix[1][2] = 2;
  A.matrix[2][0] = 5, A.matrix[2][1] = 2, A.matrix[2][2] = 1;

  correct_matrix.matrix[0][0] = 0, correct_matrix.matrix[0][1] = 10,
  correct_matrix.matrix[0][2] = -20;
  correct_matrix.matrix[1][0] = 4, correct_matrix.matrix[1][1] = -14,
  correct_matrix.matrix[1][2] = 8;
  correct_matrix.matrix[2][0] = -8, correct_matrix.matrix[2][1] = -2,
  correct_matrix.matrix[2][2] = 4;

  int status = s21_calc_complements(&A, &C);
  ck_assert_int_eq(status, OK);
  int result = s21_eq_matrix(&C, &correct_matrix);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&correct_matrix);
}

// матрица 5x5
START_TEST(s21_calc_complements_6) {
  matrix_t A = {};
  matrix_t C = {};
  matrix_t correct_matrix = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &correct_matrix);

  A.matrix[0][0] = 4, A.matrix[0][1] = 7, A.matrix[0][2] = 2,
  A.matrix[0][3] = -4, A.matrix[0][4] = 3;
  A.matrix[1][0] = 2, A.matrix[1][1] = -3, A.matrix[1][2] = 5,
  A.matrix[1][3] = 12, A.matrix[1][4] = 0;
  A.matrix[2][0] = 34, A.matrix[2][1] = -22, A.matrix[2][2] = -22,
  A.matrix[2][3] = 3, A.matrix[2][4] = 17;
  A.matrix[3][0] = 1, A.matrix[3][1] = 5, A.matrix[3][2] = 7,
  A.matrix[3][3] = 14, A.matrix[3][4] = 3;
  A.matrix[4][0] = 1, A.matrix[4][1] = 2, A.matrix[4][2] = 12,
  A.matrix[4][3] = 77, A.matrix[4][4] = 13;

  correct_matrix.matrix[0][0] = -46070, correct_matrix.matrix[0][1] = -43665,
  correct_matrix.matrix[0][2] = 38165, correct_matrix.matrix[0][3] = -19140,
  correct_matrix.matrix[0][4] = 88400;
  correct_matrix.matrix[1][0] = -33630, correct_matrix.matrix[1][1] = -20615,
  correct_matrix.matrix[1][2] = 16990, correct_matrix.matrix[1][3] = -12615,
  correct_matrix.matrix[1][4] = 64795;
  correct_matrix.matrix[2][0] = 3665, correct_matrix.matrix[2][1] = 4885,
  correct_matrix.matrix[2][2] = -3911, correct_matrix.matrix[2][3] = 2240,
  correct_matrix.matrix[2][4] = -10691;
  correct_matrix.matrix[3][0] = 64020, correct_matrix.matrix[3][1] = 59945,
  correct_matrix.matrix[3][2] = -64965, correct_matrix.matrix[3][3] = 31385,
  correct_matrix.matrix[3][4] = -140075;
  correct_matrix.matrix[4][0] = -8935, correct_matrix.matrix[4][1] = -10145,
  correct_matrix.matrix[4][2] = 11299, correct_matrix.matrix[4][3] = -5755,
  correct_matrix.matrix[4][4] = 20379;

  int status = s21_calc_complements(&A, &C);
  ck_assert_int_eq(status, OK);
  int result = s21_eq_matrix(&C, &correct_matrix);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&correct_matrix);
}

Suite *suite_calc_complements(void) {
  Suite *suite = suite_create(MAGENTA "[s21_calc_complements]" RESET);
  TCase *tcase_core = tcase_create(RED "s21_calc_complements_tc" RESET);

  if (suite != NULL && tcase_core != NULL) {
    tcase_add_test(tcase_core, s21_calc_complements_1);
    tcase_add_test(tcase_core, s21_calc_complements_2);
    tcase_add_test(tcase_core, s21_calc_complements_3);
    tcase_add_test(tcase_core, s21_calc_complements_4);
    tcase_add_test(tcase_core, s21_calc_complements_5);
    tcase_add_test(tcase_core, s21_calc_complements_6);
    suite_add_tcase(suite, tcase_core);
  }
  return suite;
}