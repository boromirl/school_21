#include "../s21_tetris_test.h"

static int **create_dynamic_array(int rows, int cols) {
  int **array = malloc((rows * sizeof(int *)) + (rows * cols * sizeof(int)));
  int *ptr = (int *)(array + rows);
  for (int i = 0; i < rows; i++) {
    array[i] = ptr + cols * i;
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      array[i][j] = 0;
    }
  }

  return array;
}

static void fill_from_static(int s_arr[22][10], int **d_arr, int rows,
                             int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      d_arr[i][j] = s_arr[i][j];
    }
  }
}

static int field_1[22][10] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

static int field_2[22][10] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

static int field_3[22][10] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 0, 0, 1, 1, 1}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

START_TEST(checks_is_in_field_right_1) {
  int y = 0;
  int x = 0;

  bool res = is_in_field(y, x);
  ck_assert_int_eq(res, true);
}
END_TEST

START_TEST(checks_is_in_field_right_2) {
  int y = 21;
  int x = 5;

  bool res = is_in_field(y, x);
  ck_assert_int_eq(res, true);
}
END_TEST

START_TEST(checks_is_in_field_wrong_1) {
  int y = 40;
  int x = 5;

  bool res = is_in_field(y, x);
  ck_assert_int_eq(res, false);
}
END_TEST

START_TEST(checks_is_in_field_wrong_2) {
  int y = 20;
  int x = 10;

  bool res = is_in_field(y, x);
  ck_assert_int_eq(res, false);
}
END_TEST

START_TEST(checks_is_visible_right_1) {
  int y = 2;
  int x = 0;

  bool res = is_visible(y, x);
  ck_assert_int_eq(res, true);
}
END_TEST

START_TEST(checks_is_visible_right_2) {
  int y = 19;
  int x = 9;

  bool res = is_visible(y, x);
  ck_assert_int_eq(res, true);
}
END_TEST

START_TEST(checks_is_visible_wrong_1) {
  int y = -1;
  int x = 0;

  bool res = is_visible(y, x);
  ck_assert_int_eq(res, false);
}
END_TEST

START_TEST(checks_is_visible_wrong_2) {
  int y = 0;
  int x = 5;

  bool res = is_visible(y, x);
  ck_assert_int_eq(res, false);
}
END_TEST

// один из блоков фигуры на последней линии
START_TEST(checks_is_touching_right_1) {
  Figure_t figure = {1, 0, {{21, 0}, {0, 0}, {0, 0}, {0, 0}}, {0, 0}, 1};
  int **field = create_dynamic_array(FIELD_ROWS, FIELD_COLUMNS);
  fill_from_static(field_1, field, FIELD_ROWS, FIELD_COLUMNS);

  bool res = is_touching(figure, field);
  ck_assert_int_eq(res, true);

  free(field);
}
END_TEST

// один из блоков на одну линию выше заполненной строки
START_TEST(checks_is_touching_right_2) {
  Figure_t figure = {1, 0, {{10, 0}, {0, 0}, {0, 0}, {0, 0}}, {0, 0}, 1};
  int **field = create_dynamic_array(FIELD_ROWS, FIELD_COLUMNS);
  fill_from_static(field_1, field, FIELD_ROWS, FIELD_COLUMNS);

  bool res = is_touching(figure, field);
  ck_assert_int_eq(res, true);

  free(field);
}
END_TEST

START_TEST(checks_is_touching_wrong_1) {
  Figure_t figure = {1, 0, {{0, 0}, {0, 0}, {0, 0}, {0, 0}}, {0, 0}, 1};
  int **field = create_dynamic_array(FIELD_ROWS, FIELD_COLUMNS);
  fill_from_static(field_1, field, FIELD_ROWS, FIELD_COLUMNS);

  bool res = is_touching(figure, field);
  ck_assert_int_eq(res, false);

  free(field);
}
END_TEST

START_TEST(checks_is_touching_wrong_2) {
  Figure_t figure = {1, 0, {{20, 9}, {20, 8}, {19, 9}, {19, 8}}, {0, 0}, 1};
  int **field = create_dynamic_array(FIELD_ROWS, FIELD_COLUMNS);
  fill_from_static(field_1, field, FIELD_ROWS, FIELD_COLUMNS);

  bool res = is_touching(figure, field);
  ck_assert_int_eq(res, false);

  free(field);
}
END_TEST

START_TEST(checks_are_complete_rows_wrong_1) {
  int **field = create_dynamic_array(FIELD_ROWS, FIELD_COLUMNS);

  bool res = are_complete_rows(field);
  ck_assert_int_eq(res, false);

  free(field);
}
END_TEST

START_TEST(checks_are_complete_rows_wrong_2) {
  int **field = create_dynamic_array(FIELD_ROWS, FIELD_COLUMNS);
  fill_from_static(field_3, field, FIELD_ROWS, FIELD_COLUMNS);

  bool res = are_complete_rows(field);
  ck_assert_int_eq(res, false);

  free(field);
}
END_TEST

START_TEST(checks_are_complete_rows_right_1) {
  int **field = create_dynamic_array(FIELD_ROWS, FIELD_COLUMNS);
  fill_from_static(field_1, field, FIELD_ROWS, FIELD_COLUMNS);

  bool res = are_complete_rows(field);
  ck_assert_int_eq(res, true);

  free(field);
}
END_TEST

START_TEST(checks_are_complete_rows_right_2) {
  int **field = create_dynamic_array(FIELD_ROWS, FIELD_COLUMNS);
  fill_from_static(field_2, field, FIELD_ROWS, FIELD_COLUMNS);

  bool res = are_complete_rows(field);
  ck_assert_int_eq(res, true);

  free(field);
}
END_TEST

