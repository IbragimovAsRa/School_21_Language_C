#include "s21_decimal.h"
#include "support.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
    int res = 0;
    bigDecimal tmp = {};
    bigDecimal rem = {};

    if (!result) {
        res = 1;
    } else {
        s21_reset(result);
        mntCpyStd2Big(&value, &tmp);
        while (tmp.pat.exp != 0) {
            mntBigDivByTen(tmp, &tmp, &rem);
            tmp.pat.exp--;
        }
        mntCpyBig2Std(&tmp, result);
    }

    return res;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
    int res = 0;
    if (result == NULL || (!value.bits[0] && !value.bits[1] && !value.bits[2] &&
                           !value.bits[3])) {
        res = 1;
    } else {
        s21_reset(result);
        mntCpy(&value, result);

        if (value.pat.sgn)
            result->pat.sgn = 0;
        else
            result->pat.sgn = 1;
    }

    return res;
}

int s21_floor(s21_decimal value, s21_decimal *result) {
    int ret = 0;
    if (!result) {
        ret = 1;
    } else {
        if (!s21_truncate(value, s21_reset(result)) && value.pat.sgn &&
            !s21_is_equal(*result, value))
            s21_sub(*result, ((s21_decimal){{1, 0, 0, 0}}), result);
    }
    return ret;
}

int s21_round(s21_decimal value, s21_decimal *result) {
    int ret = 0;
    if (!result) {
        ret = 1;
    } else if (!s21_truncate(value, s21_reset(result)) &&
               !s21_is_equal(value, *result)) {
        if (value.pat.sgn)
            s21_sub(value, ((s21_decimal){{5, 0, 0, 65536}}), &value);
        else
            s21_add(value, ((s21_decimal){{5, 0, 0, 65536}}), &value);
        s21_truncate(value, result);
    }
    return ret;
}
