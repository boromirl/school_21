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

START_TEST(fsm_on_start_state_1) {
  tetris_init();

  userInput(NoAction, false);
  GameState_t state = get_GameState();
  ck_assert_int_eq(state, START);

  userInput(Start, false);

  bool res = (get_GameState() == SPAWN);
  ck_assert_int_eq(res, true);
  tetris_end();
}
END_TEST

START_TEST(fsm_on_start_state_2) {
  tetris_init();
  userInput(Terminate, false);

  bool res = (get_GameState() == EXIT_STATE);
  ck_assert_int_eq(res, true);
  tetris_end();
}
END_TEST

START_TEST(fsm_on_start_state_3) {
  tetris_init();
  userInput(Left, false);

  bool res = (get_GameState() == START);
  ck_assert_int_eq(res, true);
  tetris_end();
}
END_TEST

START_TEST(fsm_on_spawn_state_1) {
  Tetris_t tetris = {NULL, 0, 0, 0, 0, 0, 0, {0}, SPAWN};
  act(NoAction, &tetris);

  bool res = (tetris.state == MOVING);
  ck_assert_int_eq(res, true);
  ck_assert_int_eq((tetris.next != 0), true);
  ck_assert_int_eq((tetris.current_figure.PoR[0] == START_Y), true);
  ck_assert_int_eq((tetris.current_figure.PoR[1] == START_X), true);
  ck_assert_int_eq((tetris.current_figure.color_code == 1), true);
}
END_TEST

START_TEST(fsm_on_moving_state_1) {
  tetris_init();
  userInput(Start, false);
  userInput(NoAction, false);

  // проверка при движении фигуры
  GameState_t state;
  userInput(Right, false);
  state = get_GameState();
  ck_assert_int_eq(state, MOVING);

  userInput(Left, false);
  state = get_GameState();
  ck_assert_int_eq(state, MOVING);

  // вращение
  userInput(Action, false);

  // проверка паузы
  userInput(Pause, false);
  state = get_GameState();
  ck_assert_int_eq(state, PAUSE);

  // проверка выхода из паузы
  userInput(Pause, false);
  state = get_GameState();
  ck_assert_int_eq(state, MOVING);

  // выход из игры
  userInput(Terminate, false);
  state = get_GameState();
  ck_assert_int_eq(state, EXIT_STATE);

  tetris_end();
}
END_TEST

START_TEST(fsm_on_moving_state_2) {
  tetris_init();
  userInput(Start, false);
  userInput(NoAction, false);

  // проверка перехода в состояние стыковки
  GameState_t state;
  userInput(Down, false);
  state = get_GameState();
  ck_assert_int_eq(state, ATTACHING);

  userInput(NoAction, false);
  userInput(NoAction, false);

  // проверка перехода в состояние перемещения по прохождению времени
  for (int tick = 1; tick < 10; tick++) {
    userInput(NoAction, false);
  }

  state = get_GameState();
  ck_assert_int_eq(state, SHIFTING);

  tetris_end();
}
END_TEST

START_TEST(fsm_on_pause_state_1) {
  tetris_init();
  GameState_t state;
  userInput(Start, false);
  userInput(NoAction, false);

  // Переход в паузу
  userInput(Pause, false);
  state = get_GameState();
  ck_assert_int_eq(state, PAUSE);
  // Пропуск действия в паузе
  userInput(NoAction, false);
  state = get_GameState();
  ck_assert_int_eq(state, PAUSE);
  // Выход из паузы
  userInput(Pause, false);
  state = get_GameState();
  ck_assert_int_eq(state, MOVING);
  // Переход в паузу и выход из игры
  userInput(Pause, false);
  userInput(Terminate, false);
  state = get_GameState();

  ck_assert_int_eq(state, EXIT_STATE);

  tetris_end();
}
END_TEST

START_TEST(fsm_on_gameover_state_1) {
  tetris_init();

  userInput(Start, false);
  userInput(NoAction, false);
  // Форсируем gameover
  for (int i = 0; i < 50; i++) {
    userInput(Down, false);
    userInput(NoAction, false);
  }

  GameState_t state = get_GameState();

  ck_assert_int_eq(state, GAMEOVER);
  // начало новой игры после gameover
  userInput(Start, false);
  state = get_GameState();
  ck_assert_int_eq(state, SPAWN);

  for (int i = 0; i < 50; i++) {
    userInput(Down, false);
    userInput(NoAction, false);
  }
  // Выход из игры после gameover
  userInput(Terminate, false);
  state = get_GameState();
  ck_assert_int_eq(state, EXIT_STATE);

  tetris_end();
}
END_TEST

START_TEST(fsm_on_shifting_state_1) {
  int **field = create_dynamic_array(FIELD_ROWS, FIELD_COLUMNS);
  fill_from_static(field_1, field, FIELD_ROWS, FIELD_COLUMNS);
  Figure_t figure = {1, 0, {{4, 5}, {4, 6}, {4, 7}, {4, 8}}, {3, 5}, 2};

  Tetris_t tetris = {field, 0, 0, 0, 0, 0, 0, figure, SHIFTING};

  // после shifting возвращение к moving, если фигура может двигаться вниз
  act(NoAction, &tetris);
  ck_assert_int_eq(tetris.state, MOVING);

  // переход к attaching, если после спуска фигуры вниз она упирается во что-то
  tetris.state = SHIFTING;
  tetris.field[15][5] = 1;
  tetris.current_figure.coords[0][0] = 13;
  tetris.current_figure.coords[0][1] = 5;

  act(NoAction, &tetris);
  ck_assert_int_eq(tetris.state, ATTACHING);

  free(field);
}
END_TEST

START_TEST(fsm_on_attaching_state_1) {
  int **field = create_dynamic_array(FIELD_ROWS, FIELD_COLUMNS);
  fill_from_static(field_1, field, FIELD_ROWS, FIELD_COLUMNS);
  Figure_t figure = {1, 0, {{4, 5}, {4, 6}, {4, 7}, {4, 8}}, {3, 5}, 2};

  Tetris_t tetris = {field, 0, 0, 0, 0, 0, 0, figure, ATTACHING};

  act(NoAction, &tetris);

  ck_assert_int_eq(tetris.state, SPAWN);

  free(field);
}
END_TEST

START_TEST(fsm_default_act) {
  Tetris_t tetris = {NULL, 0, 0, 0, 0, 0, 0, {0}, 15};
  act(NoAction, &tetris);
}
END_TEST

Suite *suite_fsm(void) {
  Suite *suite = suite_create(MAGENTA "[fsm]" RESET);
  TCase *tcase_core = tcase_create(RED "fsm_tc" RESET);

  if (suite != NULL && tcase_core != NULL) {
    tcase_add_test(tcase_core, fsm_on_start_state_1);
    tcase_add_test(tcase_core, fsm_on_start_state_2);
    tcase_add_test(tcase_core, fsm_on_start_state_3);

    tcase_add_test(tcase_core, fsm_on_spawn_state_1);

    tcase_add_test(tcase_core, fsm_on_moving_state_1);
    tcase_add_test(tcase_core, fsm_on_moving_state_2);

    tcase_add_test(tcase_core, fsm_on_pause_state_1);

    tcase_add_test(tcase_core, fsm_on_gameover_state_1);

    tcase_add_test(tcase_core, fsm_on_shifting_state_1);

    tcase_add_test(tcase_core, fsm_on_attaching_state_1);

    tcase_add_test(tcase_core, fsm_default_act);

    suite_add_tcase(suite, tcase_core);
  }
  return suite;
}
