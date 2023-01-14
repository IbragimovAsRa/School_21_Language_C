#include <stdio.h>
#include <math.h>
#include "s21_math.h"

int main() {
    long double r = s21_log(0.5);
    long double o = log(0.5);

    printf("orig = %Lf\n", o);
    printf("no orig = %Lf\n", r);

    return 0;
}