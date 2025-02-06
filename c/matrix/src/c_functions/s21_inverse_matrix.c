#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int status = OK;

  if (!is_matrix_correct(A) || result == NULL) status = INCORRECT_MATRIX;
  // подойдет только квадратная матрица
  else if (A->columns != A->rows)
    status = CALCULATION_ERROR;
  // если все ОК
  else {
    double determinant = 0.0;
    s21_determinant(A, &determinant);
    if (determinant == 0.0)
      status = CALCULATION_ERROR;
    else {
      matrix_t compl_matr = {};
      matrix_t transposed_matrix = {};

      // вычисляем матрицу алгебраических дополнений
      s21_calc_complements(A, &compl_matr);
      // транспонируем её
      s21_transpose(&compl_matr, &transposed_matrix);
      // умножаем транспонированную матрицу на 1/определитель
      s21_mult_number(&transposed_matrix, (1 / determinant), result);

      s21_remove_matrix(&compl_matr);
      s21_remove_matrix(&transposed_matrix);
    }
  }

  return status;
}