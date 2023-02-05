#include "../test_cases_s21_math.h"



START_TEST(floor_test_1) { ck_assert_ldouble_eq(s21_floor(0.0), floor(0.0)); }
END_TEST

START_TEST(floor_test_2) { ck_assert_ldouble_eq(s21_floor(21.21), floor(21.21)); }
END_TEST

START_TEST(floor_test_3) { ck_assert_ldouble_eq(s21_floor(21.91), floor(21.91)); }
END_TEST

START_TEST(floor_test_4) { ck_assert_ldouble_eq(s21_floor(-21.21), floor(-21.21)); }
END_TEST

START_TEST(floor_test_5) { ck_assert_ldouble_eq(s21_floor(-21.91), floor(-21.91)); }
END_TEST

START_TEST(floor_test_6) {
    ck_assert_ldouble_infinite(s21_floor(INFINITY));
}
END_TEST

START_TEST(floor_test_7) {
    ck_assert_ldouble_nan(s21_floor(NAN));
}
END_TEST

START_TEST(floor_test_8) {
    ck_assert_ldouble_eq(s21_floor(0), floor(0));
}
END_TEST

START_TEST(floor_test_9) {
    ck_assert_ldouble_eq(s21_floor(-15.01), floor(-15.01));
}
END_TEST

START_TEST(floor_test_10) {
    ck_assert_ldouble_eq(s21_floor(INFINITY), floor(INFINITY));
}
END_TEST

START_TEST(floor_test_11) {
    ck_assert_ldouble_eq(s21_floor(-INFINITY), floor(-INFINITY));
}
END_TEST


START_TEST(floor_test_12) {
    ck_assert_ldouble_nan(s21_floor(NAN));
}
END_TEST


START_TEST(floor_test_13) { ck_assert_ldouble_eq(s21_floor(-0), floor(-0)); }
END_TEST

START_TEST(floor_test_14) { ck_assert_ldouble_eq(s21_floor(-1), floor(-1)); }
END_TEST

Suite *get_suite_s21_floor() {
    Suite *s = suite_create("s21_floor suite ");
    TCase *tc = tcase_create("s21_floor test case");
    suite_add_tcase(s, tc);
    tcase_add_test(tc, floor_test_1);
    tcase_add_test(tc, floor_test_2);
    tcase_add_test(tc, floor_test_3);
    tcase_add_test(tc, floor_test_4);
    tcase_add_test(tc, floor_test_5);
    tcase_add_test(tc, floor_test_6);
    tcase_add_test(tc, floor_test_7);
    tcase_add_test(tc, floor_test_8);
    tcase_add_test(tc, floor_test_9);
    tcase_add_test(tc, floor_test_10);
    tcase_add_test(tc, floor_test_11);
    tcase_add_test(tc, floor_test_12);
    tcase_add_test(tc, floor_test_13);
    tcase_add_test(tc, floor_test_14);

    return s;
}
