#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

static S21Matrix test_matrix_1(3, 2, {1, 4, 2, 5, 3, 6});
static S21Matrix test_matrix_2(2, 3, {1, -1, 1, 2, 3, 4});

static S21Matrix test_matrix_3(2, 3, {24, 5, 3.2, 5, -2, 18});
static S21Matrix test_matrix_4(3, 4,
                               {82, 4, -9, -9.2, 8, 8, 1, 3, 5, 5.2, 2, -4.2});

// ошибка, количество столбцов первой матрицы не равно количеству строк второй
TEST(SuiteMulMatrix, MulMatrixException) {
  S21Matrix m1(2, 2, {1, 2, 3, 4});
  S21Matrix m2(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});

  ASSERT_THROW(m1.MulMatrix(m2), std::out_of_range);
}

// умножение зануленных матриц
TEST(SuiteMulMatrix, MullMatrix1) {
  S21Matrix m1(5, 6);
  S21Matrix m2(6, 8);

  m1.MulMatrix(m2);

  S21Matrix res(5, 8);

  ASSERT_TRUE(m1.EqMatrix(res));
}

// умножение матриц, заполненных одним положительным числом
TEST(SuiteMulMatrix, MullMatrix2) {
  S21Matrix m1(3, 4, {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3});
  S21Matrix m2(4, 4, {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6});

  m1.MulMatrix(m2);

  S21Matrix res(3, 4, {72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72});

  ASSERT_TRUE(m1.EqMatrix(res));
}

// умножение матриц, заполненных одним отрицательным числом
TEST(SuiteMulMatrix, MullMatrix3) {
  S21Matrix m1(3, 4, {-3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3});
  S21Matrix m2(4, 4, {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6});

  m1.MulMatrix(m2);

  S21Matrix res(3, 4, {72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72});

  ASSERT_TRUE(m1.EqMatrix(res));
}

// умножение матриц, заполненных одним отрицательным/положительным числом
TEST(SuiteMulMatrix, MullMatrix4) {
  S21Matrix m1(3, 4, {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3});
  S21Matrix m2(
      4, 4, {-6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6});

  m1.MulMatrix(m2);

  S21Matrix res(3, 4,
                {-72, -72, -72, -72, -72, -72, -72, -72, -72, -72, -72, -72});

  ASSERT_TRUE(m1.EqMatrix(res));
}

// умножение матриц, заполненных разными числами 1
TEST(SuiteMulMatrix, MullMatrix5) {
  S21Matrix m1(test_matrix_1);
  S21Matrix m2(test_matrix_2);

  S21Matrix res(3, 3, {9, 11, 17, 12, 13, 22, 15, 15, 27});

  m1.MulMatrix(m2);

  ASSERT_TRUE(m1.EqMatrix(res));
}

// умножение матриц, заполненных разными числами 2
TEST(SuiteMulMatrix, MullMatrix6) {
  S21Matrix m1(test_matrix_3);
  S21Matrix m2(test_matrix_4);

  S21Matrix res(2, 4, {2024, 152.64, -204.6, -219.24, 484, 97.6, -11, -127.6});

  m1.MulMatrix(m2);

  ASSERT_TRUE(m1.EqMatrix(res));
}