#include "../s21_string_tests.h"


START_TEST(sscanf_test_0) {
    char ch_1;
    char ch_2;
    char ch_3;
    char s21_ch_1;
    char s21_ch_2;
    char s21_ch_3;
    s21_sscanf("my number abc", "my number %c%c%c", &s21_ch_1, &s21_ch_2, &s21_ch_3);
    sscanf("my number abc", "my number %c%c%c", &ch_1, &ch_2, &ch_3);
    ck_assert_int_eq((int) s21_ch_1, (int) ch_1);
    ck_assert_int_eq((int) s21_ch_2, (int) ch_2);
    ck_assert_int_eq((int) s21_ch_3, (int) ch_3);
}

END_TEST

START_TEST(sscanf_test_1) {
    char ch_1;
    char ch_2;
    char ch_3;
    char s21_ch_1;
    char s21_ch_2;
    char s21_ch_3;
    s21_sscanf("abc", "%c%c%c", &s21_ch_1, &s21_ch_2, &s21_ch_3);
    sscanf("abc", "%c%c%c", &ch_1, &ch_2, &ch_3);

    ck_assert_int_eq((int) s21_ch_1, (int) ch_1);
    ck_assert_int_eq((int) s21_ch_2, (int) ch_2);
    ck_assert_int_eq((int) s21_ch_3, (int) ch_3);

}

END_TEST


START_TEST(sscanf_test_2) {
    char ch_1;
    char ch_2;
    char ch_3;
    char s21_ch_1;
    char s21_ch_2;
    char s21_ch_3;
    s21_sscanf("a bc", "%c%c%c", &s21_ch_1, &s21_ch_2, &s21_ch_3);
    sscanf("a bc", "%c%c%c", &ch_1, &ch_2, &ch_3);
    ck_assert_int_eq((int) s21_ch_1, (int) ch_1);
    ck_assert_int_eq((int) s21_ch_2, (int) ch_2);
    ck_assert_int_eq((int) s21_ch_3, (int) ch_3);
}

END_TEST


START_TEST(sscanf_test_3) {
    char ch_1;
    char ch_2;
    char ch_3;
    char s21_ch_1;
    char s21_ch_2;
    char s21_ch_3;
    s21_sscanf("a bc", "%c %c%c", &s21_ch_1, &s21_ch_2, &s21_ch_3);
    sscanf("a bc", "%c %c%c", &ch_1, &ch_2, &ch_3);
    ck_assert_int_eq((int) s21_ch_1, (int) ch_1);
    ck_assert_int_eq((int) s21_ch_2, (int) ch_2);
    ck_assert_int_eq((int) s21_ch_3, (int) ch_3);
}

END_TEST

START_TEST(sscanf_test_4) {
    int a;
    int b;
    s21_sscanf("228", "%d", &a);
    sscanf("228", "%d", &b);
    ck_assert_int_eq(a, b);
}

END_TEST

START_TEST(sscanf_test_5) {
    int a;
    int b;
    s21_sscanf("my number 228", "my number     %d", &a);
    sscanf("my number 228", "my number     %d", &b);
    ck_assert_int_eq(a, b);
}

END_TEST

START_TEST(sscanf_test_6) {
    int a;
    int b;
    s21_sscanf("my number 228", "my number %d", &a);
    sscanf("my number 228", "my number %d", &b);
    ck_assert_int_eq(a, b);
}

END_TEST

START_TEST(sscanf_test_7) {
    int a;
    int b;
    s21_sscanf("my number 228", "my number%d", &a);
    sscanf("my number 228", "my number%d", &b);
    ck_assert_int_eq(a, b);
}

END_TEST


START_TEST(sscanf_test_8) {
    int s21_in_1;
    int in_1;
    s21_sscanf("my number 017", "my number %i is", &s21_in_1);
    sscanf("my number 017", "my number %i is", &in_1);
    ck_assert_int_eq((int) s21_in_1, (int) in_1);
}

END_TEST

START_TEST(sscanf_test_9) {
    char *test_str = "hello";
    char *pattern = "%s";
    char tmp_str_1[256];
    char tmp_str_2[256];
   // int s21_result =
   s21_sscanf(test_str, pattern, tmp_str_1);
    //int result =
    sscanf(test_str, pattern, tmp_str_2);

    //ck_assert_int_eq(s21_result,result);
    ck_assert_str_eq(tmp_str_1, tmp_str_2);
}

END_TEST


START_TEST(sscanf_test_10) {
    char *test_str = "hello world";
    char *pattern = "%s %s";
    char tmp_str_1[256];
    char tmp_str_2[256];
    char tmp_str_11[256];
    char tmp_str_22[256];

    // int s21_result =
    s21_sscanf(test_str, pattern, tmp_str_1, tmp_str_11);
    //int result =
    sscanf(test_str, pattern, tmp_str_2, tmp_str_22);

    ck_assert_str_eq(tmp_str_1, tmp_str_2);
    ck_assert_str_eq(tmp_str_11, tmp_str_22);
}

