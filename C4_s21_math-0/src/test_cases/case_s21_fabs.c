#include "../test_cases_s21_math.h"



START_TEST(fabs_test_1) {
    ck_assert_ldouble_eq(s21_fabs(0.00000003), fabs(0.00000003));
} END_TEST

START_TEST(fabs_test_2) {
    ck_assert_ldouble_eq(s21_fabs(-12.000467), fabs(-12.000467));
} END_TEST

START_TEST(fabs_test_3) {
    ck_assert_ldouble_eq(s21_fabs(-2834348433.854), fabs(-2834348433.854));
} END_TEST

START_TEST(fabs_test_4) {
    ck_assert_ldouble_eq(s21_fabs(2834348433.854), fabs(2834348433.854));
} END_TEST

START_TEST(fabs_test_5) {
    ck_assert_ldouble_eq(s21_fabs(-5.53151413431), fabs(-5.53151413431));
} END_TEST

START_TEST(fabs_test_6) {
    ck_assert_ldouble_nan(s21_fabs(NAN));
} END_TEST

START_TEST(fabs_test_7) {
    ck_assert_ldouble_infinite(s21_fabs(max_inf));
} END_TEST

START_TEST(fabs_test_8) {
    ck_assert_ldouble_eq_tol(s21_fabs(-9519359135915.53151413431), fabs(-9519359135915.53151413431), accuracy);
} END_TEST

START_TEST(fabs_test_9) {
    ck_assert_ldouble_eq(s21_fabs(-15.01), fabs(-15.01));
} END_TEST

START_TEST(fabs_test_10) {
    ck_assert_ldouble_eq(s21_fabs(15.01), fabs(15.01));
} END_TEST

START_TEST(fabs_test_11) {
    ck_assert_ldouble_eq(s21_fabs(INFINITY), fabs(INFINITY));
} END_TEST

START_TEST(fabs_test_12) {
    ck_assert_ldouble_eq(s21_fabs(-INFINITY), fabs(-INFINITY));
} END_TEST

Suite *get_suite_s21_fabs() {
    Suite *s = suite_create("s21_fabs suite ");
    TCase *tc = tcase_create("s21_fabs test case");
    suite_add_tcase(s, tc);


    tcase_add_test(tc, fabs_test_1);
    tcase_add_test(tc, fabs_test_2);
    tcase_add_test(tc, fabs_test_3);
    tcase_add_test(tc, fabs_test_4);
    tcase_add_test(tc, fabs_test_5);
    tcase_add_test(tc, fabs_test_6);
    tcase_add_test(tc, fabs_test_7);
    tcase_add_test(tc, fabs_test_8);
    tcase_add_test(tc, fabs_test_9);
    tcase_add_test(tc, fabs_test_10);
    tcase_add_test(tc, fabs_test_11);
    tcase_add_test(tc, fabs_test_12);
    return s;
}
