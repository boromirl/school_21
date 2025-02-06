#include "../s21_decimal_tests.h"

static int input_data[] = {0,   1,    2,      3,         4,    -5,
                           255, 1024, 999999, 123456789, -123, -13151315};

static s21_decimal expected[] = {
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 0
    {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},  // 1
    {{0x00000002, 0x00000000, 0x00000000, 0x00000000}},  // 2
    {{0x00000003, 0x00000000, 0x00000000, 0x00000000}},  // 3
    {{0x00000004, 0x00000000, 0x00000000, 0x00000000}},  // 4
    {{0x00000005, 0x00000000, 0x00000000, 0x80000000}},  // -5
    {{0x000000FF, 0x00000000, 0x00000000, 0x00000000}},  // 255
    {{0x00000400, 0x00000000, 0x00000000, 0x00000000}},  // 1024
    {{0x000F423F, 0x00000000, 0x00000000, 0x00000000}},  // 999999
    {{0x075BCD15, 0x00000000, 0x00000000, 0x00000000}},  // 123456789
    {{0x0000007B, 0x00000000, 0x00000000, 0x80000000}},  // -123
    {{0x00C8AC53, 0x00000000, 0x00000000, 0x80000000}},  // -13151315
};

START_TEST(test) {
  s21_decimal temp;
  for (size_t i = 0; i < sizeof(input_data) / sizeof(int); ++i) {
    s21_from_int_to_decimal(input_data[i], &temp);
    int ret = s21_is_equal(temp, expected[i]);
    ck_assert_int_eq(ret, 1);
  }
}
END_TEST

Suite *suite_from_int_to_decimal(void) {
  Suite *suite = suite_create(MAGENTA "[s21_from_int_to_decimal]" RESET);
  TCase *tcase_core = tcase_create(RED "s21_from_int_to_decimal_tc" RESET);

  if (suite != NULL && tcase_core != NULL) {
    tcase_add_test(tcase_core, test);
    suite_add_tcase(suite, tcase_core);
  }
  return suite;
}
