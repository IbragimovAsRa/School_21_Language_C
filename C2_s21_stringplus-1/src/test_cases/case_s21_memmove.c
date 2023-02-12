#include "../s21_string_tests.h"


START_TEST(memmove_test_1) {
    char test_str_1[15];
    char *test_str_2 = "hello world";
    size_t size  = strlen(test_str_2);
    char *out_1 = memmove(test_str_1, test_str_2, size + 1);
    char *out_2 = s21_memmove(test_str_1, test_str_2, size + 1);
    ck_assert_str_eq(out_1, out_2);
    int s21_result = 0;
    if (out_1 == out_2) {
        s21_result = 1;
    }
    ck_assert_int_eq(s21_result, 1);
}

END_TEST

Suite *get_suite_s21_memmove() {
    Suite *s = suite_create("s21_memmove suite ");
    TCase *tc = tcase_create("s21_memmove test case");
    suite_add_tcase(s, tc);

    tcase_add_test(tc, memmove_test_1);


    return s;
}