END_TEST

START_TEST(sscanf_test_11) {
    char *test_str = "hello lala world";
    char *pattern = "%s %s";
    char tmp_str_1[256];
    char tmp_str_2[256];
    char tmp_str_11[256];
    char tmp_str_22[256];

    // int s21_result =
    s21_sscanf(test_str, pattern, tmp_str_1, tmp_str_11);
    //int result =
    sscanf(test_str, pattern, tmp_str_2, tmp_str_22);

    ck_assert_str_eq(tmp_str_1, tmp_str_2);
    ck_assert_str_eq(tmp_str_11, tmp_str_22);
}

END_TEST

START_TEST(sscanf_test_12) {
    char *test_str = "hello world";
    char *pattern = "%s%s";
    char tmp_str_1[256];
    char tmp_str_2[256];
    char tmp_str_11[256];
    char tmp_str_22[256];

    // int s21_result =
    s21_sscanf(test_str, pattern, tmp_str_1, tmp_str_11);
    //int result =
    sscanf(test_str, pattern, tmp_str_2, tmp_str_22);

    ck_assert_str_eq(tmp_str_1, tmp_str_2);
    ck_assert_str_eq(tmp_str_11, tmp_str_22);
}

END_TEST

START_TEST(sscanf_test_13) {
    char ch_1;
    char ch_2;
    char ch_3;
    char s21_ch_1;
    char s21_ch_2;
    char s21_ch_3;
    s21_sscanf("a    bc", "%c %c%c", &s21_ch_1, &s21_ch_2, &s21_ch_3);
    sscanf("a    bc", "%c %c%c", &ch_1, &ch_2, &ch_3);
    ck_assert_int_eq((int) s21_ch_1, (int) ch_1);
    ck_assert_int_eq((int) s21_ch_2, (int) ch_2);
    ck_assert_int_eq((int) s21_ch_3, (int) ch_3);


}

END_TEST

// test *
START_TEST(sscanf_test_14) {
    char *test_str = "hello world";
    char *pattern = "%*s%s";
    char tmp_str_1[256];
    char tmp_str_2[256];


    // int s21_result =
    s21_sscanf(test_str, pattern, tmp_str_1);
    //int result =
    sscanf(test_str, pattern, tmp_str_2);

    ck_assert_str_eq(tmp_str_1, tmp_str_2);
}
END_TEST

// test float
START_TEST(sscanf_test_15) {
    char *test_str = "hello 12.1223";
    char *pattern = "hello %f";
    float n1;
    float n2;

    s21_sscanf(test_str, pattern, &n1);
    sscanf(test_str, pattern, &n2);
    ck_assert_float_eq(n1, n2);

    test_str = "hello 12.1223";
    pattern = "hello %4f";

    s21_sscanf(test_str, pattern, &n1);
    sscanf(test_str, pattern, &n2);
    ck_assert_float_eq(n1, n2);

    test_str = "number 12.32 65.45643";
    pattern = "number %*f %f";

    s21_sscanf(test_str, pattern, &n1);
    sscanf(test_str, pattern, &n2);
    ck_assert_float_eq(n1, n2);

    test_str = "number 12325 65.45643";
    pattern = "number %*4f %f";

    s21_sscanf(test_str, pattern, &n1);
    sscanf(test_str, pattern, &n2);
    ck_assert_float_eq(n1, n2);


}
END_TEST

Suite *get_suite_s21_sscanf() {
    Suite *s = suite_create("s21_sscanf suite ");
    TCase *tc = tcase_create("s21_sscanf test case");
    suite_add_tcase(s, tc);
    tcase_add_test(tc, sscanf_test_0);
    tcase_add_test(tc, sscanf_test_1);
    tcase_add_test(tc, sscanf_test_2);
    tcase_add_test(tc, sscanf_test_3);
    tcase_add_test(tc, sscanf_test_4);
    tcase_add_test(tc, sscanf_test_5);
    tcase_add_test(tc, sscanf_test_6);
    tcase_add_test(tc, sscanf_test_7);
    tcase_add_test(tc, sscanf_test_8);
    tcase_add_test(tc, sscanf_test_9);
    tcase_add_test(tc, sscanf_test_10);
    tcase_add_test(tc, sscanf_test_11);
    tcase_add_test(tc, sscanf_test_12);
    tcase_add_test(tc, sscanf_test_13);
    tcase_add_test(tc, sscanf_test_14);
    tcase_add_test(tc, sscanf_test_15);





    return s;
}