#include "../test_cases_s21_math.h"

START_TEST(cos_test_1) {
    ck_assert_ldouble_nan(s21_cos(max_inf));
}

END_TEST

START_TEST(cos_test_2) {
    ck_assert_ldouble_nan(s21_cos(min_inf));
}

END_TEST

START_TEST(cos_test_3) {
    ck_assert_ldouble_nan(s21_cos(max_nan));

}

END_TEST
START_TEST(cos_test_4) {
    ck_assert_ldouble_nan(s21_cos(min_nan));

}

END_TEST
START_TEST(cos_test_5) {
    ck_assert_ldouble_eq_tol(s21_cos(0.5), cos(0.5), 1e-6);

}

END_TEST
START_TEST(cos_test_6) {
    ck_assert_ldouble_eq_tol(s21_cos(-0.5), cos(-0.5), 1e-6);

}

END_TEST
START_TEST(cos_test_7) {
    ck_assert_ldouble_eq_tol(s21_cos(-1), cos(-1), 1e-6);

}

END_TEST
START_TEST(cos_test_8) {
    ck_assert_ldouble_eq_tol(s21_cos(1), cos(1), 1e-6);

}

END_TEST
START_TEST(cos_test_9) {
    ck_assert_ldouble_eq_tol(s21_cos(1.1), cos(1.1), 1e-6);

}

END_TEST
START_TEST(cos_test_10) {
    ck_assert_ldouble_eq_tol(s21_cos(-2.1), cos(-2.1), 1e-6);

}

END_TEST
START_TEST(cos_test_11) {
    ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), 1e-6);

}

END_TEST
START_TEST(cos_test_12) {
    ck_assert_ldouble_eq_tol(s21_cos(-0), cos(-0), 1e-6);

}

END_TEST
START_TEST(cos_test_13) {
    ck_assert_ldouble_eq_tol(s21_cos(5.123456789123), cos(5.123456789123), 1e-6);

}

END_TEST
START_TEST(cos_test_14) {
    ck_assert_ldouble_eq_tol(s21_cos(0.00000004564897), cos(0.00000004564897),
                             1e-6);

}

END_TEST
START_TEST(cos_test_15) {
    ck_assert_ldouble_eq_tol(s21_cos(170000.1), cos(170000.1), 1e-6);

}

END_TEST


Suite *get_suite_s21_cos() {
    Suite *s = suite_create("s21_cos suite ");
    TCase *tc = tcase_create("s21_cos test case");
    suite_add_tcase(s, tc);

    tcase_add_test(tc, cos_test_1);
    tcase_add_test(tc, cos_test_2);
    tcase_add_test(tc, cos_test_3);
    tcase_add_test(tc, cos_test_4);
    tcase_add_test(tc, cos_test_5);
    tcase_add_test(tc, cos_test_6);
    tcase_add_test(tc, cos_test_7);
    tcase_add_test(tc, cos_test_8);
    tcase_add_test(tc, cos_test_9);
    tcase_add_test(tc, cos_test_10);
    tcase_add_test(tc, cos_test_11);
    tcase_add_test(tc, cos_test_12);
    tcase_add_test(tc, cos_test_13);
    tcase_add_test(tc, cos_test_14);
    tcase_add_test(tc, cos_test_15);

    return s;
}