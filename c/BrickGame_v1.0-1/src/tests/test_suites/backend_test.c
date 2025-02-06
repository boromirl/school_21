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

START_TEST(backend_updateCurrentState_1) {
  tetris_init();
  userInput(Start, false);
  userInput(NoAction, false);
  userInput(Right, false);
  userInput(Pause, false);

  GameInfo_t info = updateCurrentState();
  ck_assert_int_eq(info.pause, true);

  userInput(Pause, false);
  info = updateCurrentState();
  ck_assert_int_eq(info.pause, false);

  userInput(Down, false);
  info = updateCurrentState();

  tetris_end();
}
END_TEST

START_TEST(backend_add_points_for_rows_1) {
  int score = 0;
  add_points_for_rows(1, &score);
  ck_assert_int_eq(score, 100);

  add_points_for_rows(2, &score);
  ck_assert_int_eq(score, 400);  // 100 + 300

  add_points_for_rows(3, &score);
  ck_assert_int_eq(score, 1100);  // 400 + 700

  add_points_for_rows(4, &score);
  ck_assert_int_eq(score, 2600);  // 1100 + 1500

  add_points_for_rows(7, &score);
  ck_assert_int_eq(score, 2600);
}
END_TEST

START_TEST(backend_set_speed_1) {
  int speed = 0;

  set_speed(0, &speed);
  ck_assert_int_eq(speed, INITIAL_SPEED);

  set_speed(1, &speed);
  ck_assert_int_eq(speed, SPEED_1);

  set_speed(2, &speed);
  ck_assert_int_eq(speed, SPEED_2);

  set_speed(3, &speed);
  ck_assert_int_eq(speed, SPEED_3);

  set_speed(4, &speed);
  ck_assert_int_eq(speed, SPEED_4);

  set_speed(5, &speed);
  ck_assert_int_eq(speed, SPEED_5);

  set_speed(6, &speed);
  ck_assert_int_eq(speed, SPEED_6);

  set_speed(7, &speed);
  ck_assert_int_eq(speed, SPEED_7);

  set_speed(8, &speed);
  ck_assert_int_eq(speed, SPEED_8);

  set_speed(9, &speed);
  ck_assert_int_eq(speed, SPEED_9);

  set_speed(10, &speed);
  ck_assert_int_eq(speed, SPEED_10);

  set_speed(11, &speed);
  ck_assert_int_eq(speed, SPEED_10);
}
END_TEST

START_TEST(backend_set_level_1) {
  int level = -1;
  set_level(0, &level);
  ck_assert_int_eq(level, 0);

  set_level(3000, &level);
  ck_assert_int_eq(level, 5);

  set_level(6000, &level);
  ck_assert_int_eq(level, 10);

  set_level(20000, &level);
  ck_assert_int_eq(level, 10);
}
END_TEST

START_TEST(backend_check_and_move_1) {
  int **field = create_dynamic_array(FIELD_ROWS, FIELD_COLUMNS);
  fill_from_static(field_1, field, FIELD_ROWS, FIELD_COLUMNS);
  Figure_t figure = {1, 0, {{4, 5}, {4, 6}, {4, 7}, {4, 8}}, {3, 5}, 2};

  // Tetris_t tetris = {field, 0, 0, 0, 0, 0, 0, figure, MOVING};
  check_and_move(&figure, field, Down);
  ck_assert_int_eq(figure.coords[0][0], 5);

  check_and_move(&figure, field, Left);
  ck_assert_int_eq(figure.coords[0][1], 4);

  check_and_move(&figure, field, Right);
  ck_assert_int_eq(figure.coords[0][1], 5);

  check_and_move(&figure, field, 10);
  ck_assert_int_eq(figure.coords[0][1], 5);

  free(field);
}
END_TEST

Suite *suite_backend(void) {
  Suite *suite = suite_create(MAGENTA "[backend]" RESET);
  TCase *tcase_core = tcase_create(RED "backend_tc" RESET);

  if (suite != NULL && tcase_core != NULL) {
    tcase_add_test(tcase_core, backend_updateCurrentState_1);
    tcase_add_test(tcase_core, backend_add_points_for_rows_1);
    tcase_add_test(tcase_core, backend_set_speed_1);
    tcase_add_test(tcase_core, backend_set_level_1);
    tcase_add_test(tcase_core, backend_check_and_move_1);

    suite_add_tcase(suite, tcase_core);
  }
  return suite;
}
