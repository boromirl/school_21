#include "../s21_matrix_oop.h"

bool S21Matrix::isSquare() { return (rows_ == cols_); }

// найти алгебраическое дополнение
double S21Matrix::FindCofactor(int row, int col) {
  double result = 0.0;
  if (rows_ == 1) {
    result = 1;
  } else {
    S21Matrix minorMatrix = CreateMinorMatrix(row, col);
    result = minorMatrix.Determinant();

    result *= pow(-1.0, (double)(row + col));
  }
  return result;
}

// создание минорной матрицы путем вычеркивания троки и столбца
S21Matrix S21Matrix::CreateMinorMatrix(int row, int col) {
  if (row < 0 || row >= rows_ || col < 0 || col >= cols_) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }

  S21Matrix result(rows_ - 1, cols_ - 1);

  int current_row = 0;
  for (int i = 0; i < result.rows_; i++) {
    int current_col = 0;
    if (current_row == row) current_row++;
    for (int j = 0; j < result.rows_; j++) {
      if (current_col == col) current_col++;
      result.matrix_[i][j] = matrix_[current_row][current_col];
      current_col++;
    }
    current_row++;
  }

  return result;
}