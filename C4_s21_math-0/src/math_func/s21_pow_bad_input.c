#include "../s21_math.h"

struct result s21_pow_bad_input(double base, double exp) {
    struct result output;
    output.flag = false;
    output.value = 0.0;

    if (base == S21_INFINITY || base == -S21_INFINITY) {
        output.flag = true;
        output.value = S21_INFINITY;

        if (base == S21_INFINITY) {
            if (exp == S21_INFINITY) {
                output.value = S21_INFINITY;
            }
            if (exp == -S21_INFINITY) {
                output.value = 0.0;
            }
            if (exp != exp) {
                output.value = S21_NAN;
            }
        }
        if (base == -S21_INFINITY) {
            if (exp == S21_INFINITY) {
                output.value = S21_INFINITY;
            }
            if (exp == -S21_INFINITY) {
                output.value = 0.0;
            }
            if (exp != exp) {
                output.value = S21_NAN;
            }
        }
    }
    if (base != base) {
        output.flag = true;
        output.value = S21_NAN;
    }
    return output;
}
