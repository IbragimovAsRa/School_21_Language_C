#include "../test_cases_s21_math.h"


START_TEST(log_test_1) {
    ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), accuracy);

}
END_TEST
START_TEST(log_test_2) {
    ck_assert_ldouble_nan(s21_log(-0.5));

}
END_TEST
START_TEST(log_test_3) {
    ck_assert_ldouble_eq_tol(s21_log(1), log(1), accuracy);

}
END_TEST
START_TEST(log_test_4) {
    ck_assert_ldouble_eq_tol(s21_log(1.1), log(1.1), accuracy);

}
END_TEST
START_TEST(log_test_5) {
    ck_assert_ldouble_infinite(s21_log(0));

}
END_TEST
START_TEST(log_test_6) {
    ck_assert_ldouble_infinite(s21_log(-0));

}
END_TEST
START_TEST(log_test_7) {
    ck_assert_ldouble_eq_tol(s21_log(5.123456789123), log(5.123456789123), accuracy);

}
END_TEST
START_TEST(log_test_8) {
    ck_assert_ldouble_eq_tol(s21_log(0.00000004564), log(0.00000004564),
                             accuracy);
}
END_TEST
START_TEST(log_test_9) {
    ck_assert_ldouble_eq_tol(s21_log(170000000000000.1), log(170000000000000.1),
                             accuracy);
}
END_TEST
START_TEST(log_test_10) {
    ck_assert_ldouble_infinite(s21_log(max_inf));

}
END_TEST
START_TEST(log_test_11) {
    ck_assert_ldouble_nan(s21_log(min_inf));

}
END_TEST
START_TEST(log_test_12) {
    ck_assert_ldouble_nan(s21_log(max_nan));

}
END_TEST
START_TEST(log_test_13) {
    ck_assert_ldouble_nan(s21_log(min_nan));

}
END_TEST

Suite *get_suite_s21_log() {
    Suite *s = suite_create("s21_log suite ");
    TCase *tc = tcase_create("s21_log test case");
    suite_add_tcase(s, tc);
    tcase_add_test(tc, log_test_1);
    tcase_add_test(tc, log_test_2);
    tcase_add_test(tc, log_test_3);
    tcase_add_test(tc, log_test_4);
    tcase_add_test(tc, log_test_5);
    tcase_add_test(tc, log_test_6);
    tcase_add_test(tc, log_test_7);
    tcase_add_test(tc, log_test_8);
    tcase_add_test(tc, log_test_9);
    tcase_add_test(tc, log_test_10);
    tcase_add_test(tc, log_test_11);
    tcase_add_test(tc, log_test_12);
    tcase_add_test(tc, log_test_13);
    return s;
}