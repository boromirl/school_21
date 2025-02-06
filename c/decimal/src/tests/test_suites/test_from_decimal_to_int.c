#include "../s21_decimal_tests.h"

static s21_decimal input_data[] = {
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
    {{0x000000F4, 0x00000000, 0x00000000, 0x00030000}},  // 0.244
    {{0x00000086, 0x00000000, 0x00000000, 0x00010000}},  // 13.4
    {{0x000000C2, 0x00000000, 0x00000000, 0x00010000}},  // 19.4
    {{0x0000000D, 0x00000014, 0x00000000, 0x800A0000}},  // -8.5899345933
    {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF,
      0x00000000}},  // 79228162514264337593543950334
};

static int expected[] = {0,   1,    2,      3,         4,         -5,
                         255, 1024, 999999, 123456789, -123,      -13151315,
                         0,   13,   19,     -8,        0x7FFFFFFF};

START_TEST(test) {
  int temp, ret;
  for (size_t i = 0; i < sizeof(input_data) / sizeof(s21_decimal); ++i) {
    s21_from_decimal_to_int(input_data[i], &temp);
    ret = 0;
    if (expected[i] == temp) {
      ret = 1;
    }
    ck_assert_int_eq(ret, 1);
  }
}
END_TEST

Suite *suite_from_decimal_to_int(void) {
  Suite *suite = suite_create(MAGENTA "[s21_from_decimal_to_int]" RESET);
  TCase *tcase_core = tcase_create(RED "s21_from_decimal_to_int_tc" RESET);

  if (suite != NULL && tcase_core != NULL) {
    tcase_add_test(tcase_core, test);
    suite_add_tcase(suite, tcase_core);
  }
  return suite;
}
