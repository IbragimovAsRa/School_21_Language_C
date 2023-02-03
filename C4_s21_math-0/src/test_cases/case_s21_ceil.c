#include "../test_cases_s21_math.h"


START_TEST(ceil_test_1) {
    ck_assert_ldouble_eq(s21_ceil(max_inf), ceil(max_inf));
}

END_TEST

START_TEST(ceil_test_2) {
    ck_assert_ldouble_eq(s21_ceil(min_inf), ceil(min_inf));
}

END_TEST

START_TEST(ceil_test_3) {
    ck_assert_ldouble_nan(s21_ceil(max_nan));
}

END_TEST

START_TEST(ceil_test_4) {
    ck_assert_ldouble_nan(s21_ceil(min_nan));
}

END_TEST

START_TEST(ceil_test_5) {
    ck_assert_ldouble_eq(s21_ceil(-876554310.23455), ceil(-876554310.23455));
}
END_TEST

START_TEST(ceil_test_6) {
    ck_assert_ldouble_eq(s21_ceil(876554310.23455), ceil(876554310.23455));
}

END_TEST

START_TEST(ceil_test_7) {
    ck_assert_ldouble_eq(s21_ceil(0.45), ceil(0.45));
}

END_TEST

START_TEST(ceil_test_8) {
    ck_assert_ldouble_eq(s21_ceil(-0.00000000000000045),
                         ceil(-0.00000000000000045));
}

END_TEST


Suite *get_suite_s21_ceil() {
    Suite *s = suite_create("s21_ceil suite ");
    TCase *tc = tcase_create("s21_ceil test case");
    suite_add_tcase(s, tc);


    tcase_add_test(tc, ceil_test_1);
    tcase_add_test(tc, ceil_test_2);
    tcase_add_test(tc, ceil_test_3);
    tcase_add_test(tc, ceil_test_4);
    tcase_add_test(tc, ceil_test_5);
    tcase_add_test(tc, ceil_test_6);
    tcase_add_test(tc, ceil_test_7);
    tcase_add_test(tc, ceil_test_8);

    return s;
}