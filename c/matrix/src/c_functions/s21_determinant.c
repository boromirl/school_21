#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int status = OK;

  if (!is_matrix_correct(A) || result == NULL) status = INCORRECT_MATRIX;
  // определитель можно вычислить только у квадратной матрицы
  else if (A->columns != A->rows)
    status = CALCULATION_ERROR;
  // если все ОК
  else {
    *result = 0;
    if (A->rows == 1)
      *result = A->matrix[0][0];
    else if (A->rows == 2)
      *result = (A->matrix[0][0] * A->matrix[1][1]) -
                (A->matrix[0][1] * A->matrix[1][0]);
    else if (A->rows > 2) {
      // находим определитель по первой строке
      // умножаем каждый элемент строки на его алгебраическое дополнение
      for (int j = 0; j < A->columns; j++) {
        *result += (A->matrix[0][j] * find_cofactor(*A, 0, j));
      }
    }
    // округление числа double до седьмого знака после запятой (без округления
    // бывают ошибки из-за представления числа в двоичном виде)
    *result *= 1E7;
    *result = round(*result);
    *result /= 1E7;
  }

  return status;
}