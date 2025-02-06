#include "../s21_matrix_test.h"

// успешное удаление матрицы
START_TEST(s21_remove_matrix_1) {
  matrix_t matr;
  s21_create_matrix(4, 4, &matr);
  s21_remove_matrix(&matr);
  ck_assert_ptr_null(matr.matrix);
}

// обработка NULL указателя (проверка только на наличие ошибки)
START_TEST(s21_remove_matrix_2) {
  s21_remove_matrix(NULL);
  ck_assert_int_eq(1, 1);
}

// обработка неинициализированной матрицы (проверка только на наличие ошибки)
START_TEST(s21_remove_matrix_3) {
  matrix_t matr = {};
  s21_remove_matrix(&matr);
  ck_assert_int_eq(1, 1);
}

Suite *suite_remove_matrix(void) {
  Suite *suite = suite_create(MAGENTA "[s21_remove_matrix]" RESET);
  TCase *tcase_core = tcase_create(RED "s21_remove_matrix_tc" RESET);

  if (suite != NULL && tcase_core != NULL) {
    tcase_add_test(tcase_core, s21_remove_matrix_1);
    tcase_add_test(tcase_core, s21_remove_matrix_2);
    tcase_add_test(tcase_core, s21_remove_matrix_3);
    suite_add_tcase(suite, tcase_core);
  }
  return suite;
}
