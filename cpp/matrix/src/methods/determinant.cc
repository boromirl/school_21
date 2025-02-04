#include "../s21_matrix_oop.h"

double S21Matrix::Determinant() {
  if (!isSquare()) {
    throw std::out_of_range("Matrix is not square.");
  }
  double result = 0;
  if (rows_ == 1) {
    result = matrix_[0][0];
  } else if (rows_ == 2) {
    result = (matrix_[0][0] * matrix_[1][1]) - (matrix_[0][1] * matrix_[1][0]);
  } else if (rows_ > 2) {
    for (int j = 0; j < cols_; j++) {
      // нахождение определителя по первой строке
      // умножение каждого элеменнта строки на его алгебраическое дополнение
      result += (matrix_[0][j] * FindCofactor(0, j));
    }
  }

  return result;
}