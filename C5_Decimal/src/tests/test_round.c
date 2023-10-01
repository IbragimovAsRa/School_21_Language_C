#include "21_test.h"

// 0 - OK
// 1 - ошибка вычисления

START_TEST(test_round_1) {
    s21_decimal val = {{7, 7, 7, 0}};
    s21_decimal res = {0};
    s21_round(val, &res);
    float fres = 0;
    s21_from_decimal_to_float(res, &fres);
    float need = 129127208515966861312.0;
    ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(test_round_2) {
    s21_decimal val = {{3, 3, 3, ~(UINT_MAX / 2)}};
    s21_decimal res = {0};
    ck_assert_int_eq(0, s21_round(val, &res));
}
END_TEST

START_TEST(test_round_3) {
    s21_decimal val = {};
    s21_decimal res = {};
    s21_decimal tmp = {};
    convertStr2Dec("12345.6789", &val);
    convertStr2Dec("12346", &tmp);

    ck_assert_int_eq(0, s21_round(val, &res));
    ck_assert_int_eq(s21_is_equal(res, tmp), 1);
}
END_TEST

START_TEST(test_round_4) {
    s21_decimal val = {};
    s21_decimal res = {};
    convertStr2Dec("-12345.6789", &val);

    ck_assert_int_eq(0, s21_round(val, &res));
}
END_TEST

START_TEST(test_round_5) {
    s21_decimal val = {};
    s21_decimal res = {};
    s21_decimal tmp = {};
    convertStr2Dec("123123445.6789", &val);
    convertStr2Dec("123123446", &tmp);

    ck_assert_int_eq(0, s21_round(val, &res));
    ck_assert_int_eq(s21_is_equal(res, tmp), 1);
}
END_TEST

START_TEST(test_round_6) {
    s21_decimal val = {};
    s21_decimal res = {};
    s21_decimal tmp = {};
    convertStr2Dec("-79228162514264337593543.0335", &val);
    convertStr2Dec("-79228162514264337593543", &tmp);

    ck_assert_int_eq(0, s21_round(val, &res));
    ck_assert_int_eq(s21_is_equal(res, tmp), 1);
}
END_TEST

#include "21_test.h"

// 0 - OK
// 1 - ошибка вычисления

START_TEST(test_round_7) {
    s21_decimal val = {};
    s21_decimal res = {};
    s21_decimal tmp = {};
    convertStr2Dec("-792281625142693543.00335", &val);
    convertStr2Dec("-792281625142693543", &tmp);

    ck_assert_int_eq(0, s21_round(val, &res));
    ck_assert_int_eq(s21_is_equal(res, tmp), 1);
}
END_TEST

START_TEST(test_round_8) {
    s21_decimal val = {};
    s21_decimal res = {};
    s21_decimal tmp = {};
    convertStr2Dec("251426543.0012335", &val);
    convertStr2Dec("251426543", &tmp);

    ck_assert_int_eq(0, s21_round(val, &res));
    ck_assert_int_eq(s21_is_equal(res, tmp), 1);
}
END_TEST

START_TEST(test_round_9) {
    s21_decimal val = {};
    s21_decimal res = {};
    s21_decimal tmp = {};
    convertStr2Dec("-12345.6000789", &val);
    convertStr2Dec("-12346", &tmp);

    ck_assert_int_eq(0, s21_round(val, &res));
    ck_assert_int_eq(s21_is_equal(res, tmp), 1);
}
END_TEST

START_TEST(test_round_10) {
    s21_decimal val = {};
    s21_decimal res = {};
    s21_decimal tmp = {};
    convertStr2Dec("-2514263.00012335", &val);
    convertStr2Dec("-2514263", &tmp);

    ck_assert_int_eq(0, s21_round(val, &res));
    ck_assert_int_eq(s21_is_equal(res, tmp), 1);
}
END_TEST

START_TEST(test_round_11) {
    s21_decimal val = {};
    s21_decimal res = {};
    s21_decimal tmp = {};
    convertStr2Dec("1234989345.6789", &val);
    convertStr2Dec("1234989346", &tmp);

    ck_assert_int_eq(0, s21_round(val, &res));
    ck_assert_int_eq(s21_is_equal(res, tmp), 1);
}
END_TEST

START_TEST(test_round_12) {
    s21_decimal val = {};
    s21_decimal res = {};
    s21_decimal tmp = {};
    convertStr2Dec("-12345000.678900", &val);
    convertStr2Dec("-12345001", &tmp);

    ck_assert_int_eq(0, s21_round(val, &res));
    ck_assert_int_eq(s21_is_equal(res, tmp), 1);
}
END_TEST

Suite *test_round(void) {
    Suite *s = suite_create("\033[45m-=S21_ROUND=-\033[0m");
    TCase *tc = tcase_create("test_round");

    tcase_add_test(tc, test_round_1);
    tcase_add_test(tc, test_round_2);
    tcase_add_test(tc, test_round_3);
    tcase_add_test(tc, test_round_4);
    tcase_add_test(tc, test_round_5);
    tcase_add_test(tc, test_round_6);
    tcase_add_test(tc, test_round_7);
    tcase_add_test(tc, test_round_8);
    tcase_add_test(tc, test_round_9);
    tcase_add_test(tc, test_round_10);
    tcase_add_test(tc, test_round_11);
    tcase_add_test(tc, test_round_12);

    suite_add_tcase(s, tc);
    return s;
}