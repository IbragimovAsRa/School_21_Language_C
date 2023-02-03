#include "../test_cases_s21_math.h"


START_TEST(exp_test_1) {
    ck_assert_ldouble_eq_tol(s21_exp(0.5), exp(0.5), accuracy);
}

END_TEST

START_TEST(exp_test_2) {
    ck_assert_ldouble_eq_tol(s21_exp(-0.5), exp(-0.5), accuracy);
}

END_TEST

START_TEST(exp_test_3) {
    ck_assert_ldouble_eq_tol(s21_exp(-1), exp(-1), accuracy);
}

END_TEST

START_TEST(exp_test_4) {
    ck_assert_ldouble_eq_tol(s21_exp(1), exp(1), accuracy);
}

END_TEST
START_TEST(exp_test_5) {
    ck_assert_ldouble_eq_tol(s21_exp(1.1), exp(1.1), accuracy);
}

END_TEST
START_TEST(exp_test_6) {
    ck_assert_ldouble_eq_tol(s21_exp(-2.1), exp(-2.1), accuracy);
}

END_TEST
START_TEST(exp_test_7) {
    ck_assert_ldouble_eq_tol(s21_exp(0), exp(0),  accuracy);
}

END_TEST
START_TEST(exp_test_8) {
    ck_assert_ldouble_eq_tol(s21_exp(-0), exp(-0),  accuracy);
}

END_TEST
START_TEST(exp_test_9) {
    ck_assert_ldouble_eq_tol(s21_exp(5.123456789123), exp(5.123456789123), accuracy);

}

END_TEST


START_TEST(exp_test_10) {
    ck_assert_ldouble_eq_tol(s21_exp(0.00000004564897), exp(0.00000004564897),
                             accuracy);
}

END_TEST

START_TEST(exp_test_11) {
    ck_assert_ldouble_eq_tol(s21_exp(20.1), exp(20.1),accuracy);
}

END_TEST
START_TEST(exp_test_12) {
    ck_assert_ldouble_eq_tol(s21_exp(-20.1), exp(-20.1), accuracy);
}

END_TEST
START_TEST(exp_test_13) {
    ck_assert_ldouble_infinite(s21_exp(max_inf));
}

END_TEST
START_TEST(exp_test_14) {
    ck_assert_ldouble_eq_tol(s21_exp(min_inf), exp(min_inf),  accuracy);
}

END_TEST

START_TEST(exp_test_15) {
    ck_assert_ldouble_nan(s21_exp(max_nan));
}

END_TEST


START_TEST(exp_test_16) {
    ck_assert_ldouble_nan(s21_exp(min_nan));
}

END_TEST


Suite *get_suite_s21_exp() {
    Suite *s = suite_create("s21_exp suite ");
    TCase *tc = tcase_create("s21_exp test case");
    suite_add_tcase(s, tc);

    tcase_add_test(tc, exp_test_1);
    tcase_add_test(tc, exp_test_2);
    tcase_add_test(tc, exp_test_3);
    tcase_add_test(tc, exp_test_4);
    tcase_add_test(tc, exp_test_5);
    tcase_add_test(tc, exp_test_6);
    tcase_add_test(tc, exp_test_7);
    tcase_add_test(tc, exp_test_8);
    tcase_add_test(tc, exp_test_9);
    tcase_add_test(tc, exp_test_10);
    tcase_add_test(tc, exp_test_11);
    tcase_add_test(tc, exp_test_12);
    tcase_add_test(tc, exp_test_13);
    tcase_add_test(tc, exp_test_14);
    tcase_add_test(tc, exp_test_15);
    tcase_add_test(tc, exp_test_16);
    return s;
}