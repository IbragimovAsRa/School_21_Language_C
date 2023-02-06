#include "../s21_math.h"

long double s21_floor(double x) {
    int y = (int)x;
    long double result = y;
    if (x != x) {
        result = S21_NAN;
    } else if (x == S21_INFINITY) {
        result = S21_INFINITY;
    } else if (x == -S21_INFINITY) {
        result = -S21_INFINITY;
    } else if (result < 0.0) {
        if ((x - y) != 0.0) {
            result = result - 1.0;
        }
    }
    return result;
}
