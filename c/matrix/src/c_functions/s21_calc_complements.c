#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = OK;

  if (!is_matrix_correct(A) || result == NULL) status = INCORRECT_MATRIX;
  // подойдет только квадратная матрица
  else if (A->columns != A->rows)
    status = CALCULATION_ERROR;
  // если все ОК
  else {
    status = s21_create_matrix(A->columns, A->rows, result);
    // если матрица создана правильно
    if (status == OK) {
      for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
          result->matrix[i][j] = find_cofactor(*A, i, j);
        }
      }
    }
  }

  return status;
}