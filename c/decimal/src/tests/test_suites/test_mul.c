#include "../s21_decimal_tests.h"

static s21_decimal num1[] = {
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // i= 0: 0
    {{0x00000000, 0x00000000, 0x00000000, 0x00030000}},  // i= 1: 0.000
    {{0x0000000F, 0x00000000, 0x00000000, 0x00010000}},  // i= 2: 1.5
    {{0x00000001, 0x00000000, 0x00000000,
      0x000F0000}},  // i= 3: 0.000000000000001
    {{0xC4D5AAEC, 0x00000025, 0x00000000, 0x00060000}},  // i= 4: 162216.127212
    {{0x74489B46, 0x11C6B4C4, 0x00000000,
      0x00050000}},  // i= 5: 12809098998909.89894
    {{0xA4C194B9, 0xDF05E1A3, 0x000786BE,
      0x00050000}},  // i= 6: 90987987978798797979.37337
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x80000000}},  // i= 7: -79228162514264337593543950335
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x00000000}},  // i= 8: 79228162514264337593543950335
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x00000000}},  // i= 9: 79228162514264337593543950335
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x00000000}},  // i=10: 79228162514264337593543950335
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x000F0000}},  // i=11: 79228162514264.337593543950335
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x80180000}},  // i=12: -79228.162514264337593543950335
    {{0x0098967F, 0x00000000, 0x00000000, 0x00070000}},  // i=13: 0.9999999
    {{0x0000036C, 0x00000000, 0x00000000,
      0x00110000}},  // i=14: 0.00000000000000876
    {{0x6C47741F, 0x00000007, 0x00000000,
      0x801C0000}},  // i=15: -0.0000000000000000031881393183
    {{0x3B97BBCF, 0x00000000, 0x00000000,
      0x001C0000}},  // i=16: 0.0000000000000000000999799759
};

static s21_decimal num2[] = {
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // i= 0: 0
    {{0x00000000, 0x00000000, 0x00000000, 0x80050000}},  // i= 1: 0.00000
    {{0x00000002, 0x00000000, 0x00000000, 0x00000000}},  // i= 2: 2
    {{0x540BE400, 0x00000002, 0x00000000, 0x00000000}},  // i= 3: 10000000000
    {{0x0000033B, 0x00000000, 0x00000000, 0x00040000}},  // i= 4: 0.0827
    {{0x0005C187, 0x00000000, 0x00000000,
      0x000F0000}},  // i= 5: 0.000000000377223
    {{0x000003DD, 0x00000000, 0x00000000, 0x00000000}},  // i= 6: 989
    {{0x00000001, 0x00000000, 0x00000000, 0x80000000}},  // i= 7: -1
    {{0x00000005, 0x00000000, 0x00000000, 0x00010000}},  // i= 8: 0.5
    {{0x00000159, 0x00000000, 0x00000000, 0x00040000}},  // i= 9: 0.0345
    {{0x04000001, 0xC308736A, 0x02E87669,
      0x001B0000}},  // i=10: 0.900000000000000000000000001
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x800F0000}},  // i=11: -79228162514264.337593543950335
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x00180000}},  // i=12: 79228.162514264337593543950335
    {{0x0D01C1BA, 0x00000000, 0x00000000, 0x00010000}},  // i=13: 21821893.8
    {{0x3E41371C, 0x01632A10, 0x00000000,
      0x80040000}},  // i=14: -9996986598458.7548
    {{0xF8CF2CDA, 0x0000001F, 0x00000000,
      0x00150000}},  // i=15: 0.000000000137318313178
    {{0xF8CF2CDA, 0x0000001F, 0x00000000,
      0x00150000}},  // i=16: 0.000000000137318313178
};

