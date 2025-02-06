#include "../include/tetris_backend.h"

// статические объекты игры
static Tetris_t tetris;
static GameInfo_t game_info;

void tetris_init() {
  tetris.state = START;

  // выбор следующей фигуры
  tetris.next = rand() % FIGURE_COUNT;
  // создание динамического массива поля
  tetris.field = malloc((FIELD_ROWS * sizeof(int*)) +
                        (FIELD_ROWS * FIELD_COLUMNS * sizeof(int)));
  int* ptr = (int*)(tetris.field + FIELD_ROWS);
  for (int i = 0; i < FIELD_ROWS; i++) {
    tetris.field[i] = ptr + FIELD_COLUMNS * i;
  }

  // заполнение структуры нулями
  zero_tetris();

  tetris.high_score = get_high_score();

  game_info_init();
}

void game_info_init(void) {
  // объявление динамического массива для информации о поле
  // рисуются только 20 из 23 строк. Только они видны игроку
  game_info.field = malloc((VISIBLE_ROWS * sizeof(int*)) +
                           (VISIBLE_ROWS * VISIBLE_COLUMNS * sizeof(int)));
  int* ptr1 = (int*)(game_info.field + VISIBLE_ROWS);
  for (int i = 0; i < VISIBLE_ROWS; i++) {
    game_info.field[i] = ptr1 + VISIBLE_COLUMNS * i;
  }

  for (int row = 0; row < VISIBLE_ROWS; row++) {
    for (int col = 0; col < VISIBLE_COLUMNS; col++) {
      game_info.field[row][col] = 0;
    }
  }

  // объявление динамического массива, в котором хранятся данные о следующей
  // фигуре следующая фигура хранится в виде матрицы 4 на 6, со значениями от 1
  // до 7 (цвета/тип фигуры)
  game_info.next = malloc((4 * sizeof(int*)) + (4 * 6 * sizeof(int)));
  int* ptr2 = (int*)(game_info.next + 4);
  for (int i = 0; i < 4; i++) {
    game_info.next[i] = ptr2 + 6 * i;
  }

  game_info.high_score = tetris.high_score;
  game_info.level = 0;
  game_info.pause = false;
  game_info.score = 0;
  game_info.speed = 0;
}

void tetris_end(void) {
  free(tetris.field);

  free(game_info.field);
  free(game_info.next);
}

void userInput(UserAction_t action, bool hold) {
  act(action, &tetris);

  (void)hold;  // этот параметр не используется, void нужен, чтобы не было
               // -Werror=unused parameter
}

GameInfo_t updateCurrentState(void) {
  game_info.score = tetris.score;
  game_info.high_score = tetris.high_score;
  game_info.level = tetris.level;
  game_info.speed = tetris.speed;
  game_info.pause = (tetris.state == PAUSE);

  get_color_matrix(tetris.next, 0, game_info.next);

  // показывать только 20 видимых строк
  // то есть с 3 по 23
  for (int row = 0; row < VISIBLE_ROWS; row++) {
    for (int col = 0; col < VISIBLE_COLUMNS; col++) {
      game_info.field[row][col] = tetris.field[row + ROW_DIFF][col];
    }
  }

  for (int i = 0; i < BLOCK_COUNT; i++) {
    int y = tetris.current_figure.coords[i][0];
    int x = tetris.current_figure.coords[i][1];

    if (is_visible(y, x)) {
      game_info.field[y - ROW_DIFF][x] = tetris.current_figure.color_code;
    }
  }

  return game_info;
}

GameState_t get_GameState(void) { return tetris.state; }

// вычисление координат фигуры по id и orientation, с записью вычисленных
// координат в структуру figure
void calculate_coords(Figure_t* figure) {
  int** shape = malloc((4 * sizeof(int*)) + (4 * 2 * sizeof(int)));
  int* ptr = (int*)(shape + 4);
  for (int i = 0; i < 4; i++) {
    shape[i] = ptr + 2 * i;
  }

  get_shape(figure->id, figure->orientation, shape);
  for (int i = 0; i < 4; i++) {
    figure->coords[i][0] = shape[i][0] + figure->PoR[0];
    figure->coords[i][1] = shape[i][1] + figure->PoR[1];
  }

  free(shape);
}

// добавить фигуру на поле по координатам
void place_figure(Figure_t figure, int** field) {
  for (int i = 0; i < BLOCK_COUNT; i++) {
    int y = figure.coords[i][0];
    int x = figure.coords[i][1];

    if (is_in_field(y, x)) {
      field[y][x] = figure.color_code;
    }
  }
}

// полное зачищение матрицы игрового поля
void clear_field(void) {
  for (int row = 0; row < FIELD_ROWS; row++) {
    for (int col = 0; col < FIELD_COLUMNS; col++) {
      tetris.field[row][col] = 0;
    }
  }
}

