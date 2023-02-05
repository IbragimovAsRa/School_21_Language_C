#include "../test_cases_s21_math.h"


START_TEST(tan_test_1) {
    ck_assert_ldouble_nan(s21_cos(max_inf)); }
END_TEST

START_TEST(tan_test_2) {
    ck_assert_ldouble_nan(s21_cos(min_inf)); }
END_TEST

START_TEST(tan_test_3) {
    ck_assert_ldouble_nan(s21_cos(max_nan)); }
END_TEST

START_TEST(tan_test_4) {
    ck_assert_ldouble_nan(s21_cos(min_nan)); }
END_TEST

START_TEST(tan_test_5) {
    ck_assert_ldouble_eq_tol(s21_tan(0.5), tan(0.5), 1e-6); }
END_TEST

START_TEST(tan_test_6) {
    ck_assert_ldouble_eq_tol(s21_tan(-0.5), tan(-0.5), 1e-6); }
END_TEST

START_TEST(tan_test_7) {
    ck_assert_ldouble_eq_tol(s21_tan(-1), tan(-1), 1e-6); }
END_TEST

START_TEST(tan_test_8) {
    ck_assert_ldouble_eq_tol(s21_tan(1), tan(1), 1e-6); }
END_TEST

START_TEST(tan_test_9) {
    ck_assert_ldouble_eq_tol(s21_tan(1.1), tan(1.1), 1e-6); }
END_TEST

START_TEST(tan_test_10) {
    ck_assert_ldouble_eq_tol(s21_tan(-2.1), tan(-2.1), 1e-6);}
END_TEST

START_TEST(tan_test_11) {
    ck_assert_ldouble_eq_tol(s21_tan(0), tan(0), 1e-6);}
END_TEST

START_TEST(tan_test_12) {
    ck_assert_ldouble_eq_tol(s21_tan(-0), tan(-0), 1e-6);}
END_TEST

START_TEST(tan_test_13) {
    ck_assert_ldouble_eq_tol(s21_tan(5.123456789123), tan(5.123456789123), 1e-6);}
END_TEST

START_TEST(tan_test_14) {
    ck_assert_ldouble_eq_tol(s21_tan(0.00000004564897), tan(0.00000004564897), 1e-6);}
END_TEST

START_TEST(tan_test_15) {
    ck_assert_ldouble_eq_tol(s21_tan(170), tan(170), 1e-6);}
END_TEST

START_TEST(tan_test_16) {
    ck_assert_ldouble_eq_tol(s21_tan(1234567), tan(1234567), 1e-6);}
END_TEST

START_TEST(tan_test_17) {
    ck_assert_ldouble_eq_tol(s21_tan(1000000), tan(1000000), 1e-6);}
END_TEST

START_TEST(tan_test_18) {
    ck_assert_ldouble_eq_tol(s21_tan(-12345), tan(-12345), 1e-6);}
END_TEST



Suite *get_suite_s21_tan() {
    Suite *s = suite_create("s21_tan suite ");
    TCase *tc = tcase_create("s21_tan test case");
    suite_add_tcase(s, tc);
    tcase_add_test(tc, tan_test_1);
    tcase_add_test(tc, tan_test_2);
    tcase_add_test(tc, tan_test_3);
    tcase_add_test(tc, tan_test_4);
    tcase_add_test(tc, tan_test_5);
    tcase_add_test(tc, tan_test_6);
    tcase_add_test(tc, tan_test_7);
    tcase_add_test(tc, tan_test_8);
    tcase_add_test(tc, tan_test_9);
    tcase_add_test(tc, tan_test_10);
    tcase_add_test(tc, tan_test_11);
    tcase_add_test(tc, tan_test_12);
    tcase_add_test(tc, tan_test_13);
    tcase_add_test(tc, tan_test_14);
    tcase_add_test(tc, tan_test_15);
    tcase_add_test(tc, tan_test_16);
    tcase_add_test(tc, tan_test_17);
    tcase_add_test(tc, tan_test_18);
    return s;
}