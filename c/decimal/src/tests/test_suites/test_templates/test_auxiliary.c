#include "../s21_decimal_tests.h"

static s21_decimal decimals[] = {
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 0
    {{0x00000000, 0x00000000, 0x00000000, 0x80000000}},  // -0
    {{0xffffffff, 0xffffffff, 0x00000000, 0x00000000}},  // 18446744073709551615
    {{0xffffffff, 0xffffffff, 0x00000000,
      0x80000000}},  // -18446744073709551615
    {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},  // 1
    {{0x00000001, 0x00000000, 0x00000000, 0x80000000}},  // -1
    {{0x0000000f, 0x00000000, 0x00000000, 0x00030000}},  // 0.015
    {{0xffffffff, 0xffffffff, 0x0fffffff,
      0x00000000}},  // 4951760157141521099596496895
    {{0xffffffff, 0xffffffff, 0x0fffffff,
      0x00140000}},  // 49517601.57141521099596496895
    {{0xffffffff, 0xffffffff, 0x0fffffff,
      0x00050000}}  // 49517601571415210995964.96895
};

static unsigned int multipliers[] = {10, 10, 10, 10, 10, 100, 3, 2, 4, 10};

static s21_decimal mult_bd_by_num_results[] = {
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 0
    {{0x00000000, 0x00000000, 0x00000000, 0x80000000}},  // -0
    {{0xfffffff6, 0xffffffff, 0x00000009,
      0x00000000}},  // 184467440737095516150
    {{0xfffffff6, 0xffffffff, 0x00000009,
      0x80000000}},  // -184467440737095516150
    {{0x0000000a, 0x00000000, 0x00000000, 0x00000000}},  // 10
    {{0x00000064, 0x00000000, 0x00000000, 0x80000000}},  // -100
    {{0x0000002d, 0x00000000, 0x00000000, 0x00030000}}   // 0.045
};

static unsigned int dividers[] = {10, 10, 10, 10, 1, 10, 3};

static s21_decimal div_bd_by_num_results[] = {
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 0
    {{0x00000000, 0x00000000, 0x00000000, 0x80000000}},  // -0
    {{0x99999999, 0x19999999, 0x00000000, 0x00000000}},  // 1844674407370955161
    {{0x99999999, 0x19999999, 0x00000000, 0x80000000}},  // -1844674407370955161
    {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},  // 1
    {{0x00000000, 0x00000000, 0x00000000, 0x80000000}},  // 0
    {{0x00000005, 0x00000000, 0x00000000, 0x00030000}}   // 0.005
};

START_TEST(mult_big_decimal_by_number_test_1) {
  for (size_t i = 0; i < sizeof(mult_bd_by_num_results) / sizeof(s21_decimal);
       i++) {
    s21_big_decimal big_decimal;
    s21_decimal decimal = decimals[i];
    decimal_to_big(decimal, &big_decimal);
    mult_big_decimal_by_number(&big_decimal, multipliers[i]);
    big_to_decimal(big_decimal, &decimal);

    ck_assert_uint_eq(decimal.bits[0], mult_bd_by_num_results[i].bits[0]);
    ck_assert_uint_eq(decimal.bits[1], mult_bd_by_num_results[i].bits[1]);
    ck_assert_uint_eq(decimal.bits[2], mult_bd_by_num_results[i].bits[2]);
    ck_assert_uint_eq(decimal.bits[3], mult_bd_by_num_results[i].bits[3]);
  }
}
END_TEST

START_TEST(div_big_decimal_by_number_test_1) {
  for (size_t i = 0; i < sizeof(mult_bd_by_num_results) / sizeof(s21_decimal);
       i++) {
    s21_big_decimal big_decimal;
    s21_decimal decimal = decimals[i];
    decimal_to_big(decimal, &big_decimal);
    div_big_decimal_by_number(&big_decimal, dividers[i]);
    big_to_decimal(big_decimal, &decimal);

    ck_assert_uint_eq(decimal.bits[0], div_bd_by_num_results[i].bits[0]);
    ck_assert_uint_eq(decimal.bits[1], div_bd_by_num_results[i].bits[1]);
    ck_assert_uint_eq(decimal.bits[2], div_bd_by_num_results[i].bits[2]);
    ck_assert_uint_eq(decimal.bits[3], div_bd_by_num_results[i].bits[3]);
  }
}
END_TEST

Suite *suite_auxiliary(void) {
  Suite *suite = suite_create(MAGENTA "[s21_auxiliary_functions]" RESET);
  TCase *tcase_core = tcase_create(RED "s21_auixiliary_functions_tc" RESET);

  tcase_add_test(tcase_core, mult_big_decimal_by_number_test_1);
  tcase_add_test(tcase_core, div_big_decimal_by_number_test_1);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
