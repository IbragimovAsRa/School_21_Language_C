#include <stdio.h>
#include <math.h>
#include "s21_math.h"

int main() {


    long double r = s21_sqrt(4);
    long double o = sqrt(4);

    printf("orig = %Lf\n", o);
    printf("no orig = %Lf\n", r);

    return 0;
}