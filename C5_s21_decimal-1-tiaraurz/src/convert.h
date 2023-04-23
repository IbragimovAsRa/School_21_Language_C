#ifndef CONVERT_H
#define CONVERT_H

#include "s21_decimal.h"
#include "support.h"
#include "stdbool.h"


typedef struct FloatPattern {
    unsigned int mantis;
    unsigned int exp;
    unsigned int sign;
} FloatPattern;

typedef union FloatConvert {
    float fl;
    unsigned int un;
} FloatConvert;

typedef struct intPattern {
    unsigned int number;
    bool sign; // 1 (true) - negative sign, 0 (false) - positive sign
} intPattern;

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);






intPattern parseInt(int n);
int setBitForDec(s21_decimal* dc, int index, int value);
#endif  // CONVERT_H



















