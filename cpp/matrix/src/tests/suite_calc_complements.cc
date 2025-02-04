#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

// ошибка, нееквадратная матрица
TEST(SuiteCalcComplements, CalcComplementsException) {
  S21Matrix m1(3, 4);

  ASSERT_THROW(m1.CalcComplements(), std::out_of_range);
}

// матрица 1x1
TEST(SuiteCalcComplements, CalcComplements1) {
  S21Matrix m1(1, 1, {5.2});
  S21Matrix m2 = m1.CalcComplements();

  S21Matrix res(1, 1, {1});

  ASSERT_TRUE(m2.EqMatrix(res));
  ASSERT_NO_THROW(m1.CalcComplements());
}

// матрица 2x2
TEST(SuiteCalcComplements, CalcComplements2) {
  S21Matrix m1(2, 2, {4.1, 7, 2.2, -3});
  S21Matrix m2 = m1.CalcComplements();

  S21Matrix res(2, 2, {-3, -2.2, -7, 4.1});

  ASSERT_TRUE(m2.EqMatrix(res));
}

// матрица 3x3
TEST(SuiteCalcComplements, CalcComplements3) {
  S21Matrix m1(3, 3, {1, 2, 3, 0, 4, 2, 5, 2, 1});
  S21Matrix m2 = m1.CalcComplements();

  S21Matrix res(3, 3, {0, 10, -20, 4, -14, 8, -8, -2, 4});

  ASSERT_TRUE(m2.EqMatrix(res));
}

// матрица 5x5
TEST(SuiteCalcComplements, CalcComplements4) {
  S21Matrix m1(5, 5, {4, 7,  2, -4, 3, 2,  -3, 5, 12, 0,  34, -22, -22,
                      3, 17, 1, 5,  7, 14, 3,  1, 2,  12, 77, 13});
  S21Matrix m2 = m1.CalcComplements();

  S21Matrix res(5, 5, {-46070, -43665, 38165, -19140, 88400, -33630,  -20615,
                       16990,  -12615, 64795, 3665,   4885,  -3911,   2240,
                       -10691, 64020,  59945, -64965, 31385, -140075, -8935,
                       -10145, 11299,  -5755, 20379});

  ASSERT_TRUE(m2.EqMatrix(res));
}
