#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

TEST(SuiteOperators, PlusOperator) {
  S21Matrix m1(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
  S21Matrix m2(3, 3, {2, 2, 2, 2, 2, 2, 3, 2, 3});

  S21Matrix m3 = m1 + m2;

  m1.SumMatrix(m2);

  ASSERT_TRUE(m1.EqMatrix(m3));
}

TEST(SuiteOperators, PlusEqualOperator) {
  S21Matrix m1(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
  S21Matrix m2(3, 3, {2, 2, 2, 2, 2, 2, 3, 2, 3});

  S21Matrix m3(m1);

  m1.SumMatrix(m2);
  m3 += m2;

  ASSERT_TRUE(m1.EqMatrix(m3));
}

TEST(SuiteOperators, PlusOperatorException) {
  S21Matrix m1(3, 4, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
  S21Matrix m2(3, 3, {2, 2, 2, 2, 2, 2, 3, 2, 3});

  ASSERT_THROW(m1 + m2, std::out_of_range);
}

TEST(SuiteOperators, PlusEqualOperatorException) {
  S21Matrix m1(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
  S21Matrix m2(2, 2, {2, 2, 2, 2});

  ASSERT_THROW(m1 += m2, std::out_of_range);
}

TEST(SuiteOperators, MinusOperator) {
  S21Matrix m1(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
  S21Matrix m2(3, 3, {2, 2, 2, 2, 2, 2, 3, 2, 3});

  S21Matrix m3 = m1 - m2;

  m1.SubMatrix(m2);

  ASSERT_TRUE(m1.EqMatrix(m3));
}

TEST(SuiteOperators, MinusEqualOperator) {
  S21Matrix m1(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
  S21Matrix m2(3, 3, {2, 2, 2, 2, 2, 2, 3, 2, 3});

  S21Matrix m3(m1);

  m1.SubMatrix(m2);
  m3 -= m2;

  ASSERT_TRUE(m1.EqMatrix(m3));
}

TEST(SuiteOperators, MinusOperatorException) {
  S21Matrix m1(3, 4, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
  S21Matrix m2(3, 3, {2, 2, 2, 2, 2, 2, 3, 2, 3});

  ASSERT_THROW(m1 - m2, std::out_of_range);
}

TEST(SuiteOperators, MinusEqualOperatorException) {
  S21Matrix m1(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
  S21Matrix m2(2, 2, {2, 2, 2, 2});

  ASSERT_THROW(m1 -= m2, std::out_of_range);
}

TEST(SuiteOperators, DoubleEqualSign) {
  S21Matrix m1(3, 4, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
  S21Matrix m2(3, 3, {2, 2, 2, 2, 2, 2, 3, 2, 3});
  S21Matrix m3(3, 4, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});

  ASSERT_EQ(m1 == m2, m1.EqMatrix(m2));
  ASSERT_EQ(m1 == m3, m1.EqMatrix(m3));
}

TEST(SuiteOperators, SingleEqualSign) {
  S21Matrix m1(4, 4, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16});
  S21Matrix m2(3, 3, {2, 2, 2, 2, 2, 2, 3, 2, 3});

  m2 = m1;

  ASSERT_EQ(m2.GetRows(), 4);
  ASSERT_EQ(m2.GetCols(), 4);
  ASSERT_TRUE(m2.EqMatrix(m1));
}

TEST(SuiteOperators, MulMatrixByMatrix) {
  S21Matrix m1(4, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
  S21Matrix m2(3, 3, {2, 2, 2, 2, 2, 2, 3, 2, 3});

  S21Matrix m3 = m1 * m2;

  m1.MulMatrix(m2);

  ASSERT_TRUE(m1.EqMatrix(m3));
}

TEST(SuiteOperators, MulMatrixByMatrixException) {
  S21Matrix m1(3, 4, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
  S21Matrix m2(2, 2, {5, 5, 5, 5});

  ASSERT_THROW(m1 * m2, std::out_of_range);
}

TEST(SuiteOperators, MulMatrixByMatrixAndEqual) {
  S21Matrix m1(4, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
  S21Matrix m2(3, 3, {2, 2, 2, 2, 2, 2, 3, 2, 3});

  S21Matrix m3(m1);

  m1.MulMatrix(m2);

  m3 *= m2;

  ASSERT_TRUE(m1.EqMatrix(m3));
}

TEST(SuiteOperators, MulMatrixByMatrixAndEqualException) {
  S21Matrix m1(3, 4, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
  S21Matrix m2(2, 2, {3, 4, 5, 2});

  ASSERT_THROW(m1 *= m2, std::out_of_range);
}

TEST(SuiteOperators, MulMatrixByNum) {
  S21Matrix m1(3, 4, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
  double num = 4.2;

  S21Matrix m2 = m1 * num;
  S21Matrix m3 = num * m1;
  m1.MulNumber(num);

  ASSERT_TRUE(m1.EqMatrix(m2));
  ASSERT_TRUE(m1.EqMatrix(m3));
}

TEST(SuiteOperators, MulMatrixByNumAndEqual) {
  S21Matrix m1(3, 4, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
  double num = 4.2;

  S21Matrix m2(m1);

  m2 *= num;
  m1.MulNumber(num);

  ASSERT_TRUE(m1.EqMatrix(m2));
}

TEST(SuiteOperators, GetValue) {
  const S21Matrix m1(3, 4, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});

  double val_1 = m1(0, 0);
  double val_2 = m1(2, 3);
  ASSERT_EQ(val_1, 1);
  ASSERT_EQ(val_2, 12);
}

TEST(SuiteOperators, GetValueException) {
  const S21Matrix m1(3, 4, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
  ASSERT_THROW(m1(5, 5), std::out_of_range);
}

TEST(SuiteOperators, SetValue) {
  S21Matrix m1(3, 4, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});

  m1(0, 0) = 4.2;
  m1(2, 3) = -0.3;

  ASSERT_EQ(m1(0, 0), 4.2);
  ASSERT_EQ(m1(2, 3), -0.3);
}

TEST(SuiteOperators, SetValueException) {
  S21Matrix m1(3, 4, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});

  ASSERT_THROW(m1(5, 5) = 3, std::out_of_range);
}