#include "../test_cases_s21_math.h"


START_TEST(abs_test_1) {ck_assert_int_eq(s21_abs(17), abs(17)); }

END_TEST

START_TEST(abs_test_2) { ck_assert_int_eq(s21_abs(-17), abs(-17)); }

END_TEST

START_TEST(abs_test_3) { ck_assert_int_eq(s21_abs(-892397534), abs(-892397534)); }

END_TEST

START_TEST(abs_test_4) { ck_assert_int_eq(s21_abs(892397534), abs(892397534)); }

END_TEST

START_TEST(abs_test_5) { ck_assert_int_eq(s21_abs(-0), abs(-0)); }

END_TEST

START_TEST(abs_test_6) { ck_assert_int_eq(s21_abs(+0), abs(+0)); }

END_TEST

START_TEST(abs_test_7) { ck_assert_int_eq(s21_abs(0), abs(0)); }

END_TEST

START_TEST(abs_test_8) { ck_assert_int_eq(s21_abs((int) INFINITY), abs((int) INFINITY)); }

END_TEST
START_TEST(abs_test_9) { ck_assert_int_eq(s21_abs((int) -INFINITY), abs((int) -INFINITY)); }

END_TEST

START_TEST(abs_test_10) { ck_assert_int_eq(s21_abs((int) NAN), abs((int) NAN)); }

END_TEST

Suite *get_suite_s21_abs() {
    Suite *s = suite_create("s21_abs suite ");
    TCase *tc = tcase_create("s21_abs test case");
    suite_add_tcase(s, tc);


    tcase_add_test(tc, abs_test_1);
    tcase_add_test(tc, abs_test_2);
    tcase_add_test(tc, abs_test_3);
    tcase_add_test(tc, abs_test_4);
    tcase_add_test(tc, abs_test_5);
    tcase_add_test(tc, abs_test_6);
    tcase_add_test(tc, abs_test_7);
    tcase_add_test(tc, abs_test_8);
    tcase_add_test(tc, abs_test_9);
    tcase_add_test(tc, abs_test_10);

    return s;
}
