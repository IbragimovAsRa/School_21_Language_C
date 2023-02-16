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

    ck_assert_int_eq((int)s21_ch_1, (int) ch_1 );
    ck_assert_int_eq((int)s21_ch_2, (int) ch_2 );
    ck_assert_int_eq((int)s21_ch_3, (int) ch_3 );

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

    ck_assert_int_eq((int)s21_ch_1, (int) ch_1 );
    ck_assert_int_eq((int)s21_ch_2, (int) ch_2 );
    ck_assert_int_eq((int)s21_ch_3, (int) ch_3 );

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

        ck_assert_int_eq((int)s21_ch_1, (int) ch_1 );
        ck_assert_int_eq((int)s21_ch_2, (int) ch_2 );
        ck_assert_int_eq((int)s21_ch_3, (int) ch_3 );


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

    ck_assert_int_eq((int)s21_ch_1, (int) ch_1 );
    ck_assert_int_eq((int)s21_ch_2, (int) ch_2 );
    ck_assert_int_eq((int)s21_ch_3, (int) ch_3 );
}
END_TEST

START_TEST(sscanf_test_4) {
    int a;
    int b;
    s21_sscanf("228", "%d", &a);
    sscanf("228", "%d", &b);

    ck_assert_int_eq( a, b);

}
END_TEST

START_TEST(sscanf_test_5) {
    int a;
    int b;
    s21_sscanf("my number 228", "my number     %d", &a);
    sscanf("my number 228", "my number     %d", &b);

    ck_assert_int_eq( a, b);

}
END_TEST

START_TEST(sscanf_test_6) {
    int a;
    int b;
    s21_sscanf("my number 228", "my number %d", &a);
    sscanf("my number 228", "my number %d", &b);

    ck_assert_int_eq( a, b);

}
END_TEST

START_TEST(sscanf_test_7) {
    int a;
    int b;
    s21_sscanf("my number 228", "my number%d", &a);
    sscanf("my number 228", "my number%d", &b);

    ck_assert_int_eq( a, b);

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







    return s;
}