// поворот фигуры
void rotate_figure(Figure_t* figure) {
  Figure_t temp = *figure;
  temp.orientation = (temp.orientation + 1) % 4;
  calculate_coords(&temp);
  if (!is_collision(temp, tetris.field)) {
    *figure = temp;
  }
}

// движение фигуры с проверкой на столкновение
// двигаем temp, проверяем все ли ОК, и приравниваем к temp
void check_and_move(Figure_t* figure, int** field, int direction) {
  Figure_t temp = *figure;
  switch (direction) {
    case Left:
      move_figure(&temp, 0, -1);
      break;
    case Right:
      move_figure(&temp, 0, 1);
      break;
    case Down:
      move_figure(&temp, 1, 0);
      break;
    default:
      break;
  }

  if (!is_collision(temp, field)) {
    *figure = temp;
  }
}

// движение координат фигуры по горизонтали (x) и вертикали (y) без проверок
void move_figure(Figure_t* figure, int y, int x) {
  for (int i = 0; i < 4; i++) {
    figure->coords[i][0] += y;
    figure->coords[i][1] += x;
  }
  figure->PoR[0] += y;
  figure->PoR[1] += x;
}

void destroy_complete_rows(int** field) {
  for (int row = 0; row < FIELD_ROWS; row++) {
    if (is_row_complete(field, row)) {
      destroy_row(field, row);
      for (int i = (row - 1); i > 0; i--) {
        drop_row(field, i);
      }
    }
  }
}

void destroy_row(int** field, int row) {
  for (int col = 0; col < FIELD_COLUMNS; col++) {
    field[row][col] = 0;
  }
}

// заменяет нижнюю строку узанной, указанную строку зачищает
void drop_row(int** field, int row) {
  for (int col = 0; col < FIELD_COLUMNS; col++) {
    field[row + 1][col] = field[row][col];
  }
  destroy_row(field, row);
}

// заполнение структуры tetris нулями
void zero_tetris() {
  clear_field();

  tetris.score = 0;

  tetris.level = 0;

  tetris.speed = INITIAL_SPEED;

  for (int i = 0; i < 4; i++) {
    tetris.current_figure.coords[i][0] = -1;
    tetris.current_figure.coords[i][1] = -1;
  }

  tetris.tick = 0;
}

// падение фигуры вниз поля до упора
void drop_figure(Tetris_t* tetris) {
  while (!is_touching(tetris->current_figure, tetris->field)) {
    check_and_move(&(tetris->current_figure), tetris->field, Down);
  }
}

int count_complete_rows(int** field) {
  int count = 0;
  for (int row = 0; row < FIELD_ROWS; row++) {
    if (is_row_complete(field, row)) count++;
  }
  return count;
}

void add_points_for_rows(int number_of_complete_rows, int* score) {
  switch (number_of_complete_rows) {
    case 1:
      *score += POINTS_ONE_LINE;
      break;
    case 2:
      *score += POINTS_TWO_LINES;
      break;
    case 3:
      *score += POINTS_THREE_LINES;
      break;
    case 4:
      *score += POINTS_FOUR_LINES;
      break;
    default:
      break;
  }
}

void set_level(int score, int* level) {
  *level = (score / POINTS_FOR_LEVEL);
  if (*level > 10) *level = 10;
}

void set_speed(int level, int* speed) {
  switch (level) {
    case 0:
      *speed = INITIAL_SPEED;
      break;
    case 1:
      *speed = SPEED_1;
      break;
    case 2:
      *speed = SPEED_2;
      break;
    case 3:
      *speed = SPEED_3;
      break;
    case 4:
      *speed = SPEED_4;
      break;
    case 5:
      *speed = SPEED_5;
      break;
    case 6:
      *speed = SPEED_6;
      break;
    case 7:
      *speed = SPEED_7;
      break;
    case 8:
      *speed = SPEED_8;
      break;
    case 9:
      *speed = SPEED_9;
      break;
    case 10:
      *speed = SPEED_10;
      break;
    default:
      break;
  }
}

// Читаем хай скор из файла. Если файла нет, то создаем нулевой
int get_high_score() {
  int high_score = 0;

  FILE* file;
  file = fopen("high_score.txt", "r");
  if (file == NULL) {
    file = fopen("high_score.txt", "w");
    fprintf(file, "0");
  } else {
    fscanf(file, "%d", &high_score);
  }
  fclose(file);

  return high_score;
}

void set_high_score(int new_high_score, int* current_high_score) {
  FILE* file;
  file = fopen("high_score.txt", "w");
  fprintf(file, "%d", new_high_score);
  fclose(file);

  *current_high_score = new_high_score;
}