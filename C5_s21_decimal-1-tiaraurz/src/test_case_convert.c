#include "test_convert.h"

//------------ test from int to decimal ------------------
START_TEST(convert_test_1) {   
    s21_decimal a = {};
    s21_decimal b = {};
    convertStr2Dec("5", &a);
    s21_from_int_to_decimal(5, &b);
    ck_assert_int_eq(s21_is_equal(a,b), 1);
}
END_TEST

START_TEST(convert_test_2) {   
    s21_decimal a = {};
    s21_decimal b = {};
    convertStr2Dec("-5", &a);
    s21_from_int_to_decimal(-5, &b);
    ck_assert_int_eq(s21_is_equal(a,b), 1);
}
END_TEST
//------------ test from float to decimal ------------------
START_TEST(convert_test_3) { 
    s21_decimal a = {};
    s21_decimal b = {};
    convertStr2Dec("758.321", &a);
    s21_from_float_to_decimal(758.321, &b);
    ck_assert_int_eq(s21_is_equal(a,b), 1);
}
END_TEST

START_TEST(convert_test_4) {
    s21_decimal a = {};
    s21_decimal b = {};
    convertStr2Dec("-758.321", &a);
    s21_from_float_to_decimal(-758.321, &b);
    ck_assert_int_eq(s21_is_equal(a,b), 1);
}
END_TEST

START_TEST(convert_test_5) {
    s21_decimal a = {};
    s21_decimal b = {};
    convertStr2Dec("758", &a);
    s21_from_float_to_decimal(758, &b);
    ck_assert_int_eq(s21_is_equal(a,b), 1);
}
END_TEST

START_TEST(convert_test_6) {
    s21_decimal a = {};
    s21_decimal b = {};
    convertStr2Dec("-758", &a);
    s21_from_float_to_decimal(-758, &b);
    ck_assert_int_eq(s21_is_equal(a,b), 1);
}
END_TEST



//------------ test from decimal to float ------------------
START_TEST(convert_test_7) {
    s21_decimal a = {};
    float dst;
    convertStr2Dec("-758", &a);
    s21_from_decimal_to_float(a, &dst);
    ck_assert_float_eq(dst, -758);
}
END_TEST

START_TEST(convert_test_8) {
    s21_decimal a = {};
    float dst;
    convertStr2Dec("758", &a);
    s21_from_decimal_to_float(a, &dst);
    ck_assert_float_eq(dst, 758);
}
END_TEST

START_TEST(convert_test_9) {
    s21_decimal a = {};
    float fl_a;
    float fl_b = 1234567;
    s21_from_float_to_decimal(1234567, &a);
    s21_from_decimal_to_float(a, &fl_a);
    ck_assert_float_eq(fl_a, fl_b);
}
END_TEST

START_TEST(convert_test_10) {
    s21_decimal a = {};
    float fl_a;
    float fl_b = -1234567;
    s21_from_float_to_decimal(-1234567, &a);
    s21_from_decimal_to_float(a, &fl_a);
    ck_assert_float_eq(fl_a, fl_b);
}
END_TEST


START_TEST(convert_test_11) {
    s21_decimal a = {};
    float fl_a;
    float fl_b = 0.1234567;
    s21_from_float_to_decimal(0.1234567, &a);
    s21_from_decimal_to_float(a, &fl_a);
    ck_assert_float_eq(fl_a, fl_b);
}
END_TEST


//------------ test from decimal to int------------------
Suite *get_suite_convert() {
    Suite *s = suite_create("convert_test suite ");
    TCase *tc = tcase_create("convert_test test case");
    suite_add_tcase(s, tc);

    tcase_add_test(tc, convert_test_1);
    tcase_add_test(tc, convert_test_2);
    tcase_add_test(tc, convert_test_3);
    tcase_add_test(tc, convert_test_4);
    tcase_add_test(tc, convert_test_5);
    tcase_add_test(tc, convert_test_6);
    tcase_add_test(tc, convert_test_7);
    tcase_add_test(tc, convert_test_8);
    tcase_add_test(tc, convert_test_9);
    tcase_add_test(tc, convert_test_10);
    tcase_add_test(tc, convert_test_11);




    return s;
}
