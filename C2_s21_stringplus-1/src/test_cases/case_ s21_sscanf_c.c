#include "../s21_string_tests.h"


START_TEST(sscanf_c_test_0) {
    char format[] = "%c";
    char str[] = "\t\n\n  1 \n  \t";
    char c1, c2;

    int16_t res1 = s21_sscanf(str, format, &c1);
    int16_t res2 = sscanf(str, format, &c2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(c1, c2);
}
END_TEST


END_TEST

START_TEST(sscanf_c_test_1) {
    char format[] = "%c";
    char str[] = "\t\n\n   \n  \ta";
    char c1, c2;
    int16_t res1 = s21_sscanf(str, format, &c1);
    int16_t res2 = sscanf(str, format, &c2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_c_test_2) {
    char format[] = "%c%c%c";
    char str[] = "\t\n\n  123 \n  \t";
    char c11, c12, c13, c21, c22, c23;

    int16_t res1 = s21_sscanf(str, format, &c11, &c12, &c13);
    int16_t res2 = sscanf(str, format, &c21, &c22, &c23);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(c11, c21);
    ck_assert_int_eq(c12, c22);
    ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_c_test_3) {
    char format[] = "%c %c \t%c";
    char str[] = "\t\n\n  1    2 3 \n  \t";
    char c11, c12, c13, c21, c22, c23;

    int16_t res1 = s21_sscanf(str, format, &c11, &c12, &c13);
    int16_t res2 = sscanf(str, format, &c21, &c22, &c23);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(c11, c21);
    ck_assert_int_eq(c12, c22);
    ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_c_test_4) {
    char format[] = "%c %c \t%c";
    char str[] = "\t\n\n123\n\t";
    char c11, c12, c13, c21, c22, c23;

    int16_t res1 = s21_sscanf(str, format, &c11, &c12, &c13);
    int16_t res2 = sscanf(str, format, &c21, &c22, &c23);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(c11, c21);
    ck_assert_int_eq(c12, c22);
    ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_c_test_5) {
    char format[] = "%c %*c \t%c";
    char str[] = "\t\n\n  123 \n  \t";
    char c11, c12, c21, c22;

    int16_t res1 = s21_sscanf(str, format, &c11, &c12);
    int16_t res2 = sscanf(str, format, &c21, &c22);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(c11, c21);
    ck_assert_int_eq(c12, c22);
}
END_TEST


Suite *get_suite_s21_sscanf_c() {
    Suite *s = suite_create("s21_sscanf_c suite ");
    TCase *tc = tcase_create("s21_sscanf_c test case");
    suite_add_tcase(s, tc);
    tcase_add_test(tc, sscanf_c_test_0);
    tcase_add_test(tc, sscanf_c_test_1);
    tcase_add_test(tc, sscanf_c_test_2);

    tcase_add_test(tc, sscanf_c_test_3);
    tcase_add_test(tc, sscanf_c_test_4);
    tcase_add_test(tc, sscanf_c_test_5);
    return s;
}

// доделать тест на модификаторы длины

