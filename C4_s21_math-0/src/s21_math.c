#include "s21_math.h"

// переделать через битовые операции
int s21_abs(int x) {
    if (x < 0) {
        x = x * (-1);
    }
    return x;
}

// путем разложения в ряд Тейлора (добавить long)
long double s21_cos(double x) {
    long double cos_x = 0.0;
    for (int n = 0; n <= count_row_elem; n++) {
        cos_x += pow_int(-1, n) * (pow_int(x, 2 * n) / factorial(2 * n));
    }
    return cos_x;
}


long double s21_atan(double x) {
    long double atan_x = 0.0;
    long double d1;
    long double d2;
    long double d3;
    long double cur;

    for (int n = 1; n < count_row_elem; n++) {
        d1 = pow_int(-1, n - 1);
        d2 = 2*n - 1;
        d3 = pow_int(x, 2*n - 1);
        cur = (d1/d2) * d3;
        atan_x += cur;
    }

    return atan_x;
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
        d1 = factorial(2*n);
        d2 = pow_int(4, n);
        d3 = pow_int(factorial(n), 2) * (2*n + 1);
        d4 = (2*n + 1);
        d5 = pow_int(x, d4);
        cur = (d1/(d2*d3)) * d5;
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
    return (PI/2.0 - s21_asin(x));
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
    x = x - 1;
    long double log_x = 0.0;
    long double d1;
    long double d2;
    long double cur;

    for (int n = 1; n <= count_row_elem; n++) {
        d1 = pow_int(-1, n + 1);
        d2 = pow_int(x, n );
        cur = (d1*d2)/(n );
        log_x += cur;


        printf("iter - %i\n", n);
        printf("log_x = %Lf\n", log_x);
        printf("d1 = %Lf\n", d1);
        printf("d2 = %Lf\n", d2);
        printf("cur = %Lf\n", cur);
        printf("_______________________________\n");


    }
    return log_x;
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


