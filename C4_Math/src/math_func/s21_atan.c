#include "../s21_math.h"

long double s21_atan(double x) {
  long double atan_x = 0.0;
  int flag_sign;
  if (x == S21_INFINITY) {
    atan_x = PI / 2;
  } else if (x == -S21_INFINITY) {
    atan_x = -PI / 2;
  } else if (x == 1.0) {  // -1 and 1 - limit values, bad convergence
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
      atan_x += flag_sign * s21_pow(x, 1 + (2 * n)) / (1 + (2 * n));
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
