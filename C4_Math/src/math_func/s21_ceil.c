#include "../s21_math.h"

long double s21_ceil(double x) {
  int y = (int)x;
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
