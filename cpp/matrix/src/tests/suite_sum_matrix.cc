#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

static S21Matrix test_matrix_1(5, 5, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
static S21Matrix test_matrix_2(5, 5, {0, 2, 3, 0, 0, 5.2, 7,  0, 0, 0, 0, 0, 0,
                                      0, 0, 2, 3, 0, 0,   14, 0, 0, 0, 0, 0});
static S21Matrix test_matrix_3(2, 2,
                               {0.000000001, 0.0000001, 5E20, -0.0000001});
static S21Matrix test_matrix_4(2, 2, {0.000000001, 0.0000001, 3E20, 0.0000001});
static S21Matrix test_matrix_5(5, 5, {-5.2, -5.2, -5.2, -5.2, -5.2, -5.2, -5.2,
                                      -5.2, -5.2, -5.2, -5.2, -5.2, -5.2, -5.2,
                                      -5.2, -5.2, -5.2, -5.2, -5.2, -5.2, -5.2,
                                      -5.2, -5.2, -5.2, -5.2});
static S21Matrix test_matrix_6(5, 5,
                               {5.2, 5.2, 5.2, 5.2, 5.2, 5.2, 5.2, 5.2, 5.2,
                                5.2, 5.2, 5.2, 5.2, 5.2, 5.2, 5.2, 5.2, 5.2,
                                5.2, 5.2, 5.2, 5.2, 5.2, 5.2, 5.2});

static S21Matrix test_matrix_7(3, 4,
                               {3.2, -440, 8.2, 17, 140, 8.2, -20.45, 24000, 81,
                                7.43, -0.00001, 500000});

static S21Matrix test_matrix_8(3, 4,
                               {17, 3, 500, 4.2, 140, -8.2, -20.45, -23000,
                                300.14, -7.43, 0.00001, 1000000});

// сложение зануленных матриц
TEST(SuiteSumMatrix, SumMatrix1) {
  S21Matrix m1(5, 5);
  S21Matrix m2(5, 5);

  m1.SumMatrix(m2);

  ASSERT_TRUE(m1.EqMatrix(test_matrix_1));
}

// сложение нулевой матрицы с ненулевой
TEST(SuiteSumMatrix, SumMatrix2) {
  S21Matrix m1(test_matrix_1);
  S21Matrix m2(test_matrix_2);

  m1.SumMatrix(m2);

  ASSERT_TRUE(m1.EqMatrix(test_matrix_2));
}

// сложение матриц с обратными значениями (-5.2 и 5.2)
TEST(SuiteSumMatrix, SumMatrix3) {
  S21Matrix m1(test_matrix_5);
  S21Matrix m2(test_matrix_6);

  m1.SumMatrix(m2);

  S21Matrix res(5, 5);

  ASSERT_TRUE(m1.EqMatrix(res));
}

// сложение матриц, заполненных различными числами 1
TEST(SuiteSumMatrix, SumMatrix4) {
  S21Matrix m1(test_matrix_7);
  S21Matrix m2(test_matrix_8);

  m1.SumMatrix(m2);

  S21Matrix res(3, 4,
                {20.2, -437, 508.2, 21.2, 280, 0.0, -40.9, 1000, 381.14, 0.0,
                 0.0, 1500000});

  ASSERT_TRUE(m1.EqMatrix(res));
}

// сложение матриц, заполненных различными числами 2
TEST(SuiteSumMatrix, SumMatrix5) {
  S21Matrix m1(test_matrix_3);
  S21Matrix m2(test_matrix_4);

  m1.SumMatrix(m2);

  S21Matrix res(2, 2, {0.000000002, 0.0000002, 8E20, 0.0});

  ASSERT_TRUE(m1.EqMatrix(res));
}

// ошибка, разные размеры матриц
TEST(SuiteSumMatrix, SumMatrixException) {
  S21Matrix m1(5, 8);
  S21Matrix m2(6, 6);

  ASSERT_THROW(m1.SumMatrix(m2), std::out_of_range);
}