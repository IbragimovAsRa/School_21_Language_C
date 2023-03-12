#include "../s21_string_tests.h"


START_TEST(sscanf_spec_n_1) {
    char format[] = "%n";
    char str[] = "Ilyusha";
    int n1 = 0, n2 = 0;

    int16_t res1 = s21_sscanf(str, format, &n1);
    int16_t res2 = sscanf(str, format, &n2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_spec_n_2) {
    char format[] = "%d %n";
    char str[] = "80 Ilyusha";
    int d1 = 0, d2 = 0;
    int n1 = 0, n2 = 0;

    int16_t res1 = s21_sscanf(str, format, &d1, &n1);
    int16_t res2 = sscanf(str, format, &d2, &n2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
    ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_spec_n_3) {
    char format[] = "%d %d %n %d %d %d";
    char str[] = "80 50 70 371 327";
    int d1 = 0, d2 = 0;
    int dd1 = 0, dd2 = 0;
    int f1 = 0, f2 = 0;
    int ff1 = 0, ff2 = 0;
    int k1 = 0, k2 = 0;
    int n1 = 0, n2 = 0;

    int16_t res1 = s21_sscanf(str, format, &d1, &dd1, &n1, &f1, &ff1, &k1);
    int16_t res2 = sscanf(str, format, &d2, &dd2, &n2, &f2, &ff2, &k2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
    ck_assert_int_eq(dd1, dd2);
    ck_assert_int_eq(f1, f2);
    ck_assert_int_eq(ff1, ff2);
    ck_assert_int_eq(k1, k2);
    ck_assert_int_eq(n1, n2);
}
END_TEST




Suite *get_suite_s21_sscanf_n() {

    Suite *s = suite_create("s21_sscanf_n suite ");
    TCase *tc = tcase_create("s21_sscanf_n test case");
    suite_add_tcase(s, tc);
    tcase_add_test(tc, sscanf_spec_n_1);
    tcase_add_test(tc, sscanf_spec_n_2);
    tcase_add_test(tc, sscanf_spec_n_3);

    return s;
}