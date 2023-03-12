#include "../s21_string_tests.h"




START_TEST(sscanf_spec_hd_1) {
    char format[] = "%hd";
    char str[] = "123";
    short d1, d2;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_2) {
    char format[] = "%hd";
    char str[] = "-123";
    short d1, d2;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_3) {
    char format[] = "%hd";
    char str[] = "+123";
    short d1, d2;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_4) {
    char format[] = "%3hd";
    char str[] = "-123";
    short d1, d2;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_5) {
    char format[] = "%4hd";
    char str[] = "-123";
    short d1, d2;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_6) {
    char format[] = "%10hd";
    char str[] = "-123";
    short d1, d2;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_7) {
    char format[] = "%1hd";
    char str[] = "-123";
    short d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_8) {
    char format[] = "%3hd";
    char str[] = "+123";
    short d1, d2;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_9) {
    char format[] = "%4hd";
    char str[] = "+123";
    short d1, d2;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_10) {
    char format[] = "%10hd";
    char str[] = "+123";
    short d1, d2;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_11) {
    char format[] = "%1hd";
    char str[] = "+123";
    short d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_12) {
    char format[] = "%*1hd";
    char str[] = "+123";
    short d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_13) {
    char format[] = "%*hd";
    char str[] = "123";
    short d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_14) {
    char format[] = "%hd";
    char str[] = "2147483647";
    short d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_15) {
    char format[] = "%hd";
    char str[] = "+2147483648";
    short d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_16) {
    char format[] = "%hd";
    char str[] = "214743483648";
    short d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_17) {
    char format[] = "%hd";
    char str[] = "-2147483648";
    short d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_18) {
    char format[] = "%hd";
    char str[] = "-2147483649";
    short d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_19) {
    char format[] = "%hd";
    char str[] = "-214748364239";
    short d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_20) {
    char format[] = "%hd";
    char str[] = "−9223372036854775808";
    short d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_21) {
    char format[] = "%hd";
    char str[] = "−9223372036854775809";
    short d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_22) {
    char format[] = "%hd";
    char str[] = "−922337203685477582309";
    short d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_23) {
    char format[] = "%hd";
    char str[] = "9223372036854775807";
    short d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_24) {
    char format[] = "%hd";
    char str[] = "9223372036854775808";
    short d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_25) {
    char format[] = "%hd";
    char str[] = "922337203685477582309";
    short d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST



START_TEST(sscanf_spec_d_1) {
    char format[] = "%d";
    char str[] = "123";
    int d1, d2;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_2) {
    char format[] = "%d";
    char str[] = "-123";
    int d1, d2;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_3) {
    char format[] = "%d";
    char str[] = "+123";
    int d1, d2;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_4) {
    char format[] = "%3d";
    char str[] = "-123";
    int d1, d2;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_5) {
    char format[] = "%4d";
    char str[] = "-123";
    int d1, d2;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_6) {
    char format[] = "%10d";
    char str[] = "-123";
    int d1, d2;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_7) {
    char format[] = "%1d";
    char str[] = "-123";
    int d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);

    s21_sscanf(str, format, &d1);
    sscanf(str, format, &d2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_8) {
    char format[] = "%3d";
    char str[] = "+123";
    int d1, d2;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_9) {
    char format[] = "%4d";
    char str[] = "+123";
    int d1, d2;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_10) {
    char format[] = "%10d";
    char str[] = "+123";
    int d1, d2;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_11) {
    char format[] = "%1d";
    char str[] = "+123";
    int d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_12) {
    char format[] = "%*1d";
    char str[] = "+123";
    int d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_13) {
    char format[] = "%*d";
    char str[] = "123";
    int d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_14) {
    char format[] = "%d";
    char str[] = "2147483647";
    int d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_15) {
    char format[] = "%d";
    char str[] = "+2147483648";
    int d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_16) {
    char format[] = "%d";
    char str[] = "214743483648";
    int d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_17) {
    char format[] = "%d";
    char str[] = "-2147483648";
    int d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_18) {
    char format[] = "%d";
    char str[] = "-2147483649";
    int d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_19) {
    char format[] = "%d";
    char str[] = "-214748364239";
    int d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_20) {
    char format[] = "%d";
    char str[] = "−9223372036854775808";
    int d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_21) {
    char format[] = "%d";
    char str[] = "−9223372036854775809";
    int d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_22) {
    char format[] = "%d";
    char str[] = "−922337203685477582309";
    int d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_23) {
    char format[] = "%d";
    char str[] = "9223372036854775807";
    int d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_24) {
    char format[] = "%d";
    char str[] = "9223372036854775808";
    int d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_25) {
    char format[] = "%d";
    char str[] = "922337203685477582309";
    int d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, format, &d1);
    int16_t res2 = sscanf(str, format, &d2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(d1, d2);
}
END_TEST



Suite *get_suite_s21_sscanf_d() {
    Suite *s = suite_create("s21_sscanf_d suite ");
    TCase *tc = tcase_create("s21_sscanf_d test case");
    suite_add_tcase(s, tc);


    tcase_add_test(tc, sscanf_spec_hd_1);
    tcase_add_test(tc, sscanf_spec_hd_2);
    tcase_add_test(tc, sscanf_spec_hd_3);
    tcase_add_test(tc, sscanf_spec_hd_4);
    tcase_add_test(tc, sscanf_spec_hd_5);
    tcase_add_test(tc, sscanf_spec_hd_6);
    tcase_add_test(tc, sscanf_spec_hd_7);
    tcase_add_test(tc, sscanf_spec_hd_8);
    tcase_add_test(tc, sscanf_spec_hd_9);
    tcase_add_test(tc, sscanf_spec_hd_10);
    tcase_add_test(tc, sscanf_spec_hd_11);
    tcase_add_test(tc, sscanf_spec_hd_12);
    tcase_add_test(tc, sscanf_spec_hd_13);
    tcase_add_test(tc, sscanf_spec_hd_14);
    tcase_add_test(tc, sscanf_spec_hd_15);
    tcase_add_test(tc, sscanf_spec_hd_16);
    tcase_add_test(tc, sscanf_spec_hd_17);
    tcase_add_test(tc, sscanf_spec_hd_18);
    tcase_add_test(tc, sscanf_spec_hd_19);
    tcase_add_test(tc, sscanf_spec_hd_20);
    tcase_add_test(tc, sscanf_spec_hd_21);
    tcase_add_test(tc, sscanf_spec_hd_22);
    tcase_add_test(tc, sscanf_spec_hd_23);
    tcase_add_test(tc, sscanf_spec_hd_24);
    tcase_add_test(tc, sscanf_spec_hd_25);


    tcase_add_test(tc, sscanf_spec_d_1);
    tcase_add_test(tc, sscanf_spec_d_2);
    tcase_add_test(tc, sscanf_spec_d_3);
    tcase_add_test(tc, sscanf_spec_d_4);
    tcase_add_test(tc, sscanf_spec_d_5);
    tcase_add_test(tc, sscanf_spec_d_6);
    tcase_add_test(tc, sscanf_spec_d_7);
    tcase_add_test(tc, sscanf_spec_d_8);
    tcase_add_test(tc, sscanf_spec_d_9);
    tcase_add_test(tc, sscanf_spec_d_10);
    tcase_add_test(tc, sscanf_spec_d_11);
    tcase_add_test(tc, sscanf_spec_d_12);
    tcase_add_test(tc, sscanf_spec_d_13);
    tcase_add_test(tc, sscanf_spec_d_14);
    tcase_add_test(tc, sscanf_spec_d_15);
    tcase_add_test(tc, sscanf_spec_d_16);
    tcase_add_test(tc, sscanf_spec_d_17);
    tcase_add_test(tc, sscanf_spec_d_18);
    tcase_add_test(tc, sscanf_spec_d_19);
    tcase_add_test(tc, sscanf_spec_d_20);
    tcase_add_test(tc, sscanf_spec_d_21);
    tcase_add_test(tc, sscanf_spec_d_22);
    tcase_add_test(tc, sscanf_spec_d_23);
    tcase_add_test(tc, sscanf_spec_d_24);
    tcase_add_test(tc, sscanf_spec_d_25);
    return s;
}
