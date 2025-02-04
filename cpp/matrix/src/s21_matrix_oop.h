#ifndef __S21MATRIX_H__
#define __S21MATRIX_H__

#include <cmath>
#include <cstring>
#include <iostream>

class S21Matrix {
 private:
  int rows_, cols_;
  double** matrix_;

 public:
  S21Matrix();                        // default constructor
  S21Matrix(int rows, int cols);      // parameterized constructor
  S21Matrix(const S21Matrix& o);      // copy constructor
  S21Matrix(S21Matrix&& o) noexcept;  // move constructor
  S21Matrix(int rows, int cols,
            std::initializer_list<double> init_list);  // init_list constructor
  ~S21Matrix();                                        // destructor

  // operator overloads
  S21Matrix& operator=(const S21Matrix& other);
  bool operator==(const S21Matrix& other);
  double& operator()(int row, int col);
  const double& operator()(int row, int col) const;

  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(const double num);
  friend S21Matrix operator*(const double num, const S21Matrix& other);

  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double num);

  // methods
  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  // accessors
  int GetRows();
  int GetCols();
  // mutators
  void SetRows(int new_rows);
  void SetCols(int new_cols);

  bool isSquare();
  double FindCofactor(int row, int col);
  S21Matrix CreateMinorMatrix(int row, int col);

  double MultColByRow(const S21Matrix& other, int row, int col);
  void CopyMatrix(const S21Matrix& other);  // full copy of matrix with changes
                                            // in rows_ and cols_

  void AllocateMemory();
  void DeallocateMemory();
};

#endif