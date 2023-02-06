#include "../s21_math.h"

long double s21_fmod(double x, double y) {
    long double result = x / y;
    bool flag_nan = false;

    if ((result != result) || result == S21_INFINITY || result == -S21_INFINITY) {
        result = S21_NAN;
        flag_nan = true;
    } else {
        int tmp = (int)result;
        result = x - y * tmp;
    }

    if (s21_fabs(x) < s21_fabs(y)) {
        result = x;
    } else if (x == y && x != S21_INFINITY) {
        result = 0.0;
        if (flag_nan) {
            result = S21_NAN;
        }
    }
    return result;
}
