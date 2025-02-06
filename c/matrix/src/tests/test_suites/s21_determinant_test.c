#include "../s21_matrix_test.h"

// ошибка: некорректная матрица
START_TEST(s21_determinant_1) {
  double determinant = 0.0;
  int status = s21_determinant(NULL, &determinant);
  ck_assert_int_eq(status, INCORRECT_MATRIX);
}

// ошибка: некорректная переменная результата
START_TEST(s21_determinant_2) {
  matrix_t A = {};
  s21_create_matrix(2, 2, &A);
  int status = s21_determinant(&A, NULL);
  ck_assert_int_eq(status, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}

// ошибка: неквадратная матрица
START_TEST(s21_determinant_3) {
  matrix_t A = {};
  s21_create_matrix(2, 5, &A);
  double determinant = 0.0;
  int status = s21_determinant(&A, &determinant);
  ck_assert_int_eq(status, CALCULATION_ERROR);
  s21_remove_matrix(&A);
}

// определитель матрицы нулей == 0
START_TEST(s21_determinant_4) {
  matrix_t A = {};
  s21_create_matrix(5, 5, &A);
  fill_matrix(&A, 0.0);
  double determinant = 0.0;
  int status = s21_determinant(&A, &determinant);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq(determinant, 0.0);
  s21_remove_matrix(&A);
}

// определитель матрицы, заполненной одинаковыми элементами == 0 (исключение
// матрица 1x1)
START_TEST(s21_determinant_5) {
  matrix_t A = {};
  s21_create_matrix(5, 5, &A);
  fill_matrix(&A, -4.23);
  double determinant = 0.0;
  int status = s21_determinant(&A, &determinant);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq(determinant, 0.0);
  s21_remove_matrix(&A);
}

// матрица 1x1
START_TEST(s21_determinant_6) {
  matrix_t A = {};
  s21_create_matrix(1, 1, &A);
  fill_matrix(&A, -4.23);
  double determinant = 0.0;
  int status = s21_determinant(&A, &determinant);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq(determinant, -4.23);
  s21_remove_matrix(&A);
}

// матрица 2x2
START_TEST(s21_determinant_7) {
  matrix_t A = {};
  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 4.1, A.matrix[0][1] = 7;
  A.matrix[1][0] = 2.2, A.matrix[1][1] = -3;

  double determinant = 0.0;
  int status = s21_determinant(&A, &determinant);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq(determinant, -27.7);
  s21_remove_matrix(&A);
}

// матрица 3x3 (1)
START_TEST(s21_determinant_8) {
  matrix_t A = {};
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 1, A.matrix[1][2] = 4;
  A.matrix[2][0] = 5, A.matrix[2][1] = 6, A.matrix[2][2] = 0;

  double determinant = 0.0;
  int status = s21_determinant(&A, &determinant);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq(determinant, 1.0);
  s21_remove_matrix(&A);
}

// матрица 3x3 (2)
START_TEST(s21_determinant_9) {
  matrix_t A = {};
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 4, A.matrix[0][1] = -3, A.matrix[0][2] = 2;
  A.matrix[1][0] = 1, A.matrix[1][1] = 0, A.matrix[1][2] = -1;
  A.matrix[2][0] = -2, A.matrix[2][1] = 5, A.matrix[2][2] = 3;

  double determinant = 0.0;
  int status = s21_determinant(&A, &determinant);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq(determinant, 33.0);
  s21_remove_matrix(&A);
}

// матрица 5x5 (1)
START_TEST(s21_determinant_10) {
  matrix_t A = {};
  s21_create_matrix(5, 5, &A);

  A.matrix[0][0] = 3, A.matrix[0][1] = -1, A.matrix[0][2] = 2,
  A.matrix[0][3] = 5, A.matrix[0][4] = 7;
  A.matrix[1][0] = 0, A.matrix[1][1] = 6, A.matrix[1][2] = 4,
  A.matrix[1][3] = 1, A.matrix[1][4] = 2;
  A.matrix[2][0] = -1, A.matrix[2][1] = 3, A.matrix[2][2] = 5,
  A.matrix[2][3] = 4, A.matrix[2][4] = 6;
  A.matrix[3][0] = 2, A.matrix[3][1] = 0, A.matrix[3][2] = 1,
  A.matrix[3][3] = 3, A.matrix[3][4] = 1;
  A.matrix[4][0] = 1, A.matrix[4][1] = 2, A.matrix[4][2] = 3,
  A.matrix[4][3] = 0, A.matrix[4][4] = -1;

  double determinant = 0.0;
  int status = s21_determinant(&A, &determinant);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq(determinant, -756);
  s21_remove_matrix(&A);
}

Suite *suite_determinant(void) {
  Suite *suite = suite_create(MAGENTA "[s21_determinant]" RESET);
  TCase *tcase_core = tcase_create(RED "s21_determinant_tc" RESET);

  if (suite != NULL && tcase_core != NULL) {
    tcase_add_test(tcase_core, s21_determinant_1);
    tcase_add_test(tcase_core, s21_determinant_2);
    tcase_add_test(tcase_core, s21_determinant_3);
    tcase_add_test(tcase_core, s21_determinant_4);
    tcase_add_test(tcase_core, s21_determinant_5);
    tcase_add_test(tcase_core, s21_determinant_6);
    tcase_add_test(tcase_core, s21_determinant_7);
    tcase_add_test(tcase_core, s21_determinant_8);
    tcase_add_test(tcase_core, s21_determinant_9);
    tcase_add_test(tcase_core, s21_determinant_10);
    suite_add_tcase(suite, tcase_core);
  }
  return suite;
}