#include "../s21_math.h"


long double s21_sqrt(double x) {
    long double answer = 0.0;
    answer = s21_pow(x, 0.5);
    if (x == S21_INFINITY) {
        answer = S21_INFINITY;
    } else if (x == -S21_INFINITY) {
        answer = S21_NAN;
    } else if (x != x) {
        answer = S21_NAN;
    }

    return answer;
}
