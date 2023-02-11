#include "../s21_string_tests.h"
#include "stdio.h"

START_TEST(memchr_test_1) {
    char *test_str_1 = "hello world\0";
    int s21_result = 0;
    size_t size  = strlen(test_str_1);
    char *out_1 = memchr(test_str_1, (int)'w', size + 1);
    char *out_2 = s21_memchr(test_str_1, (int)'w', strlen(test_str_1));

    if (out_1 == out_2) {
        s21_result = 1;
    }
    ck_assert_int_eq(s21_result, 1);
}

END_TEST



Suite *get_suite_s21_memchr() {
    Suite *s = suite_create("s21_memchr suite ");
    TCase *tc = tcase_create("s21_memchr test case");
    suite_add_tcase(s, tc);

    tcase_add_test(tc, memchr_test_1);

    return s;
}