#include "../s21_matrix.h"

static int are_equal(double x, double y);

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = SUCCESS;
  if ((A->columns != B->columns) || (A->rows != B->rows))
    result = FAILURE;
  else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (!are_equal(A->matrix[i][j], B->matrix[i][j])) {
          result = FAILURE;
          break;
        }
      }
      if (result == FAILURE) break;
    }
  }

  return result;
}

static int are_equal(double x, double y) {
  double sub = fabs(x - y);
  // для правильного представления результата вычитания
  // иначе 1E-7 становится чуть меньше и проходит то, что не должен
  sub *= 1E7;
  sub = round(sub);
  sub /= 1E7;
  double precision = 1E-7;
  return sub < precision;
}