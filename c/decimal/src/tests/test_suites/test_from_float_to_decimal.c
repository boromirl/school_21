#include "../s21_decimal_tests.h"

START_TEST(test_from_float_to_decimal_1) {
  s21_decimal val;
  s21_from_float_to_decimal(0.03F, &val);
  ck_assert_int_eq(val.bits[0], 3);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 131072);
  s21_from_float_to_decimal(127.1234F, &val);
  ck_assert_int_eq(val.bits[0], 1271234);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 262144);
}
END_TEST

START_TEST(test_from_float_to_decimal_2) {
  s21_decimal val;
  s21_from_float_to_decimal(22.14836E+03F, &val);
  ck_assert_int_eq(val.bits[0], 2214836);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 131072);
}
END_TEST

START_TEST(test_from_float_to_decimal_3) {
  s21_decimal val;
  s21_from_float_to_decimal(1.02E+09F, &val);
  ck_assert_int_eq(val.bits[0], 1020000000);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(test_from_float_to_decimal_4) {
  s21_decimal val;
  float a = 1.0F / 0.0F;
  int err_check = s21_from_float_to_decimal(a, &val);
  ck_assert_int_eq(err_check, 1);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(test_from_float_to_decimal_5) {
  s21_decimal val;
  s21_from_float_to_decimal(0.0F, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

Suite *suite_from_float_to_decimal(void) {
  Suite *s = suite_create(MAGENTA "[s21_from_float_to_decimal]" RESET);
  TCase *tc = tcase_create(RED "[s21_from_float_to_decimal_tc]" RESET);

  tcase_add_test(tc, test_from_float_to_decimal_1);
  tcase_add_test(tc, test_from_float_to_decimal_2);
  tcase_add_test(tc, test_from_float_to_decimal_3);
  tcase_add_test(tc, test_from_float_to_decimal_4);
  tcase_add_test(tc, test_from_float_to_decimal_5);

  suite_add_tcase(s, tc);
  return s;
}