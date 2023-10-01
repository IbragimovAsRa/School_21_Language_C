#include "21_test.h"

// 0 - OK
// 1 - ошибка вычисления

START_TEST(test_floor_3) {
    s21_decimal val = {};
    s21_decimal res = {};
    s21_decimal tmp = {};
    convertStr2Dec("12345.6789", &val);
    convertStr2Dec("12345", &tmp);

    ck_assert_int_eq(0, s21_floor(val, &res));
    ck_assert_int_eq(s21_is_equal(res, tmp), 1);
}
END_TEST

START_TEST(test_floor_4) {
    s21_decimal val = {};
    s21_decimal res = {};
    convertStr2Dec("-12345.6789", &val);

    ck_assert_int_eq(0, s21_floor(val, &res));
}
END_TEST

START_TEST(test_floor_5) {
    s21_decimal val = {};
    s21_decimal res = {};
    s21_decimal tmp = {};
    convertStr2Dec("123123445.6789", &val);
    convertStr2Dec("123123445", &tmp);

    ck_assert_int_eq(0, s21_floor(val, &res));
    ck_assert_int_eq(s21_is_equal(res, tmp), 1);
}
END_TEST

START_TEST(test_floor_6) {
    s21_decimal val = {};
    s21_decimal res = {};
    s21_decimal tmp = {};
    convertStr2Dec("-79228162514264337593543.0335", &val);
    convertStr2Dec("-79228162514264337593544", &tmp);

    ck_assert_int_eq(0, s21_floor(val, &res));
    ck_assert_int_eq(s21_is_equal(res, tmp), 1);
}
END_TEST

#include "21_test.h"

// 0 - OK
// 1 - ошибка вычисления

START_TEST(test_floor_7) {
    s21_decimal val = {};
    s21_decimal res = {};
    s21_decimal tmp = {};
    convertStr2Dec("-792281625142693543.00335", &val);
    convertStr2Dec("-792281625142693544", &tmp);

    ck_assert_int_eq(0, s21_floor(val, &res));
    ck_assert_int_eq(s21_is_equal(res, tmp), 1);
}
END_TEST

START_TEST(test_floor_8) {
    s21_decimal val = {};
    s21_decimal res = {};
    s21_decimal tmp = {};
    convertStr2Dec("251426543.0012335", &val);
    convertStr2Dec("251426543", &tmp);

    ck_assert_int_eq(0, s21_floor(val, &res));
    ck_assert_int_eq(s21_is_equal(res, tmp), 1);
}
END_TEST

START_TEST(test_floor_9) {
    s21_decimal val = {};
    s21_decimal res = {};
    s21_decimal tmp = {};
    convertStr2Dec("-12345.6000789", &val);
    convertStr2Dec("-12346", &tmp);

    ck_assert_int_eq(0, s21_floor(val, &res));
    ck_assert_int_eq(s21_is_equal(res, tmp), 1);
}
END_TEST

START_TEST(test_floor_10) {
    s21_decimal val = {};
    s21_decimal res = {};
    s21_decimal tmp = {};
    convertStr2Dec("-2514263.00012335", &val);
    convertStr2Dec("-2514264", &tmp);

    ck_assert_int_eq(0, s21_floor(val, &res));
    ck_assert_int_eq(s21_is_equal(res, tmp), 1);
}
END_TEST

START_TEST(test_floor_11) {
    s21_decimal val = {};
    s21_decimal res = {};
    s21_decimal tmp = {};
    convertStr2Dec("1234989345.6789", &val);
    convertStr2Dec("1234989345", &tmp);

    ck_assert_int_eq(0, s21_floor(val, &res));
    ck_assert_int_eq(s21_is_equal(res, tmp), 1);
}
END_TEST

START_TEST(test_floor_12) {
    s21_decimal val = {};
    s21_decimal res = {};
    s21_decimal tmp = {};
    convertStr2Dec("-12345000.678900", &val);
    convertStr2Dec("-12345001", &tmp);

    ck_assert_int_eq(0, s21_floor(val, &res));
    ck_assert_int_eq(s21_is_equal(res, tmp), 1);
}
END_TEST

Suite *test_floor(void) {
    Suite *s = suite_create("\033[45m-=S21_FLOOR=-\033[0m");
    TCase *tc = tcase_create("test_floor");

    tcase_add_test(tc, test_floor_3);
    tcase_add_test(tc, test_floor_4);
    tcase_add_test(tc, test_floor_5);
    tcase_add_test(tc, test_floor_6);
    tcase_add_test(tc, test_floor_7);
    tcase_add_test(tc, test_floor_8);
    tcase_add_test(tc, test_floor_9);
    tcase_add_test(tc, test_floor_10);
    tcase_add_test(tc, test_floor_11);
    tcase_add_test(tc, test_floor_12);

    suite_add_tcase(s, tc);
    return s;
}