#include "../s21_matrix.h"

static double get_mult(matrix_t *A, matrix_t *B, int row, int col);

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OK;

  if (!is_matrix_correct(A) || !is_matrix_correct(B) || result == NULL)
    status = INCORRECT_MATRIX;
  // если количество строк первой матрицы, не совпадает с количеством столбцов
  // второй
  else if (A->columns != B->rows)
    status = CALCULATION_ERROR;
  // если все ОК
  else {
    status = s21_create_matrix(A->rows, B->columns, result);
    // если матрица создана правильно
    if (status == OK) {
      for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
          result->matrix[i][j] = get_mult(A, B, i, j);
          // проверка на INF и NAN
          if (!isfinite(result->matrix[i][j])) status = CALCULATION_ERROR;
        }
      }
    }
  }

  return status;
}

static double get_mult(matrix_t *A, matrix_t *B, int row, int col) {
  double result = 0.0;
  for (int i = 0; i < A->columns; i++) {
    result += A->matrix[row][i] * B->matrix[i][col];
  }

  return result;
}