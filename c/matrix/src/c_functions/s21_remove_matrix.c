#include "../s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
  if (is_matrix_correct(A)) {
    free(A->matrix);
    A->matrix = NULL;
  }
}