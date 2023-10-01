#include "21_test.h"

// 0 - OK
// 1 - ошибка вычисления

START_TEST(test_float_to_decimal_1) {
    s21_decimal dec1 = {{0b00000000000010111001001000110001,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000110000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(758.321, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST

START_TEST(test_float_to_decimal_2) {
    s21_decimal dec1 = {{0b00000000000000011111010110001000,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000001010000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(1.28392, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST

START_TEST(test_float_to_decimal_3) {
    s21_decimal dec1 = {{0b00000000000100101100100100010011,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000110000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(1231.123123, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST

START_TEST(test_float_to_decimal_4) {
    s21_decimal dec1 = {{0b00000000000001010010011011101011,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000001000000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(33.7643, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST

START_TEST(test_float_to_decimal_5) {
    s21_decimal dec1 = {{0b00000000001011100001001110111111,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000100000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(30197.11022, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST

START_TEST(test_float_to_decimal_6) {
    s21_decimal dec1 = {{0b00000000010100101110011101110010,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000110000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(5433.2016, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST

START_TEST(test_float_to_decimal_7) {
    s21_decimal dec1 = {{0b00000000000011110111110000001011,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000100000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(10147.9498, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST

START_TEST(test_float_to_decimal_8) {
    s21_decimal dec1 = {{0b00000000000000111001110010001010,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000010000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(23668.20292, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST

START_TEST(test_float_to_decimal_9) {
    s21_decimal val = {};
    s21_decimal check = {};
    float res = 1;
    float tmp = -12345678901234;
    convertStr2Dec("12345678901234", &check);

    s21_from_float_to_decimal(tmp, &val);
    s21_from_decimal_to_float(val, &res);

    ck_assert_float_eq(res, tmp);
}
END_TEST

START_TEST(test_float_to_decimal_10) {
    s21_decimal val = {};
    s21_decimal check = {};
    float res = 1;
    float tmp = 123;
    convertStr2Dec("-123", &check);

    s21_from_float_to_decimal(tmp, &val);
    s21_from_decimal_to_float(val, &res);

    ck_assert_float_eq(res, tmp);
}
END_TEST

START_TEST(convert_test_3) {
    s21_decimal dec1 = {{0b00000000000010111001001000110001,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000110000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(758.321, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST

// в памяти хранится как 1.28392004
START_TEST(convert_test_4) {
    s21_decimal dec1 = {{0b00000000000000011111010110001000,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000001010000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(1.28392, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST

START_TEST(convert_test_5) {
    s21_decimal dec1 = {{0b00000000000100101100100100010011,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000110000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(1231.123123, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST

START_TEST(convert_test_6) {
    s21_decimal dec1 = {{0b00000000000001010010011011101011,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000001000000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(33.7643, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_7) {
    s21_decimal dec1 = {{0b00000000001011100001001110111111,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000100000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(30197.11022, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(
    convert_test_8)  // тест провален, не сработало
                     // округление------------------------------------------------------
{
    s21_decimal dec1 = {{0b00000000010100101110011101110010,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000110000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(5433.2016, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_9) {
    s21_decimal dec1 = {{0b00000000000011110111110000001011,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000100000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(10147.9498, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_10) {
    s21_decimal dec1 = {{0b00000000000000111001110010001010,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000010000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(23668.20292, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_11) {
    s21_decimal dec1 = {{0b00000000010000001100001100101001,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000110000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(4244.2645, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_12) {
    s21_decimal dec1 = {{0b00000000000100101001011110110110,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000100000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(12184.8645, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_13) {
    s21_decimal dec1 = {{0b00000000000110100110000110011101,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000100000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(17289.24961, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_14) {
    s21_decimal dec1 = {{0b00000000000101100111000010100100,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000100000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(14706.27645, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_15) {
    s21_decimal dec1 = {{0b00000000100100110011100101001110,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000110000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(9648.4622, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_16) {
    s21_decimal dec1 = {{0b00000000010000011010000110101001,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000110000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(4301.22499, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_17) {
    s21_decimal dec1 = {{0b00000000000011111110101101111011,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000100000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(10433.22676, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_18) {
    s21_decimal dec1 = {{0b00000000001011100000111011111111,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000100000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(30184.9491, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_19) {
    s21_decimal dec1 = {{0b01101111010111000100100100011000,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(1868319037.2713922971, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_20) {
    s21_decimal dec1 = {{0b00000000110100001111010000010010,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(13693973.118992681, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_21) {
    s21_decimal dec1 = {{0b10101010001010101001101101011000,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(2854918600.306138834, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_22) {
    s21_decimal dec1 = {{0b01110100011010100100001011101000,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(1953120642.414020268, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_23) {
    s21_decimal dec1 = {{0b01110111011001010011111100100000,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(2003124506.1736817812, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST

START_TEST(convert_test_24) {
    s21_decimal dec1 = {{0b00000000000101101100100011101111,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000100000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(14932.306821687010898, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_25) {
    s21_decimal dec1 = {{0b00000000001100010001111100011100,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000100000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(32192.280446914238, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_26) {
    s21_decimal dec1 = {{0b00000000000100110100001010010011,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000100000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(12622.27362248727702, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_27) {
    s21_decimal dec1 = {{0b00000000000101100001111111001100,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000100000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(14499.314992658929398, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_28) {
    s21_decimal dec1 = {{0b00000000000101011111001001111001,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000100000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(14383.28843267568098, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_29) {
    s21_decimal dec1 = {{0b00000000001100010010000000111011,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000100000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(32195.149871255614037, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_30) {
    s21_decimal dec1 = {{0b00000000000000111000101000000111,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000010000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(23194.30039273514660, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_31) {
    s21_decimal dec1 = {{0b00000000000101111100110010101110,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000100000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(15597.2646263167171, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_32) {
    s21_decimal dec1 = {{0b00000000001100100101001111010011,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000110000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(3298.259292552523426, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST

START_TEST(convert_test_33) {
    s21_decimal dec1 = {{0b00000000001100010000111000010111,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000001100000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(3.21487146222795, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_34) {
    s21_decimal dec1 = {{0b00000000001110010100000111100101,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000001100000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(3.75242068227050, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_35) {
    s21_decimal dec1 = {{0b00000000001100100111111000100100,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000001100000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(3.30909174142457, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_36) {
    s21_decimal dec1 = {{0b00000000001100000110011011010011,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000001100000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(3.172051113317525, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_37) {
    s21_decimal dec1 = {{0b00000000001100100110101000010101,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000001100000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(3.3039566166822, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_38) {
    s21_decimal dec1 = {{0b00000000001110100000101111101000,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000001100000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(3.8041358725423, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_39) {
    s21_decimal dec1 = {{0b00000000001100111011010110011100,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000001100000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(3.3888277473437, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_40) {
    s21_decimal dec1 = {{0b00000000001100100001110101110110,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000001100000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(3.284341656024072, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_41) {
    s21_decimal dec1 = {{0b00000000001011111011010000111101,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000001100000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(3.12633320778629, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_42) {
    s21_decimal dec1 = {{0b00000000000001000110101011110011,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000100100000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(0.00000000000028952299113286, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_43) {
    s21_decimal dec1 = {{0b00000000000101011010101011110101,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000100110000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(0.000000000000142002120117372, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_44) {
    s21_decimal dec1 = {{0b00000000000101111100011000001011,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000100110000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(0.0000000000001558027209965, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_45) {
    s21_decimal dec1 = {{0b00000000001000100000011011111111,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000100110000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(0.0000000000002230015347271, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_46) {
    s21_decimal dec1 = {{0b00000000001001001100011110101101,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000100110000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(0.000000000000241041321731608, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_47) {
    s21_decimal dec1 = {{0b00000000001011111101110111111000,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000100110000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(0.000000000000313701639030640, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_48) {
    s21_decimal dec1 = {{0b00000000001011011101100111111010,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000100110000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(0.000000000000300492198310478, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_49) {
    s21_decimal dec1 = {{0b00000000001001111111001100001110,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000100110000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(0.00000000000026181260105670, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_50) {
    s21_decimal dec1 = {{0b00000000010010101011000110001110,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000100110000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(0.000000000000489511805733, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST

START_TEST(convert_test_51) {
    s21_decimal dec1 = {{0b00011100001011010001100000000000,
                         0b00000001011111010001111110010111,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(107276657202566773, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_52) {
    s21_decimal dec1 = {{0b11000110010000001011000000000000,
                         0b00100111110111011111110110011111,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(2872730828196917707, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_53) {
    s21_decimal dec1 = {{0b00001011010010010111000000000000,
                         0b01101110011100001110101100010001,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(7958119042533210307, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_54) {
    s21_decimal dec1 = {{0b11111001111111000111000000000000,
                         0b00001110001111111001110000110110,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(1026711306113892066, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST
START_TEST(convert_test_55) {
    s21_decimal dec1 = {{0b00101101111111110111000000000000,
                         0b00011000010000011101001111001011,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000}};
    s21_decimal dec2 = {};
    s21_from_float_to_decimal(1747910932760212141, &dec2);
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST

Suite *test_float_to_decimal(void) {
    Suite *s = suite_create("\033[45m-=S21_FLOAT_TO_DECIMAL=-\033[0m");
    TCase *tc = tcase_create("test_float_to_decimal");

    tcase_add_test(tc, test_float_to_decimal_1);
    tcase_add_test(tc, test_float_to_decimal_2);
    tcase_add_test(tc, test_float_to_decimal_3);
    tcase_add_test(tc, test_float_to_decimal_4);
    tcase_add_test(tc, test_float_to_decimal_5);
    tcase_add_test(tc, test_float_to_decimal_6);
    tcase_add_test(tc, test_float_to_decimal_7);
    tcase_add_test(tc, test_float_to_decimal_8);
    tcase_add_test(tc, test_float_to_decimal_9);
    tcase_add_test(tc, test_float_to_decimal_10);

    tcase_add_test(tc, convert_test_3);
    tcase_add_test(tc, convert_test_4);
    tcase_add_test(tc, convert_test_5);
    tcase_add_test(tc, convert_test_6);
    tcase_add_test(tc, convert_test_7);
    tcase_add_test(tc, convert_test_8);
    tcase_add_test(tc, convert_test_9);
    tcase_add_test(tc, convert_test_10);
    tcase_add_test(tc, convert_test_11);
    tcase_add_test(tc, convert_test_12);
    tcase_add_test(tc, convert_test_13);
    tcase_add_test(tc, convert_test_14);
    tcase_add_test(tc, convert_test_15);
    tcase_add_test(tc, convert_test_16);
    tcase_add_test(tc, convert_test_17);
    tcase_add_test(tc, convert_test_18);
    tcase_add_test(tc, convert_test_19);
    tcase_add_test(tc, convert_test_20);
    tcase_add_test(tc, convert_test_21);
    tcase_add_test(tc, convert_test_22);
    tcase_add_test(tc, convert_test_23);
    tcase_add_test(tc, convert_test_24);
    tcase_add_test(tc, convert_test_25);
    tcase_add_test(tc, convert_test_26);
    tcase_add_test(tc, convert_test_27);
    tcase_add_test(tc, convert_test_28);
    tcase_add_test(tc, convert_test_29);
    tcase_add_test(tc, convert_test_30);
    tcase_add_test(tc, convert_test_31);
    tcase_add_test(tc, convert_test_32);
    tcase_add_test(tc, convert_test_33);
    tcase_add_test(tc, convert_test_34);
    tcase_add_test(tc, convert_test_35);
    tcase_add_test(tc, convert_test_36);
    tcase_add_test(tc, convert_test_37);
    tcase_add_test(tc, convert_test_38);
    tcase_add_test(tc, convert_test_39);
    tcase_add_test(tc, convert_test_40);
    tcase_add_test(tc, convert_test_41);
    tcase_add_test(tc, convert_test_42);
    tcase_add_test(tc, convert_test_43);
    tcase_add_test(tc, convert_test_44);
    tcase_add_test(tc, convert_test_45);
    tcase_add_test(tc, convert_test_46);
    tcase_add_test(tc, convert_test_47);
    tcase_add_test(tc, convert_test_48);
    tcase_add_test(tc, convert_test_49);
    tcase_add_test(tc, convert_test_50);
    tcase_add_test(tc, convert_test_51);
    tcase_add_test(tc, convert_test_52);
    tcase_add_test(tc, convert_test_53);
    tcase_add_test(tc, convert_test_54);
    tcase_add_test(tc, convert_test_55);

    suite_add_tcase(s, tc);
    return s;
}