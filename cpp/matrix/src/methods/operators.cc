#include "../s21_matrix_oop.h"

double& S21Matrix::operator()(int row, int col) {
  if (row < 0 || row >= rows_ || col < 0 || col >= cols_) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return matrix_[row][col];
}

const double& S21Matrix::operator()(int row, int col) const {
  if (row < 0 || row >= rows_ || col < 0 || col >= cols_) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return matrix_[row][col];
}

// перегрузка сложения
S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix res(*this);
  res.SumMatrix(other);
  return res;
}

// перегрузка сложения с присваиванием
S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}

// перегрузка вычитания
S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix res(*this);
  res.SubMatrix(other);
  return res;
}

// перегрузка вычитания с присваиванием
S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}

// перегрузка сравнения
bool S21Matrix::operator==(const S21Matrix& other) { return EqMatrix(other); }

// перегрузка умножения матрицы на матрицу
S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix res(*this);
  res.MulMatrix(other);
  return res;
}

// перегрузка умножения матрицы на матрицу с присваиванием
S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

// перегрузка умножения матрицы на число
S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix res(*this);
  res.MulNumber(num);
  return res;
}

// перегрузка умножения матрицы на число (матрица справа)
S21Matrix operator*(const double num, const S21Matrix& other) {
  S21Matrix res(other);
  res.MulNumber(num);
  return res;
}

// перегрузка умножения матрицы на число присваиванием
S21Matrix& S21Matrix::operator*=(const double num) {
  MulNumber(num);
  return *this;
}

// перегрузка приравнивания
S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  CopyMatrix(other);
  return *this;
}