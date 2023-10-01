#include "../s21_math.h"

long double s21_cos(double x) {
  long double cos_x = 1.0;
  int tmp;
  int flag_sign;
  if (x < 0.0) {
    x = -1 * x;
  }
  if (!(x > -2 * PI && x < 2 * PI)) {
    tmp = (int)(x / (2 * PI));
    x = x - tmp * (2 * PI);
  }
  long double cur = 1;
  for (int n = 1; n <= 40; n++) {
    if (n % 2 == 0) {
      flag_sign = 1;
    } else {
      flag_sign = -1;
    }
    cur = cur * s21_pow_int(x, 2) / (2 * n) / (2 * n - 1);
    cos_x += flag_sign * cur;
  }
  return cos_x;
}
