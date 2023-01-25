#include <check.h>
#include <math.h>

#include "s21_math.h"


#define accuracy 1e-6

double max_inf = 1.0 / 0.0;
double min_inf = -1.0 / 0.0;
double max_nan = 0.0 / 0.0;
double min_nan = -0.0 / 0.0;



START_TEST(exp_test) {
    ck_assert_ldouble_eq_tol(s21_exp(0.5), exp(0.5), accuracy);
    ck_assert_ldouble_eq_tol(s21_exp(-0.5), exp(-0.5), accuracy);
    ck_assert_ldouble_eq_tol(s21_exp(-1), exp(-1), accuracy);
    ck_assert_ldouble_eq_tol(s21_exp(1), exp(1), accuracy);
    ck_assert_ldouble_eq_tol(s21_exp(1.1), exp(1.1), accuracy);
    ck_assert_ldouble_eq_tol(s21_exp(-2.1), exp(-2.1), accuracy);
    ck_assert_ldouble_eq_tol(s21_exp(0), exp(0),  accuracy);
    ck_assert_ldouble_eq_tol(s21_exp(-0), exp(-0),  accuracy);
    ck_assert_ldouble_eq_tol(s21_exp(5.123456789123), exp(5.123456789123), accuracy);
    ck_assert_ldouble_eq_tol(s21_exp(0.00000004564897), exp(0.00000004564897),
                             accuracy);
    ck_assert_ldouble_eq_tol(s21_exp(20.1), exp(20.1),accuracy);
    ck_assert_ldouble_eq_tol(s21_exp(-20.1), exp(-20.1), accuracy);
    ck_assert_ldouble_infinite(s21_exp(max_inf));
    ck_assert_ldouble_eq_tol(s21_exp(min_inf), exp(min_inf),  accuracy);
    ck_assert_ldouble_nan(s21_exp(max_nan));
    ck_assert_ldouble_nan(s21_exp(min_nan));
}
END_TEST

START_TEST(log_test) {

    ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), accuracy);
    ck_assert_ldouble_nan(s21_log(-0.5));
    ck_assert_ldouble_eq_tol(s21_log(1), log(1), accuracy);
    ck_assert_ldouble_eq_tol(s21_log(1.1), log(1.1), accuracy);
    ck_assert_ldouble_infinite(s21_log(0));
    ck_assert_ldouble_infinite(s21_log(-0));
    ck_assert_ldouble_eq_tol(s21_log(5.123456789123), log(5.123456789123), accuracy);
    ck_assert_ldouble_eq_tol(s21_log(0.00000004564), log(0.00000004564),
                             accuracy);
    ck_assert_ldouble_eq_tol(s21_log(170000000000000.1), log(170000000000000.1),
                             accuracy);
    ck_assert_ldouble_infinite(s21_log(max_inf));
    ck_assert_ldouble_nan(s21_log(min_inf));
    ck_assert_ldouble_nan(s21_log(max_nan));
    ck_assert_ldouble_nan(s21_log(min_nan));
}
END_TEST


