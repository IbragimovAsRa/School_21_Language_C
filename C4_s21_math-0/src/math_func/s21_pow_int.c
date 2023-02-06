#include "../s21_math.h"


long double s21_pow_int(long double base, int exp) {
    long double tmp = base;
    long double result = base;

    for (int i = 1; i < s21_abs(exp); i++) {
        result = result * tmp;
    }

    if (exp == 0) {
        result = 1.0;
    }
    if (exp < 0) {
        result = 1.0 / result;
    }
    if (exp == 1) {
        result = tmp;
    }
    if (exp == -1) {
        result = 1.0 / tmp;
    }
    return result;
}