START_TEST(checks_is_row_complete_right_1) {
  int **field = create_dynamic_array(FIELD_ROWS, FIELD_COLUMNS);
  fill_from_static(field_1, field, FIELD_ROWS, FIELD_COLUMNS);

  bool res = is_row_complete(field, 11);
  ck_assert_int_eq(res, true);

  free(field);
}
END_TEST

START_TEST(checks_is_row_complete_right_2) {
  int **field = create_dynamic_array(FIELD_ROWS, FIELD_COLUMNS);
  fill_from_static(field_2, field, FIELD_ROWS, FIELD_COLUMNS);

  bool res = is_row_complete(field, 14);
  ck_assert_int_eq(res, true);

  free(field);
}
END_TEST

START_TEST(checks_is_row_complete_wrong_1) {
  int **field = create_dynamic_array(FIELD_ROWS, FIELD_COLUMNS);
  fill_from_static(field_3, field, FIELD_ROWS, FIELD_COLUMNS);

  bool res = is_row_complete(field, 6);
  ck_assert_int_eq(res, false);

  free(field);
}
END_TEST

START_TEST(checks_is_row_complete_wrong_2) {
  int **field = create_dynamic_array(FIELD_ROWS, FIELD_COLUMNS);
  fill_from_static(field_3, field, FIELD_ROWS, FIELD_COLUMNS);

  bool res = is_row_complete(field, 14);
  ck_assert_int_eq(res, false);

  free(field);
}
END_TEST

START_TEST(checks_is_collision_right_1) {
  Figure_t figure = {1, 0, {{10, 10}, {0, 0}, {0, 0}, {0, 0}}, {0, 0}, 1};
  int **field = create_dynamic_array(FIELD_ROWS, FIELD_COLUMNS);
  fill_from_static(field_1, field, FIELD_ROWS, FIELD_COLUMNS);

  bool res = is_collision(figure, field);
  ck_assert_int_eq(res, true);

  free(field);
}
END_TEST

START_TEST(checks_is_collision_right_2) {
  Figure_t figure = {1, 0, {{6, 5}, {0, 0}, {0, 0}, {0, 0}}, {0, 0}, 1};
  int **field = create_dynamic_array(FIELD_ROWS, FIELD_COLUMNS);
  fill_from_static(field_3, field, FIELD_ROWS, FIELD_COLUMNS);

  bool res = is_collision(figure, field);
  ck_assert_int_eq(res, true);

  free(field);
}
END_TEST

START_TEST(checks_is_collision_wrong_1) {
  Figure_t figure = {1, 0, {{21, 9}, {21, 0}, {0, 0}, {0, 9}}, {0, 0}, 1};
  int **field = create_dynamic_array(FIELD_ROWS, FIELD_COLUMNS);
  fill_from_static(field_1, field, FIELD_ROWS, FIELD_COLUMNS);

  bool res = is_collision(figure, field);
  ck_assert_int_eq(res, false);

  free(field);
}
END_TEST

START_TEST(checks_is_collision_wrong_2) {
  Figure_t figure = {1, 0, {{10, 1}, {10, 2}, {10, 3}, {10, 4}}, {0, 0}, 1};
  int **field = create_dynamic_array(FIELD_ROWS, FIELD_COLUMNS);
  fill_from_static(field_2, field, FIELD_ROWS, FIELD_COLUMNS);

  bool res = is_collision(figure, field);
  ck_assert_int_eq(res, false);

  free(field);
}
END_TEST

Suite *suite_boolean_checks(void) {
  Suite *suite = suite_create(MAGENTA "[boolean_checks]" RESET);
  TCase *tcase_core = tcase_create(RED "boolean_checks_tc" RESET);

  if (suite != NULL && tcase_core != NULL) {
    tcase_add_test(tcase_core, checks_is_in_field_right_1);
    tcase_add_test(tcase_core, checks_is_in_field_right_2);
    tcase_add_test(tcase_core, checks_is_in_field_wrong_1);
    tcase_add_test(tcase_core, checks_is_in_field_wrong_2);

    tcase_add_test(tcase_core, checks_is_visible_right_1);
    tcase_add_test(tcase_core, checks_is_visible_right_2);
    tcase_add_test(tcase_core, checks_is_visible_wrong_1);
    tcase_add_test(tcase_core, checks_is_visible_wrong_2);

    tcase_add_test(tcase_core, checks_is_touching_right_1);
    tcase_add_test(tcase_core, checks_is_touching_right_2);
    tcase_add_test(tcase_core, checks_is_touching_wrong_1);
    tcase_add_test(tcase_core, checks_is_touching_wrong_2);

    tcase_add_test(tcase_core, checks_are_complete_rows_wrong_1);
    tcase_add_test(tcase_core, checks_are_complete_rows_wrong_2);
    tcase_add_test(tcase_core, checks_are_complete_rows_right_1);
    tcase_add_test(tcase_core, checks_are_complete_rows_right_2);

    tcase_add_test(tcase_core, checks_is_row_complete_right_1);
    tcase_add_test(tcase_core, checks_is_row_complete_right_2);
    tcase_add_test(tcase_core, checks_is_row_complete_wrong_1);
    tcase_add_test(tcase_core, checks_is_row_complete_wrong_2);

    tcase_add_test(tcase_core, checks_is_collision_right_1);
    tcase_add_test(tcase_core, checks_is_collision_right_2);
    tcase_add_test(tcase_core, checks_is_collision_wrong_1);
    tcase_add_test(tcase_core, checks_is_collision_wrong_2);

    suite_add_tcase(suite, tcase_core);
  }
  return suite;
}