static s21_decimal result[] = {
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // i= 0: 0
    {{0x00000000, 0x00000000, 0x00000000, 0x00080000}},  // i= 1: 0.00000000
    {{0x0000001E, 0x00000000, 0x00000000, 0x00010000}},  // i= 2: 3.0
    {{0x540BE400, 0x00000002, 0x00000000,
      0x000F0000}},  // i= 3: 0.000010000000000
    {{0xDE3F2864, 0x00007A02, 0x00000000,
      0x000A0000}},  // i= 4: 13415.2737204324
    {{0x17B7A7EA, 0xB5E7B4AF, 0x00006651,
      0x00140000}},  // i= 5: 4831.88675166578880784362
    {{0x7FDB8EB5, 0x99B8B533, 0x1D138F63,
      0x00050000}},  // i= 6: 89987120111032011201600.26293
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x00000000}},  // i= 7: 79228162514264337593543950335
    {{0x00000000, 0x00000000, 0x80000000,
      0x00000000}},  // i= 8: 39614081257132168796771975168
    {{0x851EB852, 0x1EB851EB, 0x5851EB85,
      0x00010000}},  // i= 9: 2733371606742119646977266286.6
    {{0x666666B5, 0x66666666, 0xE6666666,
      0x00000000}},  // i=10: 71305346262837903834189555381
    {{0x096EE456, 0x359A3B3E, 0xCAD2F7F5,
      0x80010000}},  // i=11: -6277101735386680763835789423.0
    {{0x096EE456, 0x359A3B3E, 0xCAD2F7F5,
      0x80130000}},  // i=12: -6277101735.3866807638357894230
    {{0x81D21746, 0x0007C0B0, 0x00000000,
      0x00080000}},  // i=13: 21821891.61781062
    {{0x072893D0, 0xBF53EF95, 0x00000004,
      0x80150000}},  // i=14: -0.087573602602498692048
    {{0x00000004, 0x00000000, 0x00000000,
      0x801C0000}},  // i=15: -0.0000000000000000000000000004
    {{0x00000000, 0x00000000, 0x00000000,
      0x001C0000}},  // i=16: 0.0000000000000000000000000000
};

static s21_decimal err_num1[] = {
    {{0x00000010, 0x00000000, 0x00000000, 0x80010000}},  // -1.6
    {{0x00000069, 0x00000000, 0x00000000, 0x00010000}},  // 10.5
    {{0x0000000B, 0x00000000, 0x00000000, 0x80010000}},  // -1.1
    {{0x0000006A, 0x00000000, 0x00000000, 0x00010000}},  // 10.6
};

static s21_decimal err_num2[] = {
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x00000000}},  // 79228162514264337593543950335
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x00000000}},  // 79228162514264337593543950335
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x80000000}},  //-79228162514264337593543950335
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x80000000}},  //-79228162514264337593543950335
};

static int err_result[] = {
    2,
    1,
    1,
    2,
};

START_TEST(test) {
  for (size_t i = 0; i < sizeof(num1) / sizeof(s21_decimal); ++i) {
    s21_decimal tmp;
    int ret = s21_mul(num1[i], num2[i], &tmp);
    ck_assert_int_eq(tmp.bits[0], result[i].bits[0]);
    ck_assert_int_eq(tmp.bits[1], result[i].bits[1]);
    ck_assert_int_eq(tmp.bits[2], result[i].bits[2]);
    ck_assert_int_eq(tmp.bits[3], result[i].bits[3]);
    ck_assert_int_eq(ret, 0);
  }
}
END_TEST

START_TEST(error_test) {
  for (size_t i = 0; i < sizeof(err_num1) / sizeof(s21_decimal); ++i) {
    s21_decimal tmp;
    int ret = s21_mul(err_num1[i], err_num2[i], &tmp);
    if (tmp.bits[0] == 0) {
      tmp.bits[0] = 1;
    }
    ck_assert_int_eq(ret, err_result[i]);
  }
}
END_TEST

Suite *suite_mul(void) {
  Suite *suite = suite_create(MAGENTA "[s21_mul]" RESET);
  TCase *tcase_core = tcase_create(RED "s21_mul_tc" RESET);

  if (suite != NULL && tcase_core != NULL) {
    tcase_add_test(tcase_core, test);
    tcase_add_test(tcase_core, error_test);
    suite_add_tcase(suite, tcase_core);
  }
  return suite;
}