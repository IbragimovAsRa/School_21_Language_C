#include "../test_cases_s21_math.h"


START_TEST(fmod_test_1) {
    ck_assert_ldouble_eq(s21_fmod(2.34, 2.0), fmod(2.34, 2.0));
}
END_TEST

START_TEST(fmod_test_2) {
    ck_assert_ldouble_eq(s21_fmod(-2.34, 2.0), fmod(-2.34, 2.0));
}
END_TEST

START_TEST(fmod_test_3) {
    ck_assert_ldouble_eq(s21_fmod(2.34, -2.0), fmod(2.34, -2.0));
}
END_TEST

START_TEST(fmod_test_4) {
    ck_assert_ldouble_eq(s21_fmod(-2.34, -2.0), fmod(-2.34, -2.0));
}
END_TEST

START_TEST(fmod_test_5) {
    ck_assert_ldouble_eq(s21_fmod(21.21, 3), fmod(21.21, 3));
}
END_TEST

START_TEST(fmod_test_6) {
    ck_assert_ldouble_eq(s21_fmod(3, 21.21), fmod(3, 21.21));
}
END_TEST

START_TEST(fmod_test_7) {
    ck_assert_ldouble_eq(s21_fmod(-21.21, 3), fmod(-21.21, 3));
}
END_TEST

START_TEST(fmod_test_8) {
    ck_assert_ldouble_eq(s21_fmod(3, -21.21), fmod(3, -21.21));
}
END_TEST

START_TEST(fmod_test_9) {
    ck_assert_ldouble_eq(s21_fmod(100500, 9), fmod(100500, 9));
}
END_TEST

START_TEST(fmod_test_10) {
    ck_assert_ldouble_eq(s21_fmod(-100500, -9), fmod(-100500, -9));
}
END_TEST

START_TEST(fmod_test_11) {
    ck_assert_ldouble_eq(s21_fmod(-9, -100500), fmod(-9, -100500));
}
END_TEST

START_TEST(fmod_test_12) {
    ck_assert_ldouble_eq(s21_fmod(-9, -9), fmod(-9, -9));
}
END_TEST

START_TEST(fmod_test_13) {
    ck_assert_ldouble_eq(s21_fmod(10, 5), fmod(10, 5));
}
END_TEST

START_TEST(fmod_test_14) {
    ck_assert_ldouble_nan(s21_fmod(INFINITY, INFINITY));
    ck_assert_ldouble_nan(fmod(INFINITY, INFINITY));
}
END_TEST

START_TEST(fmod_test_15) {
    ck_assert_ldouble_nan(s21_fmod(NAN, NAN));
    ck_assert_ldouble_nan(fmod(NAN, NAN));
}
END_TEST

START_TEST(fmod_test_16) {
    ck_assert_ldouble_nan(s21_fmod(2.45, 0));
    ck_assert_ldouble_nan(fmod(2.45, 0));
}
END_TEST

START_TEST(fmod_test_17) {
    ck_assert_ldouble_nan(s21_fmod(0, 0));
    ck_assert_ldouble_nan(fmod(0, 0));
}
END_TEST

START_TEST(fmod_test_18) {
    ck_assert_ldouble_nan(s21_fmod(INFINITY, 0));
    ck_assert_ldouble_nan(fmod(INFINITY, 0));
}
END_TEST




START_TEST(fmod_test_19) {
    ck_assert_ldouble_eq(s21_fmod(2.0, INFINITY), fmod(2.0, INFINITY));
}
END_TEST

START_TEST(fmod_test_20) {
    ck_assert_ldouble_eq(s21_fmod(2.0, INFINITY), fmod(2.0, INFINITY));
}
END_TEST

START_TEST(fmod_test_21) {
    ck_assert_ldouble_eq(s21_fmod(2.0, -INFINITY), fmod(2.0, -INFINITY));
}
END_TEST


START_TEST(fmod_test_22) {
    ck_assert_ldouble_nan(s21_fmod(INFINITY, INFINITY));
    ck_assert_ldouble_nan(fmod(INFINITY, INFINITY));
}
END_TEST

START_TEST(fmod_test_23) {
    ck_assert_ldouble_eq(s21_fmod(0, 23), fmod(0, 23));
}
END_TEST

Suite *get_suite_s21_fmod() {
    Suite *s = suite_create("s21_fmod suite ");
    TCase *tc = tcase_create("s21_fmod test case");
    suite_add_tcase(s, tc);


    tcase_add_test(tc, fmod_test_1);
    tcase_add_test(tc, fmod_test_2);
    tcase_add_test(tc, fmod_test_3);
    tcase_add_test(tc, fmod_test_4);
    tcase_add_test(tc, fmod_test_5);
    tcase_add_test(tc, fmod_test_6);
    tcase_add_test(tc, fmod_test_7);
    tcase_add_test(tc, fmod_test_8);
    tcase_add_test(tc, fmod_test_9);
    tcase_add_test(tc, fmod_test_10);
    tcase_add_test(tc, fmod_test_11);
    tcase_add_test(tc, fmod_test_12);
    tcase_add_test(tc, fmod_test_13);
    tcase_add_test(tc, fmod_test_14);
    tcase_add_test(tc, fmod_test_15);
    tcase_add_test(tc, fmod_test_16);
    tcase_add_test(tc, fmod_test_17);
    tcase_add_test(tc, fmod_test_18);
    tcase_add_test(tc, fmod_test_19);
    tcase_add_test(tc, fmod_test_20);
    tcase_add_test(tc, fmod_test_21);
    tcase_add_test(tc, fmod_test_22);
    tcase_add_test(tc, fmod_test_23);

    return s;
}
