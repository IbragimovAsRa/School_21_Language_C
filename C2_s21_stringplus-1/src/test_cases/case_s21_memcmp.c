#include "../s21_string_tests.h"


START_TEST(memcmp_test_1) {
    char *test_str_1 = "hello world";
    char *test_str_2 = "hello world";
    unsigned long length = strlen(test_str_1);
    ck_assert_int_eq(s21_memcmp(test_str_1, test_str_2, length), memcmp(test_str_1, test_str_2, length));
}

END_TEST

START_TEST(memcmp_test_2) {
    char *test_str_1 = "hello world";
    char *test_str_2 = "hello warld";
    unsigned long length = strlen(test_str_1);
    ck_assert_int_eq(s21_memcmp(test_str_1, test_str_2, length), memcmp(test_str_1, test_str_2, length));
}

END_TEST

Suite *get_suite_s21_memcmp() {
    Suite *s = suite_create("s21_memcmp suite ");
    TCase *tc = tcase_create("s21_memcmp test case");
    suite_add_tcase(s, tc);

    tcase_add_test(tc, memcmp_test_1);
    tcase_add_test(tc, memcmp_test_2);


    return s;
}