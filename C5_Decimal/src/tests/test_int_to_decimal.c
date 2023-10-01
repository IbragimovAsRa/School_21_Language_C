#include "21_test.h"

// 0 - OK
// 1 - ошибка вычисления

START_TEST(test_int_to_decimal_1) {
    s21_decimal a = {};
    s21_decimal b = {};
    convertStr2Dec("5", &a);
    s21_from_int_to_decimal(5, &b);
    ck_assert_int_eq(s21_is_equal(a, b), 1);
}
END_TEST

START_TEST(test_int_to_decimal_2) {
    s21_decimal a = {};
    s21_decimal b = {};
    convertStr2Dec("-5", &a);
    s21_from_int_to_decimal(-5, &b);
    ck_assert_int_eq(s21_is_equal(a, b), 1);
}
END_TEST

START_TEST(test_int_to_decimal_3) {
    s21_decimal a = {};
    s21_decimal b = {};
    convertStr2Dec("5345435", &a);
    s21_from_int_to_decimal(5345435, &b);
    ck_assert_int_eq(s21_is_equal(a, b), 1);
}
END_TEST

START_TEST(test_int_to_decimal_4) {
    s21_decimal a = {};
    s21_decimal b = {};
    convertStr2Dec("0", &a);
    s21_from_int_to_decimal(0, &b);
    ck_assert_int_eq(s21_is_equal(a, b), 1);
}
END_TEST

START_TEST(test_int_to_decimal_5) {
    s21_decimal a = {};
    s21_decimal b = {};
    convertStr2Dec("132456789", &a);
    s21_from_int_to_decimal(132456789, &b);
    ck_assert_int_eq(s21_is_equal(a, b), 1);
}
END_TEST

START_TEST(test_int_to_decimal_6) {
    s21_decimal a = {};
    s21_decimal b = {};
    convertStr2Dec("-1324567", &a);
    s21_from_int_to_decimal(-1324567, &b);
    ck_assert_int_eq(s21_is_equal(a, b), 1);
}
END_TEST

Suite *test_int_to_decimal(void) {
    Suite *s = suite_create("\033[45m-=S21_INT_TO_DECIMAL=-\033[0m");
    TCase *tc = tcase_create("test_int_to_decimal");

    tcase_add_test(tc, test_int_to_decimal_1);
    tcase_add_test(tc, test_int_to_decimal_2);
    tcase_add_test(tc, test_int_to_decimal_3);
    tcase_add_test(tc, test_int_to_decimal_4);
    tcase_add_test(tc, test_int_to_decimal_5);
    tcase_add_test(tc, test_int_to_decimal_6);

    suite_add_tcase(s, tc);
    return s;
}