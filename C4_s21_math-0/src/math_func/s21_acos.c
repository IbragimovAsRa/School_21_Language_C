#include "../s21_math.h"

long double s21_acos(double x) { return (PI / 2.0 - s21_asin(x)); }
