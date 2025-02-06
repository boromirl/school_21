#include "../include/tetris_backend.h"

/*
    Здесь собраны булевы функции проверок
 */

// Должна ли быть видна в интерфейсе эта точка
bool is_visible(int y, int x) {
  if (y >= ROW_DIFF && y < (VISIBLE_ROWS + ROW_DIFF) && x >= 0 &&
      x < VISIBLE_ROWS) {
    return true;
  }
  return false;
}

// Соприкасается ли данная фигура с полем (снизу)
bool is_touching(Figure_t figure, int** field) {
  for (int i = 0; i < BLOCK_COUNT; i++) {
    int y = figure.coords[i][0];
    int x = figure.coords[i][1];
    if (y == (FIELD_ROWS - 1) || field[y + 1][x]) return true;
  }
  return false;
}

// Есть ли в поле заполненные строки
bool are_complete_rows(int** field) {
  for (int row = 0; row < FIELD_ROWS; row++) {
    if (is_row_complete(field, row)) return true;
  }
  return false;
}

// Заполнена ли конкретная строка
bool is_row_complete(int** field, int row) {
  for (int col = 0; col < FIELD_COLUMNS; col++) {
    if (field[row][col] == 0) return false;
  }
  return true;
}

// Простая проверка, пересекаются ли координаты фигуры с игровым полем
bool is_collision(Figure_t figure, int** field) {
  for (int i = 0; i < 4; i++) {
    int y = figure.coords[i][0];
    int x = figure.coords[i][1];
    // здесь порядок очень важен!!! Сначала нужно проверить находится ли фигура
    // в поле, а потом уже заполнено ли оно иначе сегфолт из-за попытки взять
    // несуществующую координату из поля
    if (!is_in_field(y, x) || field[y][x]) return true;
  }
  return false;
}

// Простая проверка, находится ли точка с координатами в поле
bool is_in_field(int y, int x) {
  if (y >= 0 && y < FIELD_ROWS && x >= 0 && x < FIELD_COLUMNS)
    return true;
  else
    return false;
}