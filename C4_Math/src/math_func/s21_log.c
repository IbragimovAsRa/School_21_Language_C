#include "../s21_math.h"

long double s21_log(double x) {
  double log_x = 0.0;
  double cur = 0.0;
  int local_count_row_elem = 220;

  bool flag_negative = false;
  bool flag_zero = false;
  bool flag_negative_inf = false;
  bool flag_positive_inf = false;

  if (x <= -10e-11) {  // checking for a negative number
    flag_negative = true;
  }
  if ((x < 10e-11) && (x > -10e-11)) {  // checking for a zero number
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
      log_x = (double)(cur + 2 * (x - s21_exp(cur)) / (x + s21_exp(cur)));
    }
  }
  if (flag_zero || flag_positive_inf) {
    log_x = S21_INFINITY;
  } else if (flag_negative || flag_negative_inf) {
    log_x = S21_NAN;
  }
  return log_x;
}
