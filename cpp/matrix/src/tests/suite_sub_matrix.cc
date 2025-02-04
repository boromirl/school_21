#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

static S21Matrix test_matrix_1(5, 5, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
static S21Matrix test_matrix_2(5, 5,
                               {5.2, 5.2, 5.2, 5.2, 5.2, 5.2, 5.2, 5.2, 5.2,
                                5.2, 5.2, 5.2, 5.2, 5.2, 5.2, 5.2, 5.2, 5.2,
                                5.2, 5.2, 5.2, 5.2, 5.2, 5.2, 5.2});
static S21Matrix test_matrix_3(5, 5, {-5.2, -5.2, -5.2, -5.2, -5.2, -5.2, -5.2,
                                      -5.2, -5.2, -5.2, -5.2, -5.2, -5.2, -5.2,
                                      -5.2, -5.2, -5.2, -5.2, -5.2, -5.2, -5.2,
                                      -5.2, -5.2, -5.2, -5.2});
static S21Matrix test_matrix_4(3, 4,
                               {-100.0, -245.3, 0.00001, 54.32, 0.3, -0.0003,
                                90, 65.2, 81, 100, -0.00001, 500000});
static S21Matrix test_matrix_5(3, 4,
                               {17, 3, -0.00001, 4.2, 140, -0.0003, 20.45, 30.3,
                                -300.14, 100, 0.00001, 1000000});

static S21Matrix test_matrix_6(2, 2, {0.000000001, 0.0000001, 5E20, 0.0000001});
static S21Matrix test_matrix_7(2, 2,
                               {-0.000000001, -0.0000001, 3E20, 0.0000001});

// ошибка, разные размеры матриц
TEST(SuiteSubMatrix, SubMatrixException) {
  S21Matrix m1(5, 8);
  S21Matrix m2(6, 6);

  ASSERT_THROW(m1.SubMatrix(m2), std::out_of_range);
}

// вычитание зануленных матриц
TEST(SuiteSubMatrix, SubMatrix1) {
  S21Matrix m1(5, 5);
  S21Matrix m2(5, 5);

  m1.SubMatrix(m2);

  ASSERT_TRUE(m1.EqMatrix(test_matrix_1));
}

// вычитание нулевой матрицы из ненулевой
TEST(SuiteSubMatrix, SubMatrix2) {
  S21Matrix m1(test_matrix_1);
  S21Matrix m2(test_matrix_2);

  m2.SubMatrix(m1);

  ASSERT_TRUE(m2.EqMatrix(test_matrix_2));
}

// вычитание матрицы из самой себя
TEST(SuiteSubMatrix, SubMatrix3) {
  S21Matrix m1(test_matrix_2);

  m1.SubMatrix(m1);

  S21Matrix res(5, 5);

  ASSERT_TRUE(m1.EqMatrix(res));
}

// вычитание обратных матриц
TEST(SuiteSubMatrix, SubMatrix4) {
  S21Matrix m1(test_matrix_2);
  S21Matrix m2(test_matrix_3);

  m1.SubMatrix(m2);

  S21Matrix res(5, 5, {10.4, 10.4, 10.4, 10.4, 10.4, 10.4, 10.4, 10.4, 10.4,
                       10.4, 10.4, 10.4, 10.4, 10.4, 10.4, 10.4, 10.4, 10.4,
                       10.4, 10.4, 10.4, 10.4, 10.4, 10.4, 10.4});

  ASSERT_TRUE(m1.EqMatrix(res));
}

// вычитание матриц, заполненных различными значениями 1
TEST(SuiteSubMatrix, SubMatrix5) {
  S21Matrix m1(test_matrix_4);
  S21Matrix m2(test_matrix_5);

  m1.SubMatrix(m2);

  S21Matrix res(3, 4,
                {-117, -248.3, 0.00002, 50.12, -139.7, 0.0, 69.55, 34.9, 381.14,
                 0.0, -0.00002, -500000});
  ASSERT_TRUE(m1.EqMatrix(res));
}

// вычитание матриц, заполненных различными значениями 2
TEST(SuiteSubMatrix, SubMatrix6) {
  S21Matrix m1(test_matrix_6);
  S21Matrix m2(test_matrix_7);

  m1.SubMatrix(m2);

  S21Matrix res(2, 2, {0.000000002, 0.0000002, 2E20, 0.0});

  ASSERT_TRUE(m1.EqMatrix(res));
}