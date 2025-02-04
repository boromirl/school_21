#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

static S21Matrix test_matrix_1(1, 1, {0});
static S21Matrix test_matrix_2(5, 5, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
static S21Matrix test_matrix_3(2, 2, {1, 2, 3, 4});
static S21Matrix test_matrix_4(1, 1, {-5.2});
static S21Matrix test_matrix_5(5, 5, {-5.2, -5.2, -5.2, -5.2, -5.2, -5.2, -5.2,
                                      -5.2, -5.2, -5.2, -5.2, -5.2, -5.2, -5.2,
                                      -5.2, -5.2, -5.2, -5.2, -5.2, -5.2, -5.2,
                                      -5.2, -5.2, -5.2, -5.2});
static S21Matrix test_matrix_6(4, 4,
                               {1, 3, 4, 5, 9, 11, 3, 8, -2.4, 52, 0.556, 18,
                                10002, -0, 7, 2});
static S21Matrix test_matrix_7(4, 4,
                               {2, 5, 7, 9, 6, 8, 1, 3, 4, 2, 0, 7, 1, 3, 2,
                                4});
static S21Matrix test_matrix_8(4, 4,
                               {2, 5, 7, 9, 6, 8, 1, 3, 4, 2, 0, 7, 1, 3, 2,
                                4});

// матрица равна сама себе
TEST(SuiteEqMatrix, EqTest1) {
  S21Matrix m1(test_matrix_7);
  ASSERT_TRUE(m1.EqMatrix(m1));
}

// одинаковые заполненные матрицы
TEST(SuiteEqMatrix, EqTest2) {
  S21Matrix m1(test_matrix_7);
  S21Matrix m2(test_matrix_8);
  ASSERT_TRUE(m1.EqMatrix(m2));
}

// матрицы, отличающиеся размером
TEST(SuiteEqMatrix, EqTest3) {
  S21Matrix m1(test_matrix_1);
  S21Matrix m2(test_matrix_2);
  ASSERT_FALSE(m1.EqMatrix(m2));
}

// матрицы одинакового размера, заполненные разными числами 1
TEST(SuiteEqMatrix, EqTest4) {
  S21Matrix m1(test_matrix_2);
  S21Matrix m2(test_matrix_5);
  ASSERT_FALSE(m1.EqMatrix(m2));
}

// матрицы одинакового размера, заполненные разными числами 2
TEST(SuiteEqMatrix, EqTest5) {
  S21Matrix m1(test_matrix_6);
  S21Matrix m2(test_matrix_7);
  ASSERT_FALSE(m1.EqMatrix(m2));
}
