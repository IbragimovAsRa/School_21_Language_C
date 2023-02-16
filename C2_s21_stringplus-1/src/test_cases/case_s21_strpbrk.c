#include "../s21_string_tests.h"

START_TEST(strpbrk_test_1) { // empty
    char str1[] = "";
    char str2[] = "";

    ck_assert_pstr_eq(s21_strpbrk(str1, str2),
                      strpbrk(str1, str2));
} END_TEST

START_TEST(strpbrk_test_2) { //str1 tik
    char str1[] = "tik";
    char str2[] = "";

    ck_assert_pstr_eq(s21_strpbrk(str1, str2),
                      strpbrk(str1, str2));
} END_TEST

START_TEST(strpbrk_test_3) { //str2 tok
    char str1[] = "";
    char str2[] = "tok";

    ck_assert_pstr_eq(s21_strpbrk(str1, str2),
                      strpbrk(str1, str2));
} END_TEST

START_TEST(strpbrk_test_4) {
    char str1[] = "bb go next";
    char str2[] = "yep";

    ck_assert_pstr_eq(s21_strpbrk(str1, str2),
                      strpbrk(str1, str2));
} END_TEST

START_TEST(strpbrk_test_5) { // go
    char str1[] = "bb go next";
    char str2[] = "go";

    ck_assert_pstr_eq(s21_strpbrk(str1, str2),
                      strpbrk(str1, str2));
} END_TEST

START_TEST(strpbrk_test_6) { // e
    char str1[] = "hey hi";
    char str2[] = "e";

    ck_assert_pstr_eq(s21_strpbrk(str1, str2),
                      strpbrk(str1, str2));
} END_TEST

START_TEST(strpbrk_test_7) { // S
    char str1[] = "School21";
    char str2[] = "S";

    ck_assert_pstr_eq(s21_strpbrk(str1, str2),
                      strpbrk(str1, str2));
} END_TEST

START_TEST(strpbrk_test_8) { // 0
    char str1[] = "School21";
    char str2[] = "\0";

    ck_assert_pstr_eq(s21_strpbrk(str1, str2),
                      strpbrk(str1, str2));
} END_TEST


Suite *get_suite_s21_strpbrk() {
    Suite *s = suite_create("s21_strpbrk suite");
    TCase *tc = tcase_create("s21_strpbrk test case");
    suite_add_tcase(s, tc);

    tcase_add_test(tc, strpbrk_test_1);
    tcase_add_test(tc, strpbrk_test_2);
    tcase_add_test(tc, strpbrk_test_3);
    tcase_add_test(tc, strpbrk_test_4);
    tcase_add_test(tc, strpbrk_test_5);
    tcase_add_test(tc, strpbrk_test_6);
    tcase_add_test(tc, strpbrk_test_7);
    tcase_add_test(tc, strpbrk_test_8);

    return s;
}