#include "21_test.h"

// 0 - OK
// 1 - ошибка вычисления

START_TEST(test_decimal_to_float_1) {
    float a = 123.321;
    float b;
    s21_decimal dec = {{0b00000000000000011110000110111001,
                        0b00000000000000000000000000000000,
                        0b00000000000000000000000000000000,
                        0b00000000000000110000000000000000}};
    s21_from_decimal_to_float(dec, &b);
    ck_assert_float_eq_tol(a, b, 0.001);
}
END_TEST

START_TEST(test_decimal_to_float_2) {
    float a = 313.1234;
    float b;
    s21_decimal dec = {{0b00000000001011111100011101100010,
                        0b00000000000000000000000000000000,
                        0b00000000000000000000000000000000,
                        0b00000000000001000000000000000000}};
    s21_from_decimal_to_float(dec, &b);
    ck_assert_float_eq_tol(a, b, 0.001);
}
END_TEST

START_TEST(test_decimal_to_float_3) {
    float a = 123423.13123;
    float b;
    s21_decimal dec = {{0b00000000000100101101010100110111,
                        0b00000000000000000000000000000000,
                        0b00000000000000000000000000000000,
                        0b00000000000000010000000000000000}};
    s21_from_decimal_to_float(dec, &b);
    ck_assert_float_eq_tol(a, b, 0.1);
}
END_TEST

START_TEST(test_decimal_to_float_4) {
    float a = 1234.4321;
    float b;
    s21_decimal dec = {{0b00000000000100101101011000000000,
                        0b00000000000000000000000000000000,
                        0b00000000000000000000000000000000,
                        0b00000000000000110000000000000000}};
    s21_from_decimal_to_float(dec, &b);
    ck_assert_float_eq_tol(a, b, 0.001);
}
END_TEST

START_TEST(test_decimal_to_float_5) {
    float a = 12345;
    float b;
    s21_decimal dec = {{0b00000000000000000011000000111001,
                        0b00000000000000000000000000000000,
                        0b00000000000000000000000000000000,
                        0b00000000000000000000000000000000}};
    s21_from_decimal_to_float(dec, &b);
    ck_assert_float_eq_tol(a, b, 0.001);
}
END_TEST

START_TEST(test_decimal_to_float_6) {
    float a = 123456789987654321;
    float b;
    s21_decimal dec = {{0b00110101000110110100000000000000,
                        0b00000001101101101001101101001110,
                        0b00000000000000000000000000000000,
                        0b00000000000000000000000000000000}};
    s21_from_decimal_to_float(dec, &b);
    ck_assert_float_eq_tol(a, b, 10000000000);
}
END_TEST

START_TEST(test_decimal_to_float_7) {
    float a = 123456789987654321.123881193;
    float b;
    s21_decimal dec = {{0b00110101000110110100000000000000,
                        0b00000001101101101001101101001110,
                        0b00000000000000000000000000000000,
                        0b00000000000000000000000000000000}};
    s21_from_decimal_to_float(dec, &b);
    ck_assert_float_eq_tol(a, b, 10000000000);
}
END_TEST

START_TEST(test_decimal_to_float_8) {
    float a = 0.0000000000001234567;
    float b;
    s21_decimal dec = {{0b00000000000100101101011010000111,
                        0b00000000000000000000000000000000,
                        0b00000000000000000000000000000000,
                        0b00000000000100110000000000000000}};
    s21_from_decimal_to_float(dec, &b);
    ck_assert_float_eq_tol(a, b, 0.0000000000000000001);
}
END_TEST

START_TEST(test_decimal_to_float_9) {
    float a = 0.0000000000000001234;
    float b;
    s21_decimal dec = {{0b00000000000000000000010011010010,
                        0b00000000000000000000000000000000,
                        0b00000000000000000000000000000000,
                        0b00000000000100110000000000000000}};
    s21_from_decimal_to_float(dec, &b);
    ck_assert_float_eq_tol(a, b, 0.0000000000000000001);
}
END_TEST

START_TEST(test_decimal_to_float_10) {
    float a = 0.000000000000000123456789;
    float b;
    s21_decimal dec = {{0b00000000000100101101011010001000,
                        0b00000000000000000000000000000000,
                        0b00000000000000000000000000000000,
                        0b00000000000101100000000000000000}};
    s21_from_decimal_to_float(dec, &b);
    ck_assert_float_eq_tol(a, b, 0.0000000000000000001);
}
END_TEST

Suite *test_decimal_to_float(void) {
    Suite *s = suite_create("\033[45m-=S21_DECIMAL_TO_FLOAT=-\033[0m");
    TCase *tc = tcase_create("test_decimal_to_float");

    tcase_add_test(tc, test_decimal_to_float_1);
    tcase_add_test(tc, test_decimal_to_float_2);
    tcase_add_test(tc, test_decimal_to_float_3);
    tcase_add_test(tc, test_decimal_to_float_4);
    tcase_add_test(tc, test_decimal_to_float_5);
    tcase_add_test(tc, test_decimal_to_float_6);
    tcase_add_test(tc, test_decimal_to_float_7);
    tcase_add_test(tc, test_decimal_to_float_8);
    tcase_add_test(tc, test_decimal_to_float_9);
    tcase_add_test(tc, test_decimal_to_float_10);

    suite_add_tcase(s, tc);
    return s;
}