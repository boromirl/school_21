#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t* result) {
  if (result == NULL) {
    return INCORRECT_MATRIX;
  }

  int status = OK;

  if (rows <= 0 || columns <= 0) {
    status = INCORRECT_MATRIX;
  } else {
    result->rows = rows;
    result->columns = columns;

    result->matrix =
        malloc((rows * sizeof(double*)) + (rows * columns * sizeof(double)));

    // проверка на корректное выделение памяти
    if (result->matrix == NULL) {
      status = INCORRECT_MATRIX;
    } else {
      // выделение памяти под матрицу одним блоком
      double* ptr = (double*)(result->matrix + rows);
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = ptr + (columns * i);
      }

      // заполняем матрицу нулями
      fill_matrix(result, 0.0);
    }
  }

  return status;
}