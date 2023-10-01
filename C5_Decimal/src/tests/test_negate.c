#include "21_test.h"
#define S21_MAX_UINT 4294967295

// 0 - OK
// 1 - ошибка вычисления

START_TEST(test_negate_1) {
    s21_decimal val = {{2, 0, 0, 0}};
    s21_decimal res = {0};
    int sign_before = isSetBit(val.bits, 127);
    s21_negate(val, &res);
    int sign_after = 1;

    ck_assert_int_ne(sign_before, sign_after);
}
END_TEST

START_TEST(test_negate_2) {
    s21_decimal val = {0};
    s21_decimal res = {0};

    convertStr2Dec("-12", &val);

    int sign_before = isSetBit(val.bits, 127);
    s21_negate(val, &res);
    int sign_after = 0;
    ck_assert_int_ne(sign_before, sign_after);
}
END_TEST

START_TEST(negate_0) {
    s21_decimal val = {{2, 0, 0, 0}};
    s21_decimal res = {0};
    ck_assert_int_eq(0, s21_negate(val, &res));
}
END_TEST

START_TEST(negate_1) {
    s21_decimal val = {{2, 0, 0, ~(S21_MAX_UINT / 2)}};
    s21_decimal res = {0};
    ck_assert_int_eq(0, s21_negate(val, &res));
}
END_TEST

START_TEST(negate_2) {
    s21_decimal val = {{0, 0, 0, ~(S21_MAX_UINT / 2)}};
    s21_decimal res = {0};
    ck_assert_int_eq(0, s21_negate(val, &res));
}
END_TEST

START_TEST(negate_3) {
    s21_decimal val = {0};
    s21_decimal res = {0};
    ck_assert_int_eq(1, s21_negate(val, &res));
}
END_TEST

Suite *test_negate(void) {
    Suite *s = suite_create("\033[45m-=TEST_NEGATE=-\033[0m");
    TCase *tc = tcase_create("test_negate");

    tcase_add_test(tc, test_negate_1);
    tcase_add_test(tc, test_negate_2);
    tcase_add_test(tc, negate_0);
    tcase_add_test(tc, negate_1);
    tcase_add_test(tc, negate_2);
    tcase_add_test(tc, negate_3);

    suite_add_tcase(s, tc);
    return s;
}