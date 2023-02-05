#include "../test_cases_s21_math.h"


START_TEST(acos_test_1) {
    ck_assert_ldouble_nan(s21_asin(max_inf));
}
END_TEST

START_TEST(acos_test_2) {
    ck_assert_ldouble_nan(s21_asin(min_inf));
}

END_TEST

START_TEST(acos_test_3) {
    ck_assert_ldouble_nan(s21_asin(max_nan));
}

END_TEST

START_TEST(acos_test_4) {
    ck_assert_ldouble_nan(s21_asin(min_nan));
}

END_TEST

START_TEST(acos_test_5) {
    ck_assert_ldouble_eq_tol(s21_asin(0.5), asin(0.5), 1e-6);
}

END_TEST

START_TEST(acos_test_6) {
    ck_assert_ldouble_eq_tol(s21_asin(-0.5), asin(-0.5), 1e-6);
}

END_TEST

START_TEST(acos_test_7) {
    ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), 1e-6);
}

END_TEST

START_TEST(acos_test_8) {
    ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), 1e-6);
}

END_TEST

START_TEST(acos_test_9) {
    ck_assert_ldouble_nan(s21_asin(1.1));
}

END_TEST
START_TEST(acos_test_10) {
    ck_assert_ldouble_eq_tol(s21_asin(0), asin(0), 1e-6);
}

END_TEST

START_TEST(acos_test_11) {
    ck_assert_ldouble_eq_tol(s21_asin(-0), asin(-0), 1e-6);
}

END_TEST

START_TEST(acos_test_12) {
    ck_assert_ldouble_eq_tol(s21_asin(0.00000004564897), asin(0.00000004564897), 1e-6);
}

END_TEST

START_TEST(acos_test_13) {
    ck_assert_ldouble_eq_tol(s21_asin(0.15), asin(0.15), 1e-6);
}

END_TEST

START_TEST(acos_test_14) {
    ck_assert_ldouble_eq_tol(s21_asin(-0.666), asin(-0.666), 1e-6);
}

END_TEST

START_TEST(acos_test_15) {
    ck_assert_ldouble_eq_tol(s21_asin(0.04564897), asin(0.04564897), 1e-6);
}

END_TEST

START_TEST(acos_test_16) {
    ck_assert_ldouble_nan(s21_acos(12345));}


END_TEST


Suite *get_suite_s21_acos() {
    Suite *s = suite_create("s21_acos suite ");
    TCase *tc = tcase_create("s21_acos test case");
    suite_add_tcase(s, tc);


    tcase_add_test(tc, acos_test_1);
    tcase_add_test(tc, acos_test_2);
    tcase_add_test(tc, acos_test_3);
    tcase_add_test(tc, acos_test_4);
    tcase_add_test(tc, acos_test_5);
    tcase_add_test(tc, acos_test_6);
    tcase_add_test(tc, acos_test_7);
    tcase_add_test(tc, acos_test_8);
    tcase_add_test(tc, acos_test_9);
    tcase_add_test(tc, acos_test_10);
    tcase_add_test(tc, acos_test_11);
    tcase_add_test(tc, acos_test_12);
    tcase_add_test(tc, acos_test_13);
    tcase_add_test(tc, acos_test_14);
    tcase_add_test(tc, acos_test_15);
    tcase_add_test(tc, acos_test_16);

    return s;
}