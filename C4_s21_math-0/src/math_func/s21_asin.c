#include "../s21_math.h"


long double s21_asin(double x) {
    long double asin_x = 0.0;
    if (x == S21_INFINITY || x == -S21_INFINITY || x != x) {
        asin_x = S21_NAN;
    } else {
        asin_x = s21_atan((double)(x / s21_sqrt((double)(1.0 - s21_pow(x, 2)))));
    }
    return asin_x;
}

