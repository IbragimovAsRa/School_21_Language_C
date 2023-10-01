#include "21_test.h"

// 0 - OK
// 1 - ошибка вычисления

START_TEST(test_decimal_to_int_1) {
    int a = 0;
    s21_decimal dec1 = {
        {0b00000000000000000000000001111011, 0b00000000000000000000000000000000,
         0b00000000000000000000000000000000,
         0b10000000000000000000000000000000}};  // тестируемое число: 123
    s21_from_decimal_to_int(dec1, &a);
    ck_assert_int_eq(-123, a);
}
END_TEST

START_TEST(test_decimal_to_int_2) {
    int a = 0;
    s21_decimal dec1 = {{0b00000000001100001111111101101010,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000}};
    s21_from_decimal_to_int(dec1, &a);
    ck_assert_int_eq(3211114, a);
}
END_TEST

START_TEST(test_decimal_to_int_3) {
    int a = 0;
    s21_decimal dec1 = {{0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000}};
    s21_from_decimal_to_int(dec1, &a);
    ck_assert_int_eq(0, a);
}
END_TEST

START_TEST(test_decimal_to_int_4) {
    int a = 0;
    s21_decimal dec1 = {{0b00000000000000010100110000000001,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000}};
    s21_from_decimal_to_int(dec1, &a);
    ck_assert_int_eq(84993, a);
}
END_TEST

START_TEST(test_decimal_to_int_5) {
    int a = 0;
    s21_decimal dec1 = {{0b00000000000000010100110000000001,
                         0b00000100010000000001000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000}};
    s21_from_decimal_to_int(dec1, &a);
    ck_assert_int_eq(s21_from_decimal_to_int(dec1, &a), 1);
}
END_TEST

START_TEST(test_decimal_to_int_6) {
    int a = 0;
    s21_decimal dec1 = {{0b00000000011000101100100001010100,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000100000000000000000}};
    s21_from_decimal_to_int(dec1, &a);
    ck_assert_int_eq(64738, a);
}
END_TEST

START_TEST(test_decimal_to_int_7) {
    int a = 0;
    s21_decimal dec1 = {{0b00000000001011111100011101100010,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000001000000000000000000}};
    s21_from_decimal_to_int(dec1, &a);
    ck_assert_int_eq(313, a);
}
END_TEST

START_TEST(test_decimal_to_int_8) {
    int a = 0;
    s21_decimal dec1 = {{0b00000000000100010010010001011001,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000100000000000000000}};
    s21_from_decimal_to_int(dec1, &a);
    ck_assert_int_eq(11234, a);
}
END_TEST

START_TEST(test_decimal_to_int_9) {
    int a = 0;
    s21_decimal dec1 = {{0b00000000000100101101011010000111,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000}};
    s21_from_decimal_to_int(dec1, &a);
    ck_assert_int_eq(1234567, a);
}
END_TEST

Suite *test_decimal_to_int(void) {
    Suite *s = suite_create("\033[45m-=S21_DECIMAL_TO_INT=-\033[0m");
    TCase *tc = tcase_create("test_decimal_to_int");

    tcase_add_test(tc, test_decimal_to_int_1);
    tcase_add_test(tc, test_decimal_to_int_2);
    tcase_add_test(tc, test_decimal_to_int_3);
    tcase_add_test(tc, test_decimal_to_int_4);
    tcase_add_test(tc, test_decimal_to_int_5);
    tcase_add_test(tc, test_decimal_to_int_6);
    tcase_add_test(tc, test_decimal_to_int_7);
    tcase_add_test(tc, test_decimal_to_int_8);
    tcase_add_test(tc, test_decimal_to_int_9);

    suite_add_tcase(s, tc);
    return s;
}