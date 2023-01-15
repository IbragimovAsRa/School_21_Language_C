#include "s21_math.h"

// переделать через битовые операции
int s21_abs(int x) {
    if (x < 0) {
        x = x * (-1);
    }
    return x;
}

long double s21_fabs(double x) {
    if (x < 0.00000000000001) {
        x = x * (-1);
    }
    return x;
    return 1.1;
}

long double s21_floor(double x) {
    int y = (int) x;
    long double result = y;
    return result;
}

long double s21_cos(double x) {
    long double cos_x = 0.0;
    for (int n = 0; n <= count_row_elem; n++) {
        cos_x += pow_int(-1, n) * (pow_int(x, 2 * n) / factorial(2 * n));
    }
    return cos_x;
}

long double s21_pow(double x, double exp) {
    long double result;
    double d1;
    d1 = (double) (exp * s21_log(x));
    result = s21_exp(d1);
    return result;
}

long double s21_atan(double x) {
    long double atan_x = 0.0;
    long double d1;
    long double d2;
    long double d3;
    long double cur;
    for (int n = 1; n < count_row_elem; n++) {
        d1 = pow_int(-1, n - 1);
        d2 = 2 * n - 1;
        d3 = pow_int(x, 2 * n - 1);
        cur = (d1 / d2) * d3;
        atan_x += cur;
    }
    return atan_x;
}

long double s21_sqrt(double x) {
    long double answer = 0.0;
    answer = s21_pow(x, 0.5);
    return answer;
}

long double s21_ceil(double x) {
    int y = (int) x;
    long double result = y + 1.0;
    return result;
}

long double s21_asin(double x) {
    long double asin_x = 0.0;
    long double d1;
    long double d2;
    long double d3;
    int d4;
    long double d5;
    long double cur;
    for (int n = 0; n < count_row_elem; n++) {
        d1 = factorial(2 * n);
        d2 = pow_int(4, n);
        d3 = pow_int(factorial(n), 2) * (2 * n + 1);
        d4 = (2 * n + 1);
        d5 = pow_int(x, d4);
        cur = (d1 / (d2 * d3)) * d5;
        asin_x += cur;
    }
    return asin_x;
}

long double s21_exp(double x) {
    long double exp_x = 0;
    for (int n = 0; n <= count_row_elem; n++) {
        exp_x += (pow_int(x, n) / factorial(n));
    }
    return exp_x;
}

long double s21_acos(double x) {
    return (PI / 2.0 - s21_asin(x));
}

long double s21_sin(double x) {
    long double sin_x = 0;
    long double d1;
    long double d2;
    long double d3;
    long double cur;

    for (int n = 1; n <= count_row_elem; n++) {
        d1 = pow_int(-1, n - 1);
        d2 = pow_int(x, 2 * n - 1);
        d3 = factorial(2 * n - 1);
        cur = d1 * (d2 / d3);
        sin_x += cur;
    }
    return sin_x;
}

long double s21_log(double x) {
    x = (x - 1) / (x + 1);
    long double log_x = 0.0;
    long double d1;
    long double d2;
    int d0;
    long double cur;

    for (int n = 1; n <= count_row_elem; n++) {
        d0 = 2 * n - 1;
        d1 = pow_int(x, d0);
        d2 = 2 * n - 1;
        cur = d1 / d2;
        log_x += cur;
        printf("iter - %i\n", n);
        printf("log_x = %Lf\n", log_x);
        printf("d1 = %Lf\n", d1);
        printf("d2 = %Lf\n", d2);
        printf("cur = %Lf\n", cur);
        printf("_______________________________\n");
    }
    log_x = log_x * 2;
    return log_x;
}

long double s21_fmod(double x, double y) {
    long double result = x / y;
    int tmp = (int) result;
    result = x - y * tmp;
    return result;

}

long double s21_tan(double x) {
    long double bernuli[] = {1.0,
                             -1.0 / 2.0,
                             1.0 / 6.0,
                             0.0,
                             -1.0 / 30.0,
                             0.0,
                             1.0 / 42.0};
    long double tan_x = 0.0;
    long double d1;
    long double d2;
    long double d3;
    long double d4;
    long double cur;
    for (int n = 1; n < count_row_elem; n++) {
        d1 = pow_int(-4, n);
        d2 = 1 - pow_int(4, n);
        d3 = factorial(2 * n);
        d4 = pow_int(x, 2 * n - 1);
        cur = ((bernuli[2 * n] * d1 * d2) / d3) * d4;
        tan_x += cur;
    }
    return tan_x;
}

// вспомогательные функции
int factorial(int x) {
    int result = 1;
    int tmp = x;
    for (int i = 0; i < x; i++) {
        result = result * tmp;
        tmp--;
    }
    return result;
}

long double pow_int(double base, int exp) {
    long double tmp = base;
    long double result = base;

    for (int i = 1; i < exp; i++) {
        result = result * tmp;
    }
    if (exp == 0) {
        result = 1.0;
    }
    if (exp == 1) {
        result = tmp;
    }
    return result;
}


