#include "../s21_matrix_test.h"

// создание матрицы
START_TEST(s21_create_matrix_1) {
  matrix_t matr;
  int result = s21_create_matrix(4, 4, &matr);
  ck_assert_int_eq(result, OK);
  s21_remove_matrix(&matr);
}

// создание NULL матрицы
START_TEST(s21_create_matrix_2) {
  int result = s21_create_matrix(4, 4, NULL);
  ck_assert_int_eq(result, INCORRECT_MATRIX);
}

// недопустимое количество строк
START_TEST(s21_create_matrix_3) {
  matrix_t matr;
  int result = s21_create_matrix(0, 4, &matr);
  ck_assert_int_eq(result, INCORRECT_MATRIX);
}

// недопустимое количество столбцов
START_TEST(s21_create_matrix_4) {
  matrix_t matr;
  int result = s21_create_matrix(4, 0, &matr);
  ck_assert_int_eq(result, INCORRECT_MATRIX);
}

// неверное количество строк и столбцов
START_TEST(s21_create_matrix_5) {
  matrix_t matr;
  int result = s21_create_matrix(0, 0, &matr);
  ck_assert_int_eq(result, INCORRECT_MATRIX);
}

Suite *suite_create_matrix(void) {
  Suite *suite = suite_create(MAGENTA "[s21_create_matrix]" RESET);
  TCase *tcase_core = tcase_create(RED "s21_create_matrix_tc" RESET);

  if (suite != NULL && tcase_core != NULL) {
    tcase_add_test(tcase_core, s21_create_matrix_1);
    tcase_add_test(tcase_core, s21_create_matrix_2);
    tcase_add_test(tcase_core, s21_create_matrix_3);
    tcase_add_test(tcase_core, s21_create_matrix_4);
    tcase_add_test(tcase_core, s21_create_matrix_5);
    suite_add_tcase(suite, tcase_core);
  }
  return suite;
}
