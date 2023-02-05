#include "s21_math.h"
#include <stdbool.h>

int s21_abs(int x) {
    if (x < 0) {
        x = x * (-1);
    }
    return x;
}

long double s21_fabs(double x) {
    if (x < 0.0) {
        x = x * (-1.0);
    }
    return x;
}

long double s21_floor(double x) {
    int y = (int) x;
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

long double s21_cos(double x) {
    long double cos_x = 1.0;
    int tmp;
    int flag_sign;
    if (x < 0.0) {
        x = -1 * x;
    }
    if (!(x > -2*PI && x < 2*PI) ) {
        tmp = (int)(x / (2*PI));
        x = x - tmp * (2*PI);
    }
    long double cur = 1;
    for (int n = 1; n <= 40; n++) {
        if (n % 2 == 0) {
            flag_sign = 1;
        } else {
            flag_sign = -1;
        }
        cur = cur*pow_int(x, 2)/(2*n)/(2*n-1);
        cos_x += flag_sign*cur;
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
    if (exp == 0.0) {
        res = 1;
    }
    return res;
}

long double s21_atan(double x) {
    long double atan_x = 0.0;
    int flag_sign;
    if (x == S21_INFINITY) {
        atan_x = PI / 2;
    } else if (x == -S21_INFINITY) {
        atan_x = -PI / 2;
    } else if (x == 1.0) {    // -1 and 1 - limit values, bad convergence
        atan_x = 0.78539816339744;
    } else if (x == -1.0) {
        atan_x = -0.78539816339744;
    } else if (x > -1.0 && x < 1.0) {
        for (int n = 0; n < 1000; n++) {
            if (n % 2 == 0) {
                flag_sign = 1;
            } else {
                flag_sign = -1;
            }
            atan_x += flag_sign* s21_pow(x, 1 + (2 * n)) / (1 + (2 * n));
        }
    } else {
        for (int n = 0; n < 1000; n++) {
            if (n % 2 == 0) {
                flag_sign = 1;
            } else {
                flag_sign = -1;
            }
            atan_x += flag_sign * s21_pow(x, -1 - (2 * n)) / (1 + (2 * n));
        }
        atan_x = PI * s21_sqrt(x * x) / (2 * x) - atan_x;
    }
    return atan_x;
}

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

long double s21_ceil(double x) {
    int y = (int) x;
    long double result = y;
    if (x > 0.0) {
        result += 1.0;
    }
    if (x == S21_INFINITY) {
        result = S21_INFINITY;
    } else if (x == -S21_INFINITY) {
        result = -S21_INFINITY;
    } else if (x != x) {
        result = S21_NAN;
    }
    return result;
}

long double s21_asin(double x) {
    long double asin_x = 0.0;
    if (x == S21_INFINITY || x == -S21_INFINITY || x != x) {
        asin_x = S21_NAN;
    } else {
        asin_x = s21_atan((double )(x /s21_sqrt((double )(1.0 - s21_pow(x, 2)))));
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
    return s21_cos(PI/2 - x);
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
    if (x == S21_INFINITY) {
        flag_positive_inf = true;
    }
    if (x == -S21_INFINITY) {
        flag_negative_inf = true;
    }

    if (!(flag_zero || flag_negative || flag_positive_inf || flag_negative_inf)) {
        for (int n = 0; n <= local_count_row_elem; n++) {
            cur = log_x;
            log_x = (double) (cur + 2 * (x - s21_exp(cur)) / (x + s21_exp(cur)));
        }
    }
    if (flag_zero || flag_positive_inf) {
        log_x = S21_INFINITY;
    } else if (flag_negative || flag_negative_inf) {
        log_x = S21_NAN;
    }
    return log_x;
}

long double s21_fmod(double x, double y) {
    long double result = x / y;
    bool flag_nan = false;

    if ((result != result)||result == S21_INFINITY || result == -S21_INFINITY) {
        result = S21_NAN;
        flag_nan = true;
    } else {
        int tmp = (int) result;
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

long double s21_tan(double x) {
    return s21_sin(x)/s21_cos(x);
}

// вспомогательные функции
unsigned long long int factorial(int x) {
    if (x < 0) {
        return 0;
    }
    if (x == 0) {
        return 1;
    } else {
        return x * factorial(x - 1);
    }
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
