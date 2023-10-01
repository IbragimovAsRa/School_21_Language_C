#include "convert.h"

int s21_get_bit(s21_decimal value, int index) {
    int idxRow = getRow(index);
    int idxCol = getCol(index);
    return (value.bits[idxRow] & (1u << idxCol)) >> idxCol;
}
int setBitForDec(s21_decimal *dc, int index, int value) {
    if (value == 1) {
        setBit(&(dc->bits[getRow(index)]), getCol(index));
    } else if (value == 0) {
        resetBit(&(dc->bits[getRow(index)]), getCol(index));
    }

    return 0;
}
intPattern parseInt(int n) {
    intPattern pattern;
    if (n < 0) {
        pattern.sign = true;
        n = -1 * n;
    } else {
        pattern.sign = false;
    }
    pattern.number = (unsigned int)n;
    return pattern;
}

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
    unsigned int result = 0;

    intPattern intPat = parseInt(src);
    dst->bits[0] = intPat.number;
    dst->bits[1] = 0;
    dst->bits[2] = 0;
    dst->bits[3] = 0;
    if (intPat.sign) {
        setBitForDec(dst, 127, 1);
    }
    return result;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
    unsigned int result = 0;

    BigUnInt bigUnInt = {{src.bits[0], src.bits[1]}};
    FloatConvert floatConvert;
    int sign = isSetBit(src.bits, 127);
    int exp_10 = src.pat.exp;
    double tmp_fl = (double)bigUnInt.value;
    unsigned int mantis = 0;
    int exp_2 = 0;

    if (exp_10 > 0) {  // корректно отрабатывает
        for (int i = 1; i < (exp_10 + 1); i++) {
            tmp_fl = tmp_fl / 10.0;
        }
        if (sign) {
            tmp_fl = -tmp_fl;
        }
        *dst = (float)tmp_fl;

    } else {
        for (int i = 95; i >= 0; i--) {
            if (isSetBit(&(src.bits[getRow(i)]), getCol(i))) {
                exp_2 = i - 1;
                break;
            }
        }
        // заполнение мантиссы
        int current_bit_index = 0;
        for (int i = 22; i >= 0; i--) {
            current_bit_index = (exp_2 - (22 - i));
            if (current_bit_index >= 0) {
                if (isSetBit(&(src.bits[getRow(current_bit_index)]),
                             getCol(current_bit_index))) {
                    mantis |= (1 << i);
                }
            }
        }
        FloatPattern floatPattern;
        floatPattern.mantis = 0;
        floatPattern.mantis = mantis;
        floatPattern.exp = 0;
        floatPattern.exp |= (exp_2 + 127 + 1) << 23;
        floatPattern.sign = 0;
        if (sign == 1) {
            floatPattern.sign |= (1 << 31);
        }
        floatConvert.un =
            (floatPattern.sign | floatPattern.exp | floatPattern.mantis);
        *dst = floatConvert.fl;
    }
    return result;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
    unsigned int result = 0;
    if (src == S21_INF || src == -S21_INF) {
        result = 1;
    } else if (fabs(src) > 0 && fabs(src) < 1e-28) {  // числа слишком малы
        dst->bits[0] = 0;
        dst->bits[1] = 0;
        dst->bits[2] = 0;
        dst->bits[3] = 0;
        result = 1;
    } else if (fabs(src) > 79228162514264337593543950335.0) {
        result = 1;
    } else if (isnan(src)) {
        result = 1;
    } else {
        dst->bits[0] = 0;
        dst->bits[1] = 0;
        dst->bits[2] = 0;
        dst->bits[3] = 0;
        long double tmp_src = (long double)src;

        int flag_sign = 0;
        if (src < 0.0) {
            tmp_src *= -1;
            flag_sign = 1;
        }
        int exp = 0;
        long double exp_helper = 1000000;  // отвечает за 7 значащих цифр
        if (tmp_src < exp_helper) {  // 1-ый исход
            while (tmp_src / exp_helper < 1.0) {
                exp++;
                tmp_src *= 10;
            }
        } else if (tmp_src >= exp_helper * 10) {
            while (tmp_src >= exp_helper * 10) {
                exp--;
                tmp_src /= 10;
            }
        }

        dst->pat.mnt1 =
            (unsigned int)tmp_src;  // обработка случая больших чисел
        // округлятор --------------------
        unsigned int a = (unsigned int)tmp_src;
        long double a_f = (long double)a;
        if ((tmp_src - a_f) >= 0.5) {
            dst->pat.mnt1 += 1;
        }
        while (exp < 0) {
            multByTen(dst);
            exp++;
        }
        dst->pat.exp = exp;
        if (flag_sign == 1) {
            inverseBit(&(dst->bits[3]), 31);
        }
    }
    return result;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
    int result = 0;
    uint8_t exp = 0;
    int sign = isSetBit(src.bits, 127);
    BigUnInt bigUnInt = {{src.bits[0], src.bits[1]}};
    exp = src.pat.exp;
    if (exp > 0) {
        for (int i = exp; i > 0; i--) {
            bigUnInt.value = bigUnInt.value / 10;
        }
    }
    // Валидация
    if (find_index_first_nonzero_bit(src) > 63 &&
        exp == 0) {  // слишком большое значение
        result = 1;
    } else if ((sign == 1) && (bigUnInt.value > 2147483648)) {
        result = 1;
    } else if ((sign == 0) && (bigUnInt.value > 2147483647)) {
        result = 1;
    }
    if (result == 0) {
        *dst = (int)bigUnInt.value;
        if (sign) {
            *dst = *dst * (-1);
        }
    }
    return result;
}

int find_index_first_nonzero_bit(s21_decimal dc) {
    int result = 0;
    for (int i = 95; i >= 0; i--) {
        if (isSetBit(dc.bits, i)) {
            result = i;
            break;
        }
    }
    return result;
}

int pow10(int val) {  // заменить
    int result = 1;

    for (int i = 0; i < val; i++) {
        result *= 10;
    }
    return result;
}

void printBitFloat(float fl) {
    float f = fl;
    unsigned int *p = (unsigned int *)&f;

    for (int i = 31; i >= 0; i--) {
        printf("%d", (*p & (1 << i)) != 0);
    }
    printf("\n");
}

void printUnIntt(unsigned int un_i) {
    unsigned int f = un_i;
    unsigned int *p = &f;

    for (int i = 31; i >= 0; i--) {
        printf("%d", (*p & (1 << i)) != 0);
    }
    printf("\n");
}
