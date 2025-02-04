#include "../s21_matrix_oop.h"

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_) {
    throw std::out_of_range(
        "Incorrect input, number of columns of the first matrix should be "
        "equal to the number of rows of the second matrix");
  } else {
    S21Matrix temp(rows_, other.cols_);
    for (int i = 0; i < temp.rows_; i++) {
      for (int j = 0; j < temp.cols_; j++) {
        temp.matrix_[i][j] = MultColByRow(other, i, j);
      }
    }
    CopyMatrix(temp);
  }
}

double S21Matrix::MultColByRow(const S21Matrix& other, int row, int col) {
  double result = 0.0;
  for (int i = 0; i < cols_; i++) {
    result += matrix_[row][i] * other.matrix_[i][col];
  }

  return result;
}