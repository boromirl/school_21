#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

// ошибка, нееквадратная матрица
TEST(SuiteDeterminant, DeterminantException) {
  S21Matrix m1(3, 4);

  ASSERT_THROW(m1.Determinant(), std::out_of_range);
}

// определитель матрицы нулей = 0
TEST(SuiteDeterminant, Determinant1) {
  S21Matrix m1(5, 5);

  double res = m1.Determinant();
  ASSERT_EQ(res, 0);
}

// определитель матрицы, заполненной одинаковыми элементами == 0 (исключение
// матрица 1x1)
TEST(SuiteDeterminant, Determinant2) {
  S21Matrix m1(4, 4,
               {5.2, 5.2, 5.2, 5.2, 5.2, 5.2, 5.2, 5.2, 5.2, 5.2, 5.2, 5.2, 5.2,
                5.2, 5.2, 5.2});
  double res = m1.Determinant();
  ASSERT_EQ(res, 0);
}

// матрица 1x1
TEST(SuiteDeterminant, Determinant3) {
  S21Matrix m1(1, 1, {500});
  double res = m1.Determinant();
  ASSERT_EQ(res, 500);
}

// матрица 2x2
TEST(SuiteDeterminant, Determinant4) {
  S21Matrix m1(2, 2, {4.1, 7, 2.2, -3});
  double res = m1.Determinant();
  ASSERT_NEAR(res, -27.7, 1E-12);
}

// матрица 3x3
TEST(SuiteDeterminant, Determinant5) {
  S21Matrix m1(3, 3, {1, 2, 3, 0, 1, 4, 5, 6, 0});
  double res = m1.Determinant();
  ASSERT_EQ(res, 1);
}

// матрица 5x5
TEST(SuiteDeterminant, Determinant6) {
  S21Matrix m1(5, 5, {3, -1, 2, 5, 7, 0, 6, 4, 1, 2, -1, 3, 5,
                      4, 6,  2, 0, 1, 3, 1, 1, 2, 3, 0,  -1});
  double res = m1.Determinant();
  ASSERT_EQ(res, -756);
}