
#include "../test_cases_s21_math.h"


START_TEST(atan_test_1) {
        ck_assert_ldouble_nan(s21_atan(max_nan));}
END_TEST

START_TEST(atan_test_2) {
    ck_assert_ldouble_nan(s21_atan(min_nan));}
END_TEST

START_TEST(atan_test_3) {
    ck_assert_ldouble_eq_tol(s21_atan(min_inf), atan(min_inf), 1e-6);}
END_TEST

START_TEST(atan_test_4) {
    ck_assert_ldouble_eq_tol(s21_atan(max_inf), atan(max_inf), 1e-6);}
END_TEST

START_TEST(atan_test_5) {
    ck_assert_ldouble_eq_tol(s21_atan(0.5), atan(0.5), 1e-6);}
END_TEST

START_TEST(atan_test_6) {
    ck_assert_ldouble_eq_tol(s21_atan(-0.5), atan(-0.5), 1e-6);}
END_TEST

START_TEST(atan_test_7) {
    ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), 1e-6);}
END_TEST

START_TEST(atan_test_8) {
    ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), 1e-6);}
END_TEST

START_TEST(atan_test_9) {
    ck_assert_ldouble_eq_tol(s21_atan(1.1), atan(1.1), 1e-6);}
END_TEST

START_TEST(atan_test_10) {
    ck_assert_ldouble_eq_tol(s21_atan(-2.1), atan(-2.1), 1e-6);}
END_TEST

START_TEST(atan_test_11) {
    ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), 1e-6);}
END_TEST

START_TEST(atan_test_12) {
    ck_assert_ldouble_eq_tol(s21_atan(-0), atan(-0), 1e-6);}
END_TEST

START_TEST(atan_test_13) {
    ck_assert_ldouble_eq_tol(s21_atan(5.123456789123), atan(5.123456789123),1e-6);}
END_TEST

START_TEST(atan_test_14) {
    ck_assert_ldouble_eq_tol(s21_atan(0.00000004564897), atan(0.00000004564897),1e-6);}
END_TEST

START_TEST(atan_test_15) {
    ck_assert_ldouble_eq_tol(s21_atan(123456), atan(123456),1e-6);}
END_TEST

START_TEST(atan_test_16) {
    ck_assert_ldouble_eq_tol(s21_atan(-18), atan(-18),1e-6);}
END_TEST

START_TEST(atan_test_17) {
    ck_assert_ldouble_eq_tol(s21_atan(4.624262), atan(4.624262),1e-6);}
END_TEST
START_TEST(atan_test_18) {
    ck_assert_ldouble_eq_tol(s21_atan(PI/2), atan(PI/2),1e-6);}
END_TEST
START_TEST(atan_test_19) {
    ck_assert_ldouble_eq_tol(s21_atan(-PI/2), atan(-PI/2),1e-6);}
END_TEST
START_TEST(atan_test_20) {
    ck_assert_ldouble_eq_tol(s21_atan(1.01), atan(1.01),1e-6);}
END_TEST
Suite *get_suite_s21_atan() {
    Suite *s = suite_create("s21_atan suite ");
    TCase *tc = tcase_create("s21_atan test case");
    suite_add_tcase(s, tc);
    tcase_add_test(tc, atan_test_1);
    tcase_add_test(tc, atan_test_2);
    tcase_add_test(tc, atan_test_3);
    tcase_add_test(tc, atan_test_4);
    tcase_add_test(tc, atan_test_5);
    tcase_add_test(tc, atan_test_6);
    tcase_add_test(tc, atan_test_7);
    tcase_add_test(tc, atan_test_8);
    tcase_add_test(tc, atan_test_9);
    tcase_add_test(tc, atan_test_10);
    tcase_add_test(tc, atan_test_11);
    tcase_add_test(tc, atan_test_12);
    tcase_add_test(tc, atan_test_13);
    tcase_add_test(tc, atan_test_14);
    tcase_add_test(tc, atan_test_15);
    tcase_add_test(tc, atan_test_16);
    tcase_add_test(tc, atan_test_17);
    tcase_add_test(tc, atan_test_18);
    tcase_add_test(tc, atan_test_19);
    tcase_add_test(tc, atan_test_20);

    return s;
}