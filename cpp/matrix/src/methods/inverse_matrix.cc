#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::InverseMatrix() {
  double determinant = Determinant();
  if (determinant == 0) {
    throw std::out_of_range(
        "Determinant is equal to 0. Matrix can't be inverted.");
  }
  S21Matrix complementsMatrix = CalcComplements();

  S21Matrix transposedMatrix = complementsMatrix.Transpose();

  transposedMatrix.MulNumber(1.0 / determinant);

  S21Matrix result(rows_, cols_);
  result.CopyMatrix(transposedMatrix);

  return result;
}