#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::CalcComplements() {
  if (!isSquare()) {
    throw std::out_of_range("Matrix is not square.");
  }
  S21Matrix result(rows_, cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      result.matrix_[i][j] = FindCofactor(i, j);
    }
  }

  return result;
}