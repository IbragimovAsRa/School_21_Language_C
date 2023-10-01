#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#define _POSIX_C_SOURCE 200809L

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define count_row_elem 13  // determines the accuracy
#define PI 3.14159265358979323846
#define S21_INFINITY (1.0 / 0.0)
#define S21_NAN (0.0 / 0.0)

int s21_abs(int x);

long double s21_acos(double x);

long double s21_asin(double x);

long double s21_atan(double x);

long double s21_ceil(double x);

long double s21_cos(double x);

long double s21_exp(double x);

long double s21_fabs(double x);

long double s21_floor(double x);

long double s21_fmod(double x, double y);

long double s21_log(double x);

long double s21_pow(double base, double exp);

long double s21_sin(double x);

long double s21_sqrt(double x);

long double s21_tan(double x);

// __________________________supporting_function_______________________________________________
struct result {
  long double value;

  bool flag;
};
struct result s21_pow_bad_input(double base, double exp);

long double s21_pow_int(long double base, int exp);  // temporary
// ________________________________________________________________________________________________

#endif  // SRC_S21_MATH_H_
