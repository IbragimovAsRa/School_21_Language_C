#include "21_test.h"

// 0 - OK
// 1 - ошибка вычисления

START_TEST(test_truncate_1) {
    s21_decimal val = {0};
    s21_decimal res = {0};
    s21_decimal tmp = {0};
    convertStr2Dec("7922816251426433759354395.0335", &val);
    convertStr2Dec("7922816251426433759354395", &tmp);

    s21_truncate(val, &res);

    ck_assert_int_eq(s21_is_equal(res, tmp), 1);
}
END_TEST

START_TEST(test_truncate_2) {
    s21_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
    s21_decimal res = {0};
    ck_assert_int_eq(0, s21_truncate(val, &res));
    float fres = 0;
    s21_from_decimal_to_float(res, &fres);
    float need = -2.0;
    ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(test_truncate_3) {
    s21_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
    s21_decimal res = {0};
    ck_assert_int_eq(0, s21_truncate(val, &res));
    float fres = 0;
    s21_from_decimal_to_float(res, &fres);
    float need = -2.0;
    ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(test_truncate_5) {
    s21_decimal val = {{128, 0, 0, 0}};
    s21_decimal res = {0};
    // setScale(&val, 1);
    val.pat.exp = 1;
    ck_assert_int_eq(0, s21_truncate(val, &res));
    float fres = 0;
    s21_from_decimal_to_float(res, &fres);
    float need = 12;
    ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(test_truncate_6) {
    s21_decimal val = {0};
    s21_decimal res = {0};
    s21_decimal tmp = {0};
    convertStr2Dec("7922816251426433759354395033.5", &val);
    convertStr2Dec("7922816251426433759354395033", &tmp);

    s21_truncate(val, &res);

    ck_assert_int_eq(s21_is_equal(res, tmp), 1);
}
END_TEST

START_TEST(test_truncate_7) {
    s21_decimal val = {0};
    s21_decimal res = {0};
    s21_decimal tmp = {0};
    convertStr2Dec("79228162514264337593543950335", &val);
    convertStr2Dec("79228162514264337593543950335", &tmp);

    s21_truncate(val, &res);

    ck_assert_int_eq(s21_is_equal(res, tmp), 1);
}
END_TEST

START_TEST(test_truncate_8) {
    s21_decimal val = {0};
    s21_decimal res = {0};
    s21_decimal tmp = {0};
    convertStr2Dec("-7922816251426433759354395033.5", &val);
    convertStr2Dec("-7922816251426433759354395033", &tmp);

    s21_truncate(val, &res);

    ck_assert_int_eq(s21_is_equal(res, tmp), 1);
}
END_TEST

START_TEST(test_truncate_9) {
    s21_decimal val = {0};
    s21_decimal res = {0};
    s21_decimal tmp = {0};
    convertStr2Dec("-79228162514264337593543950335", &val);
    convertStr2Dec("-79228162514264337593543950335", &tmp);

    s21_truncate(val, &res);

    ck_assert_int_eq(s21_is_equal(res, tmp), 1);
}
END_TEST

START_TEST(test_truncate_10) {
    s21_decimal val = {};
    s21_decimal res = {};
    s21_decimal tmp = {};
    convertStr2Dec("-79228162514264337593543950335", &val);
    convertStr2Dec("-79228162514264337593543950335", &tmp);

    s21_truncate(val, &res);

    ck_assert_int_eq(s21_is_equal(res, tmp), 1);
}
END_TEST

Suite *test_truncate(void) {
    Suite *s = suite_create("\033[45m-=S21_TRUNCATE=-\033[0m");
    TCase *tc = tcase_create("test_truncate");

    tcase_add_test(tc, test_truncate_1);
    tcase_add_test(tc, test_truncate_2);
    tcase_add_test(tc, test_truncate_3);
    tcase_add_test(tc, test_truncate_5);
    tcase_add_test(tc, test_truncate_6);
    tcase_add_test(tc, test_truncate_7);
    tcase_add_test(tc, test_truncate_8);
    tcase_add_test(tc, test_truncate_9);
    tcase_add_test(tc, test_truncate_10);

    suite_add_tcase(s, tc);
    return s;
}