START_TEST(pow_test) {
    ck_assert_ldouble_eq(s21_pow(max_inf, max_inf), pow(max_inf, max_inf));
    ck_assert_ldouble_eq_tol(s21_pow(max_inf, min_inf), pow(max_inf, min_inf),
                             1e-8);
    ck_assert_ldouble_nan(s21_pow(max_inf, max_nan));
    ck_assert_ldouble_nan(s21_pow(max_inf, min_nan));

    ck_assert_ldouble_eq(s21_pow(min_inf, max_inf), pow(min_inf, max_inf));
    ck_assert_ldouble_eq_tol(s21_pow(min_inf, min_inf), pow(min_inf, min_inf),
                             1e-8);
    ck_assert_ldouble_nan(s21_pow(min_inf, max_nan));
    ck_assert_ldouble_nan(s21_pow(min_inf, min_nan));

    ck_assert_ldouble_nan(s21_pow(max_nan, max_inf));
    ck_assert_ldouble_nan(s21_pow(max_nan, min_inf));
    ck_assert_ldouble_nan(s21_pow(max_nan, max_nan));
    ck_assert_ldouble_nan(s21_pow(max_nan, min_nan));

    ck_assert_ldouble_nan(s21_pow(min_nan, max_inf));
    ck_assert_ldouble_nan(s21_pow(min_nan, min_inf));
    ck_assert_ldouble_nan(s21_pow(min_nan, max_nan));
    ck_assert_ldouble_nan(s21_pow(min_nan, min_nan));
    ck_assert_ldouble_infinite(s21_pow(max_inf, 2.4));
    ck_assert_ldouble_infinite(s21_pow(min_inf, 2.4));
    ck_assert_ldouble_nan(s21_pow(max_nan, 2.4));
    ck_assert_ldouble_nan(s21_pow(min_nan, 2.4));
    ck_assert_ldouble_infinite(s21_pow(2.4, max_inf));
    ck_assert_ldouble_eq_tol(s21_pow(2.4, min_inf), pow(2.4, min_inf), accuracy );
    ck_assert_ldouble_nan(s21_pow(2.4, max_nan));
    ck_assert_ldouble_nan(s21_pow(2.4, min_nan));

    ck_assert_ldouble_eq_tol(s21_pow(0, 2.4), pow(0, 2.4), accuracy );
    ck_assert_ldouble_eq_tol(s21_pow(-0, 2.4), pow(-0, 2.4), accuracy );
    ck_assert_ldouble_eq_tol(s21_pow(2.4, 0), pow(2.4, 0), accuracy );
    ck_assert_ldouble_eq_tol(s21_pow(2.4, -0), pow(2.4, -0), accuracy );
    ck_assert_ldouble_eq_tol(s21_pow(2.4, 0.5), pow(2.4, 0.5), accuracy );
    ck_assert_ldouble_eq_tol(s21_pow(2.4, -0.5), pow(2.4, -0.5), accuracy );
    ck_assert_ldouble_nan(s21_pow(-2.4, 0.5));
    ck_assert_ldouble_nan(s21_pow(-2.4, -0.5));
    ck_assert_ldouble_nan(s21_pow(-2.4, 2.1));
    ck_assert_ldouble_nan(s21_pow(-2.4, -2.1));
    ck_assert_ldouble_eq_tol(s21_pow(-2.4, 2), pow(-2.4, 2), accuracy );
    ck_assert_ldouble_eq_tol(s21_pow(2.4, 2), pow(2.4, 2), accuracy );
    ck_assert_ldouble_eq_tol(s21_pow(-2.4, -1), pow(-2.4, -1), accuracy );
    ck_assert_ldouble_nan(s21_pow(-2.4, -1.2));
    ck_assert_ldouble_nan(s21_pow(-2.4, -0.4));
    ck_assert_ldouble_eq_tol(s21_pow(2.4, 1), pow(2.4, 1), 1e-8);
    ck_assert_ldouble_eq_tol(s21_pow(2.4, 3), pow(2.4, 3), 1e-8);
    ck_assert_ldouble_eq_tol(s21_pow(2.4, -3), pow(2.4, -3), 1e-8);
    ck_assert_ldouble_eq_tol(s21_pow(66666.4, 1.5), pow(66666.4, 1.5), accuracy );
    ck_assert_ldouble_eq_tol(s21_pow(66666.4, -1.5), pow(66666.4, -1.5), accuracy );
    ck_assert_ldouble_eq_tol(s21_pow(3.3, 13.2), pow(3.3, 13.2), accuracy );
}
END_TEST

START_TEST(sqrt_test) {
    ck_assert_ldouble_nan(s21_sqrt(min_inf));
    ck_assert_ldouble_infinite(s21_sqrt(max_inf));
    ck_assert_ldouble_nan(s21_sqrt(max_nan));
    ck_assert_ldouble_nan(s21_sqrt(min_nan));
    ck_assert_ldouble_eq_tol(s21_sqrt(0.5), sqrt(0.5), accuracy);
    ck_assert_ldouble_nan(s21_sqrt(-0.5));
    ck_assert_ldouble_eq_tol(s21_sqrt(1), sqrt(1), accuracy);
    ck_assert_ldouble_eq_tol(s21_sqrt(1.1), sqrt(1.1), accuracy);
    ck_assert_ldouble_eq_tol(s21_sqrt(0), sqrt(0), accuracy);
    ck_assert_ldouble_eq_tol(s21_sqrt(-0), sqrt(-0), accuracy);
    ck_assert_ldouble_eq_tol(s21_sqrt(5.123456789123), sqrt(5.123456789123),
                             accuracy);
    ck_assert_ldouble_eq_tol(s21_sqrt(0.00000004564897), sqrt(0.00000004564897),
                             accuracy);
}
END_TEST

START_TEST(ceil_test) {
    ck_assert_ldouble_eq(s21_ceil(max_inf), ceil(max_inf));
    ck_assert_ldouble_eq(s21_ceil(min_inf), ceil(min_inf));
    ck_assert_ldouble_nan(s21_ceil(max_nan));
    ck_assert_ldouble_nan(s21_ceil(min_nan));
    ck_assert_ldouble_eq(s21_ceil(-876554310.23455), ceil(-876554310.23455));
    ck_assert_ldouble_eq(s21_ceil(876554310.23455), ceil(876554310.23455));
    ck_assert_ldouble_eq(s21_ceil(-0.45), ceil(-0.45));
    ck_assert_ldouble_eq(s21_ceil(0.45), ceil(0.45));
    ck_assert_ldouble_eq(s21_ceil(-0.00000000000000045),
                         ceil(-0.00000000000000045));
}
END_TEST


int main(void) {

    Suite *s = suite_create("String suite");
    TCase *tc = tcase_create("String test case");
    SRunner * runner = srunner_create(s);

    suite_add_tcase(s, tc);
    tcase_add_test(tc, exp_test);
    tcase_add_test(tc, log_test);
    tcase_add_test(tc, pow_test);
    tcase_add_test(tc, sqrt_test);
    tcase_add_test(tc, ceil_test);


    srunner_set_fork_status(runner, CK_NOFORK);
    srunner_run_all(runner, CK_NORMAL);
    srunner_free(runner);

    return 0;
}