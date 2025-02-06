#include "../s21_matrix_test.h"

// ошибка: некорректная матрица
START_TEST(s21_sub_matrix_1) {
  matrix_t A = {};
  matrix_t B = {};
  int status = s21_sub_matrix(&A, &B, NULL);
  ck_assert_int_eq(status, INCORRECT_MATRIX);
}

// ошибка: не совпадают размеры матриц
START_TEST(s21_sub_matrix_2) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t C = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 1, &B);
  int status = s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(status, CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}

// вычитание зануленных матриц
START_TEST(s21_sub_matrix_3) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t C = {};
  matrix_t correct_matrix = {};

  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_create_matrix(5, 5, &correct_matrix);

  int status = s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(status, OK);

  int result = s21_eq_matrix(&C, &correct_matrix);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&correct_matrix);
}

// вычитание матриц, заполненных одинаковыми положительными числами
START_TEST(s21_sub_matrix_4) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t C = {};
  matrix_t correct_matrix = {};

  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_create_matrix(5, 5, &correct_matrix);

  fill_matrix(&A, 3.0);
  fill_matrix(&B, 7.0);
  fill_matrix(&correct_matrix, -4.0);

  int status = s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(status, OK);

  int result = s21_eq_matrix(&C, &correct_matrix);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&correct_matrix);
}

// вычитание матриц, заполненных одинаковыми отрицательными числами
START_TEST(s21_sub_matrix_5) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t C = {};
  matrix_t correct_matrix = {};

  s21_create_matrix(50, 50, &A);
  s21_create_matrix(50, 50, &B);
  s21_create_matrix(50, 50, &correct_matrix);

  fill_matrix(&A, -513.90003);
  fill_matrix(&B, -7.14005);
  fill_matrix(&correct_matrix, -506.75998);

  int status = s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(status, OK);

  int result = s21_eq_matrix(&C, &correct_matrix);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&correct_matrix);
}

// вычитание матриц, заполненных одинаковыми отрицательными/положительными
// числами
START_TEST(s21_sub_matrix_6) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t C = {};
  matrix_t correct_matrix = {};

  s21_create_matrix(50, 50, &A);
  s21_create_matrix(50, 50, &B);
  s21_create_matrix(50, 50, &correct_matrix);

  fill_matrix(&A, -3945.4);
  fill_matrix(&B, 100000);
  fill_matrix(&correct_matrix, -103945.4);

  int status = s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(status, OK);

  int result = s21_eq_matrix(&C, &correct_matrix);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&correct_matrix);
}

// вычитание матриц, заполненных разными числами 1
START_TEST(s21_sub_matrix_7) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t C = {};
  matrix_t correct_matrix = {};

  s21_create_matrix(3, 4, &A);
  s21_create_matrix(3, 4, &B);
  s21_create_matrix(3, 4, &correct_matrix);

  A.matrix[0][0] = -100.0, A.matrix[0][1] = -245.3, A.matrix[0][2] = 0.00001,
  A.matrix[0][3] = 54.32;
  A.matrix[1][0] = 0.3, A.matrix[1][1] = -0.0003, A.matrix[1][2] = 90,
  A.matrix[1][3] = 65.2;
  A.matrix[2][0] = 81, A.matrix[2][1] = 100, A.matrix[2][2] = -0.00001,
  A.matrix[2][3] = 500000;

  B.matrix[0][0] = 17, B.matrix[0][1] = 3, B.matrix[0][2] = -0.00001,
  B.matrix[0][3] = 4.2;
  B.matrix[1][0] = 140, B.matrix[1][1] = -0.0003, B.matrix[1][2] = 20.45,
  B.matrix[1][3] = 30.3;
  B.matrix[2][0] = -300.14, B.matrix[2][1] = 100, B.matrix[2][2] = 0.00001,
  B.matrix[2][3] = 1000000;

  correct_matrix.matrix[0][0] = -117, correct_matrix.matrix[0][1] = -248.3,
  correct_matrix.matrix[0][2] = 0.00002, correct_matrix.matrix[0][3] = 50.12;
  correct_matrix.matrix[1][0] = -139.7, correct_matrix.matrix[1][1] = 0.0,
  correct_matrix.matrix[1][2] = 69.55, correct_matrix.matrix[1][3] = 34.9;
  correct_matrix.matrix[2][0] = 381.14, correct_matrix.matrix[2][1] = 0.0,
  correct_matrix.matrix[2][2] = -0.00002, correct_matrix.matrix[2][3] = -500000;

  int status = s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(status, OK);

  int result = s21_eq_matrix(&C, &correct_matrix);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&correct_matrix);
}

// вычитание матриц, заполненных разными числами 2
START_TEST(s21_sub_matrix_8) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t C = {};
  matrix_t correct_matrix = {};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &correct_matrix);

  A.matrix[0][0] = 0.000000001, A.matrix[0][1] = 0.0000001;
  A.matrix[1][0] = 5E20, A.matrix[1][1] = 0.0000001;

  B.matrix[0][0] = -0.000000001, B.matrix[0][1] = -0.0000001;
  B.matrix[1][0] = 3E20, B.matrix[1][1] = 0.0000001;

  correct_matrix.matrix[0][0] = 0.0, correct_matrix.matrix[0][1] = 0.0000002;
  correct_matrix.matrix[1][0] = 2E20, correct_matrix.matrix[1][1] = 0.0;

  int status = s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(status, OK);

  int result = s21_eq_matrix(&C, &correct_matrix);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&correct_matrix);
}

// ошибка: бесконечное значение
START_TEST(s21_sub_matrix_9) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t C = {};
  matrix_t correct_matrix = {};

  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &B);
  s21_create_matrix(4, 4, &correct_matrix);

  A.matrix[3][1] = INFINITY;

  int status = s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(status, CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&correct_matrix);
}

// ошибка: Nan
START_TEST(s21_sub_matrix_10) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t C = {};
  matrix_t correct_matrix = {};

  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &B);
  s21_create_matrix(4, 4, &correct_matrix);

  A.matrix[3][1] = NAN;

  int status = s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(status, CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&correct_matrix);
}

Suite *suite_sub_matrix(void) {
  Suite *suite = suite_create(MAGENTA "[s21_sub_matrix]" RESET);
  TCase *tcase_core = tcase_create(RED "s21_sub_matrix_tc" RESET);

  if (suite != NULL && tcase_core != NULL) {
    tcase_add_test(tcase_core, s21_sub_matrix_1);
    tcase_add_test(tcase_core, s21_sub_matrix_2);
    tcase_add_test(tcase_core, s21_sub_matrix_3);
    tcase_add_test(tcase_core, s21_sub_matrix_4);
    tcase_add_test(tcase_core, s21_sub_matrix_5);
    tcase_add_test(tcase_core, s21_sub_matrix_6);
    tcase_add_test(tcase_core, s21_sub_matrix_7);
    tcase_add_test(tcase_core, s21_sub_matrix_8);
    tcase_add_test(tcase_core, s21_sub_matrix_9);
    tcase_add_test(tcase_core, s21_sub_matrix_10);
    suite_add_tcase(suite, tcase_core);
  }
  return suite;
}