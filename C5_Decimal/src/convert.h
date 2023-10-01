#ifndef CONVERT_H
#define CONVERT_H

#include "s21_decimal.h"
#include "stdbool.h"
#include "support.h"

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
    bool sign;  // 1 (true) - negative sign, 0 (false) - positive sign
} intPattern;

typedef union BigUnInt {
    unsigned int bits[2];
    uint64_t value;
} BigUnInt;

void printUnIntt(unsigned int un_i);
int pow10(int val);
void printBitFloat(float fl);
int s21_get_bit(s21_decimal value, int index);
int find_index_first_nonzero_bit(s21_decimal dc);
intPattern parseInt(int n);
int setBitForDec(s21_decimal* dc, int index, int value);

#endif  // CONVERT_H
