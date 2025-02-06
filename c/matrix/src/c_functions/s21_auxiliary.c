#include "../s21_matrix.h"

void fill_matrix(matrix_t *matr, double num) {
  for (int i = 0; i < matr->rows; i++) {
    for (int j = 0; j < matr->columns; j++) {
      matr->matrix[i][j] = num;
    }
  }
}

int is_matrix_correct(matrix_t *matr) {
  int is_correct = 1;

  if (matr == NULL || matr->matrix == NULL || matr->rows < 1 ||
      matr->columns < 1)
    is_correct = 0;

  return is_correct;
}

void create_minor(matrix_t matr, int row, int col, matrix_t *minor) {
  s21_create_matrix((matr.rows - 1), (matr.columns - 1), minor);

  int current_row = 0;
  for (int i = 0; i < minor->rows; i++) {
    int current_col = 0;
    if (current_row == row) current_row++;
    for (int j = 0; j < minor->columns; j++) {
      if (current_col == col) current_col++;
      minor->matrix[i][j] = matr.matrix[current_row][current_col];
      current_col++;
    }
    current_row++;
  }
}

// cofactor - алгебраическое дополнение
double find_cofactor(matrix_t matr, int row, int col) {
  double result = 0.0;
  // алгебраическое дополнение равно 1 в матрице 1 на 1, т.к. определитель
  // матрицы 0 на 0 равен 1
  if (matr.rows == 1)
    result = 1;
  else {
    // создаем матрицу, вычернув строку и столбец из исходной
    matrix_t M = {};
    create_minor(matr, row, col, &M);

    // вычисляем определитель этой матрицы, т.е. минор элемента matr
    s21_determinant(&M, &result);

    // умножаем результат на -1 в степени, чтобы определить знак алгебраического
    // дополнения
    result *= pow(-1.0, (double)(row + col));

    s21_remove_matrix(&M);
  }

  return result;
}