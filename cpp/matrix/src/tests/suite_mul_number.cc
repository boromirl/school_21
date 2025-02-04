#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

static S21Matrix test_matrix_1(5, 5, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
static S21Matrix test_matrix_2(3, 4,
                               {17, 3, 500, 4.2, 140, -8.2, -20.45, -23000,
                                300.14, -7.43, 0.00001, 1000000});
static S21Matrix test_matrix_3(3, 3, {4, 4, 4, 16, 16, 16, 40, 40, 40});

// умножение зануленной матрицы на число
TEST(SuiteMulNumber, MulNumber1) {
  S21Matrix m1(test_matrix_1);

  m1.MulNumber(5.2);

  ASSERT_TRUE(m1.EqMatrix(test_matrix_1));
}

// умножение заполненной матрицы на 0
TEST(SuiteMulNumber, MulNumber2) {
  S21Matrix m1(test_matrix_2);

  m1.MulNumber(0.0);

  S21Matrix res(3, 4);

  ASSERT_TRUE(m1.EqMatrix(res));
}

// умножение матрицы на положительное число
TEST(SuiteMulNumber, MulNumber3) {
  S21Matrix m1(test_matrix_2);

  m1.MulNumber(2);

  S21Matrix res(3, 4,
                {34, 6, 1000, 8.4, 280, -16.4, -40.9, -46000, 600.28, -14.86,
                 0.00002, 2000000});

  ASSERT_TRUE(m1.EqMatrix(res));
}

// умножение матрицы на отрицательное число
TEST(SuiteMulNumber, MulNumber4) {
  S21Matrix m1(test_matrix_2);

  m1.MulNumber(-2);

  S21Matrix res(3, 4,
                {-34, -6, -1000, -8.4, -280, 16.4, 40.9, 46000, -600.28, 14.86,
                 -0.00002, -2000000});

  ASSERT_TRUE(m1.EqMatrix(res));
}

// умножение матрицы на дробное число
TEST(SuiteMulNumber, MulNumber5) {
  S21Matrix m1(test_matrix_3);

  m1.MulNumber(0.25);

  S21Matrix res(3, 3, {1, 1, 1, 4, 4, 4, 10, 10, 10});

  ASSERT_TRUE(m1.EqMatrix(res));
}