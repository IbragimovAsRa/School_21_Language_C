#include "s21_math.h"
#include <math.h>
#include <stdbool.h>
#include "stdlib.h"

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

long double s21_pow(double base, double exp) {
    long double res;
    int integer = (int) s21_floor(exp);
    long double diff = exp - s21_floor(exp);
    struct result tmp;
    double d1;

    tmp = s21_pow_bad_input(base, exp);
    if (tmp.flag) {
        res = tmp.value;
    } else {
        if (diff <= 0.0000000000000001 && diff >= -0.0000000000000001) {
            res = pow_int(base, integer);
        } else {
            d1 = (double) (exp * s21_log(base));
            res = s21_exp(d1);
        }
        if (base < 10e-14 && base > -10e-14) {
            res = 0.0;
        }
    }
    return res;
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
    if (x == INFINITY) {
        answer = INFINITY;
    } else if (x == -INFINITY) {
        answer = NAN;
    } else if (x != x) {
        answer = NAN;
    }

    return answer;
}

long double s21_ceil(double x) {
     int y = ( int) x;
    long double result = y;
    if (x > 0.0) {
        result += 1.0;
    }
    if (x == INFINITY) {
        result = INFINITY;
    } else if (x == -INFINITY) {
        result = -INFINITY;
    } else if (x != x) {
        result = NAN;
    }
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
    int local_count_row_elem = 80;
    long double exp_x = 1.0;
    long double res = 1.0;

    int flag = 0;
    if (x < 0.0) {
        flag = 1;
        x = x * (-1.0);
    }
    for (int n = 1; n <= local_count_row_elem; n++) {
        res *= x / n;
        exp_x += res;
    }
    if (flag) {
        exp_x = 1.0 / exp_x;
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
    double log_x = 0.0;
    double cur = 0.0;
    int local_count_row_elem = 220;

    bool flag_negative = false;
    bool flag_zero = false;
    bool flag_negative_inf = false;
    bool flag_positive_inf = false;

    if (x <= -10e-11) { // checking for a negative number
        flag_negative = true;
    }
    if ((x < 10e-11) && (x > -10e-11)) { // checking for a zero number
        flag_zero = true;
    }
    if (x == INFINITY) {
        flag_positive_inf = true;
    }
    if (x == -INFINITY) {
        flag_negative_inf = true;
    }

    if (!(flag_zero || flag_negative || flag_positive_inf || flag_negative_inf)) {
        for (int n = 0; n <= local_count_row_elem; n++) {
            cur = log_x;
            log_x = (double) (cur + 2 * (x - s21_exp(cur)) / (x + s21_exp(cur)));
        }
    }
    if (flag_zero || flag_positive_inf) {
        log_x = INFINITY;
    } else if (flag_negative || flag_negative_inf) {
        log_x = NAN;
    }
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
unsigned long long int factorial(int x) {
    unsigned long long int result = 1;
    unsigned long long int tmp = x;
    for (int i = 0; i < x; i++) {
        result = result * tmp;
        tmp--;
    }
    return result;
}

long double pow_int(long double base, int exp) {
    long double tmp = base;
    long double result = base;

    for (int i = 1; i < s21_abs(exp); i++) {
        result = result * tmp;
    }

    if (exp == 0) {
        result = 1.0;
    }
    if (exp < 0) {
        result = 1.0/result;
    }
    if (exp == 1) {
        result = tmp;
    }
    if (exp == -1) {
        result = 1.0 / tmp;
    }
    return result;
}

struct result s21_pow_bad_input(double base, double exp) {
    struct result output;
    output.flag = false;
    output.value = 0.0;

    if (base == INFINITY || base == -INFINITY) {
        output.flag = true;
        output.value = INFINITY;

        if (base == INFINITY) {
            if (exp == INFINITY) {
                output.value = INFINITY;
            }
            if (exp == -INFINITY) {
                output.value = 0.0;
            }
            if (exp != exp) {
                output.value = NAN;
            }
        }
        if (base == -INFINITY) {

            if (exp == INFINITY) {
                output.value = INFINITY;
            }
            if (exp == -INFINITY) {
                output.value = 0.0;
            }
            if (exp != exp) {
                output.value = NAN;
            }
        }
    }
    if (base != base) {
        output.flag = true;
        output.value = NAN;
    }
    return output;
}
