#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

// ошибка, неквадратная матрица
TEST(SuiteInverseMatrix, InverseMatrixException1) {
  S21Matrix m1(3, 5);

  ASSERT_THROW(m1.InverseMatrix(), std::out_of_range);
}

// ошибка, определитель равен нулю
TEST(SuiteInverseMatrix, InverseMatrixException2) {
  S21Matrix m1(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});

  ASSERT_THROW(m1.InverseMatrix(), std::out_of_range);
}

// матрица 1x1
TEST(SuiteInverseMatrix, InverseMatrix1) {
  S21Matrix m1(1, 1, {5});

  S21Matrix m2 = m1.InverseMatrix();

  S21Matrix res(1, 1, {0.2});

  ASSERT_TRUE(m2.EqMatrix(res));
}

// матрица 2x2
TEST(SuiteInverseMatrix, InverseMatrix2) {
  S21Matrix m1(2, 2, {-1, 2, 0, 1});

  S21Matrix m2 = m1.InverseMatrix();

  S21Matrix res(2, 2, {-1, 2, 0, 1});

  ASSERT_TRUE(m2.EqMatrix(res));
}

// матрица 3x3
TEST(SuiteInverseMatrix, InverseMatrix3) {
  S21Matrix m1(3, 3, {2, 5, 7, 6, 3, 4, 5, -2, -3});

  S21Matrix m2 = m1.InverseMatrix();

  S21Matrix res(3, 3, {1, -1, 1, -38, 41, -34, 27, -29, 24});

  ASSERT_TRUE(m2.EqMatrix(res));
}

// матрица 5x5
TEST(SuiteInverseMatrix, InverseMatrix4) {
  S21Matrix m1(5, 5, {0, -1, 0, 0, -1, -1, 0, 0,  0, 1,  0, 0, 1,
                      0, -1, 0, 0, 0,  -1, 0, -1, 1, -1, 0, -1});

  S21Matrix m2 = m1.InverseMatrix();

  S21Matrix res(5, 5, {-0.25, -0.75, -0.25, 0,    -0.25, -0.75, -0.25, 0.25, 0,
                       0.25,  -0.25, 0.25,  0.75, 0,     -0.25, 0,     0,    0,
                       -1,    0,     -0.25, 0.25, -0.25, 0,     -0.25});

  ASSERT_TRUE(m2.EqMatrix(res));
}
