#ifndef SRC_TEST_CASES_S21_MATH_H_
#define SRC_TEST_CASES_S21_MATH_H_

#include <stdio.h>
#include <check.h>
#include <math.h>

#include "s21_math.h"

#define accuracy 1e-6
#define max_inf  1.0 / 0.0
#define  min_inf  -1.0 / 0.0
#define  max_nan  0.0 / 0.0
#define  min_nan  -0.0 / 0.0

Suite *get_suite_s21_asin();

Suite *get_suite_s21_acos();

Suite *get_suite_s21_ceil();

Suite *get_suite_s21_exp();

Suite *get_suite_s21_log();

Suite *get_suite_s21_pow();

Suite *get_suite_s21_sqrt();

#endif // SRC_TEST_CASES_S21_MATH_H_
