#include "../s21_math.h"

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
