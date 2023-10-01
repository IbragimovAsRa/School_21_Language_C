#include "../s21_math.h"

long double s21_pow(double base, double exp) {
  long double res;
  int integer = (int)s21_floor(exp);
  long double diff = exp - s21_floor(exp);
  struct result tmp;
  double d1;

  tmp = s21_pow_bad_input(base, exp);
  if (tmp.flag) {
    res = tmp.value;
  } else {
    if (diff <= 0.0000000000000001 && diff >= -0.0000000000000001) {
      res = s21_pow_int(base, integer);
    } else {
      d1 = (double)(exp * s21_log(base));
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
