
#ifndef S21_MATH_H_
#define S21_MATH_H_

#include <stdio.h>

#define count_row_elem 10 // determines the accuracy
#define PI 3.14159265359

int s21_abs(int x);
long double s21_cos(double x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_exp(double x);
long double s21_sin(double x);
long double s21_log(double x);
// __________________________supporting_function_______________________________________________
int factorial(int x);
long double pow_int(double base, int exp); // temporary
// ________________________________________________________________________________________________

#endif //S21_MATH_H_
