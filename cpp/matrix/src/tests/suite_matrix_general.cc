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

// default constructor
TEST(SuiteMatrixGeneral, DefaultConstructor) {
  S21Matrix m1;

  ASSERT_EQ(m1.GetRows(), 3);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ASSERT_EQ(m1(i, j), 0);
    }
  }
}

// parameter constructor
TEST(SuiteMatrixGeneral, ParameterConstructor) {
  S21Matrix m1(10, 5);

  ASSERT_EQ(m1.GetRows(), 10);
  ASSERT_EQ(m1.GetCols(), 5);

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 5; j++) {
      ASSERT_EQ(m1(i, j), 0);
    }
  }
}

// parameter constructor, incorrect pframeters
TEST(SuiteMatrixGeneral, ParameterConstructorException) {
  ASSERT_THROW(S21Matrix m1(10, -2), std::invalid_argument);
  ASSERT_THROW(S21Matrix m1(0, 2), std::invalid_argument);
}

// copy constructor
TEST(SuiteMatrixGeneral, CopyConstructor) {
  S21Matrix m1(test_matrix_6);
  ASSERT_TRUE(m1.EqMatrix(test_matrix_6));
}

// move constructor
TEST(SuiteMatrixGeneral, MoveConstructor) {
  S21Matrix m1(test_matrix_6);
  S21Matrix m2 = std::move(m1);
  ASSERT_TRUE(m2.EqMatrix(test_matrix_6));

  ASSERT_EQ(m1.GetRows(), 0);
  ASSERT_EQ(m1.GetCols(), 0);
}

// init_list constructor
TEST(SuiteMatrixGeneral, InitListConstructor) {
  S21Matrix m1(2, 3, {1, 2, 3, 4, 5, 6});
  ASSERT_EQ(m1.GetRows(), 2);
  ASSERT_EQ(m1.GetCols(), 3);

  ASSERT_EQ(m1(0, 0), 1);
  ASSERT_EQ(m1(0, 1), 2);
  ASSERT_EQ(m1(0, 2), 3);
  ASSERT_EQ(m1(1, 0), 4);
  ASSERT_EQ(m1(1, 1), 5);
  ASSERT_EQ(m1(1, 2), 6);
}

// init_list constructor, incorrect list
TEST(SuiteMatrixGeneral, InitListConstructorException) {
  ASSERT_THROW(S21Matrix m1(0, 3, {1, 2, 3, 4, 5, 6}), std::invalid_argument);
  ASSERT_THROW(S21Matrix m1(1, 3, {1, 2, 3, 4, 5, 6}), std::invalid_argument);
}

// rows mutator
TEST(SuiteMatrixGeneral, SetRows) {
  S21Matrix m1(test_matrix_3);
  m1.SetRows(5);

  ASSERT_EQ(m1.GetRows(), 5);
  ASSERT_EQ(m1.GetCols(), 2);
  ASSERT_EQ(m1(4, 1), 0);
}

// rows mutator, incorrect number of rows
TEST(SuiteMatrixGeneral, SetRowsException) {
  S21Matrix m1(test_matrix_3);

  ASSERT_THROW(m1.SetRows(0), std::invalid_argument);
}

// cols mutator
TEST(SuiteMatrixGeneral, SetCols) {
  S21Matrix m1(test_matrix_3);
  m1.SetCols(6);

  ASSERT_EQ(m1.GetRows(), 2);
  ASSERT_EQ(m1.GetCols(), 6);
  ASSERT_EQ(m1(1, 5), 0);
}

// cols mutator, incorrect number of cols
TEST(SuiteMatrixGeneral, SetColsException) {
  S21Matrix m1(test_matrix_3);

  ASSERT_THROW(m1.SetCols(0), std::invalid_argument);
}

// copy of matrix (not copy constructor)
TEST(suiteMatrixGeneral, CopyMatrix) {
  S21Matrix m1(test_matrix_6);

  S21Matrix m2;
  ASSERT_FALSE(m1.EqMatrix(m2));

  m2.CopyMatrix(m1);
  ASSERT_TRUE(m1.EqMatrix(m2));
}