#include "../include/tetris_backend.h"

static void on_start_state(UserAction_t action, Tetris_t* tetris);
static void on_spawn_state(Tetris_t* tetris);
static void on_moving_state(UserAction_t action, Tetris_t* tetris);
static void on_shifting_state(Tetris_t* tetris);
static void on_attach_state(Tetris_t* tetris);
static void on_gameover_state(UserAction_t action, Tetris_t* tetris);
static void on_pause_state(UserAction_t action, Tetris_t* tetris);

void act(UserAction_t action, Tetris_t* tetris) {
  switch (tetris->state) {
    case START:
      on_start_state(action, tetris);
      break;
    case SPAWN:
      on_spawn_state(tetris);
      break;
    case MOVING:
      on_moving_state(action, tetris);
      break;
    case SHIFTING:
      on_shifting_state(tetris);
      break;
    case ATTACHING:
      on_attach_state(tetris);
      break;
    case GAMEOVER:
      on_gameover_state(action, tetris);
      break;
    case PAUSE:
      on_pause_state(action, tetris);
      break;
    default:
      break;
  }
}

static void on_start_state(UserAction_t action, Tetris_t* tetris) {
  switch (action) {
    case Start:
      zero_tetris();
      tetris->state = SPAWN;
      break;
    case Terminate:
      tetris->state = EXIT_STATE;
      break;
    default:
      break;
  }
}

static void on_spawn_state(Tetris_t* tetris) {
  tetris->current_figure.id = tetris->next;
  tetris->current_figure.orientation = 0;
  tetris->current_figure.PoR[0] = START_Y;
  tetris->current_figure.PoR[1] = START_X;

  tetris->current_figure.color_code = tetris->current_figure.id + 1;
  calculate_coords(&(tetris->current_figure));

  // выбираем случайно следующую фигуру
  int new_id = rand() % FIGURE_COUNT;

  // для того, чтобы не было двух одинаковых фигур подряд, проверяем на
  // повторение
  tetris->next =
      (new_id == tetris->next) ? (new_id + 1) % FIGURE_COUNT : new_id;

  tetris->state = MOVING;
}

static void on_moving_state(UserAction_t action, Tetris_t* tetris) {
  switch (action) {
    case Terminate:
      tetris->state = EXIT_STATE;
      break;
    case Action:
      rotate_figure(&(tetris->current_figure));
      break;
    case Down:
      drop_figure(tetris);
      break;
    case Left:
      check_and_move(&(tetris->current_figure), tetris->field, Left);
      break;
    case Right:
      check_and_move(&(tetris->current_figure), tetris->field, Right);
      break;
    case Pause:
      tetris->state = PAUSE;
      break;
    default:
      break;
  }

  // Если не выход из игры
  if (!(tetris->state == EXIT_STATE)) {
    // сначала проверяем на прикосновение к полю
    if (is_touching(tetris->current_figure, tetris->field)) {
      tetris->state = ATTACHING;
      tetris->tick = 0;  // после стыковки начинаем новый цикл тиков
    }
    // переходим на следующий тик
    tetris->tick++;

    // если прошло достаточно тиков, фигура начинает падать сама
    if (tetris->tick > 9) {
      tetris->state = SHIFTING;
      tetris->tick =
          0;  // обнуляем тики (снова начинаем ждать перед следующим смещением)
    }
  }
}

static void on_shifting_state(Tetris_t* tetris) {
  // двигаемся вниз с проверкой
  check_and_move(&(tetris->current_figure), tetris->field, Down);
  // если есть прикосновение после движения, то стыкуемся
  if (is_touching(tetris->current_figure, tetris->field))
    tetris->state = ATTACHING;
  // если нет, то продолжаем движение
  else {
    tetris->state = MOVING;
  }
}

static void on_attach_state(Tetris_t* tetris) {
  // добавляем фигуру в матрицу поля
  place_figure(tetris->current_figure, tetris->field);
  // если есть хоть одна заполненная строка
  if (are_complete_rows(tetris->field)) {
    // считаем сколько строк заполнено
    int complete_rows = count_complete_rows(tetris->field);
    // уничтожаем заполненные строки(также здесь вниз падают строки выше
    // заполненных)
    destroy_complete_rows(tetris->field);
    // зачисляем очки
    add_points_for_rows(complete_rows, &(tetris->score));
    if (tetris->score > tetris->high_score)
      set_high_score(tetris->score, &(tetris->high_score));
    // изменяем уровень и скорость
    set_level(tetris->score, &(tetris->level));
    set_speed(tetris->level, &(tetris->speed));
  }
  tetris->state = SPAWN;

  // после стыковки фигуры, проверяем выходит ли она за пределы поля
  for (int block = 0; block < BLOCK_COUNT; block++) {
    if (tetris->current_figure.coords[block][0] < ROW_DIFF) {
      tetris->state = GAMEOVER;
    }
  }
}

static void on_gameover_state(UserAction_t action, Tetris_t* tetris) {
  switch (action) {
    case Start:
      tetris->state = START;
      userInput(Start, false);
      break;
    case Terminate:
      tetris->state = EXIT_STATE;
      break;
    default:
      break;
  }
}

static void on_pause_state(UserAction_t action, Tetris_t* tetris) {
  switch (action) {
    case Pause:
      tetris->state = MOVING;
      break;
    case Terminate:
      tetris->state = EXIT_STATE;
      break;
    default:
      break;
  }
}