#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OK;

  if (!is_matrix_correct(A) || !is_matrix_correct(B) || result == NULL)
    status = INCORRECT_MATRIX;
  // если количество строк/столбцов не совпадает
  else if ((A->columns != B->columns) || (A->rows != B->rows))
    status = CALCULATION_ERROR;
  // если все ОК
  else {
    status = s21_create_matrix(A->rows, A->columns, result);
    // если матрица создана правильно
    if (status == OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
          // проверка на INF и NAN
          if (!isfinite(result->matrix[i][j])) status = CALCULATION_ERROR;
        }
      }
    }
  }

  return status;
}