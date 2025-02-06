#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int status = OK;

  if (!is_matrix_correct(A) || result == NULL)
    status = INCORRECT_MATRIX;
  else if (!isfinite(number))
    status = CALCULATION_ERROR;
  // если все ОК
  else {
    status = s21_create_matrix(A->rows, A->columns, result);
    // если матрица создана правильно
    if (status == OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] * number;
          // проверка на INF и NAN
          if (!isfinite(result->matrix[i][j])) status = CALCULATION_ERROR;
        }
      }
    }
  }

  return status;
}