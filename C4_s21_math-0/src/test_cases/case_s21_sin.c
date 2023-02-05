#include "../test_cases_s21_math.h"


START_TEST(sin_test_1) {
    ck_assert_ldouble_nan(s21_sin(max_inf));

}

END_TEST



START_TEST(sin_test_2) {
    ck_assert_ldouble_nan(s21_sin(min_inf));

}

END_TEST


START_TEST(sin_test_3) {
    ck_assert_ldouble_nan(s21_sin(max_nan));

}

END_TEST


START_TEST(sin_test_4) {
    ck_assert_ldouble_nan(s21_sin(min_nan));

}

END_TEST


START_TEST(sin_test_5) {
    ck_assert_ldouble_eq_tol(s21_sin(0.5), sin(0.5), 1e-6);

}

END_TEST


START_TEST(sin_test_6) {
    ck_assert_ldouble_eq_tol(s21_sin(-0.5), sin(-0.5), 1e-6);

}

END_TEST


START_TEST(sin_test_7) {
    ck_assert_ldouble_eq_tol(s21_sin(-1), sin(-1), 1e-6);

}

END_TEST


START_TEST(sin_test_8) {
    ck_assert_ldouble_eq_tol(s21_sin(1), sin(1), 1e-6);

}

END_TEST


START_TEST(sin_test_9) {
    ck_assert_ldouble_eq_tol(s21_sin(1.1), sin(1.1), 1e-6);

}

END_TEST


START_TEST(sin_test_10) {
    ck_assert_ldouble_eq_tol(s21_sin(-2.1), sin(-2.1), 1e-6);

}

END_TEST


START_TEST(sin_test_11) {
    ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), 1e-6);

}

END_TEST


START_TEST(sin_test_12) {
    ck_assert_ldouble_eq_tol(s21_sin(-0), sin(-0), 1e-6);

}

END_TEST


START_TEST(sin_test_13) {
    ck_assert_ldouble_eq_tol(s21_sin(5.123456789123), sin(5.123456789123), 1e-6);

}

END_TEST


START_TEST(sin_test_14) {
    ck_assert_ldouble_eq_tol(s21_sin(0.00000004564897), sin(0.00000004564897),
                         1e-6);

}

END_TEST

START_TEST(sin_test_15) {
    ck_assert_ldouble_eq_tol(s21_sin(170000.1), sin(170000.1), 1e-6);


}

END_TEST



Suite *get_suite_s21_sin() {
    Suite *s = suite_create("s21_sin suite ");
    TCase *tc = tcase_create("s21_sin test case");
    suite_add_tcase(s, tc);

    tcase_add_test(tc, sin_test_1);
    tcase_add_test(tc, sin_test_2);
    tcase_add_test(tc, sin_test_3);
    tcase_add_test(tc, sin_test_4);
    tcase_add_test(tc, sin_test_5);
    tcase_add_test(tc, sin_test_6);
    tcase_add_test(tc, sin_test_7);
    tcase_add_test(tc, sin_test_8);
    tcase_add_test(tc, sin_test_9);
    tcase_add_test(tc, sin_test_10);
    tcase_add_test(tc, sin_test_11);
    tcase_add_test(tc, sin_test_12);
    tcase_add_test(tc, sin_test_13);
    tcase_add_test(tc, sin_test_14);
    tcase_add_test(tc, sin_test_15);
    return s;
}