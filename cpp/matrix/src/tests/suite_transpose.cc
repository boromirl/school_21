#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

// транспонирование нулевой матрицы
TEST(SuiteTranspose, Transpose1) {
  S21Matrix m1(4, 4);

  S21Matrix m2 = m1.Transpose();

  S21Matrix res(4, 4);

  ASSERT_TRUE(m2.EqMatrix(res));
}

// транспонирование квадратной матрицы
TEST(SuiteTranspose, Transpose2) {
  S21Matrix m1(4, 4, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16});

  S21Matrix m2 = m1.Transpose();

  S21Matrix res(4, 4, {1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15, 4, 8, 12, 16});

  ASSERT_TRUE(m2.EqMatrix(res));
}

// транспонирование заполненной неквадратной матрицы 1
TEST(SuiteTranspose, Transpose3) {
  S21Matrix m1(1, 5, {10.2, -3, 45, 100, 1});
  S21Matrix m2 = m1.Transpose();

  S21Matrix res(5, 1, {10.2, -3, 45, 100, 1});

  ASSERT_TRUE(m2.EqMatrix(res));
}
// транспонирование заполненной неквадратной матрицы 2
TEST(SuiteTranspose, Transpose4) {
  S21Matrix m1(3, 5, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15});
  S21Matrix m2 = m1.Transpose();

  S21Matrix res(5, 3, {1, 6, 11, 2, 7, 12, 3, 8, 13, 4, 9, 14, 5, 10, 15});

  ASSERT_TRUE(m2.EqMatrix(res));
}