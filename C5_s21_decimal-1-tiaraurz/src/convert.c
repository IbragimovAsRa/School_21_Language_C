#include "convert.h"

// 1-случай: 0.0000324998234 -> 324998.234 (необходимо привести к такому виду)
// 2- случай: 1233432321.234341 ->
//void
//print_bit(unsigned int num) {
//    for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
//        printf("%d", (num >> i) & 1);
//    }
//    printf("\n");
//}
int setBitForDec(s21_decimal* dc, int index, int value) {

    if (value == 1) {
        setBit(&(dc->bits[getRow(index)]), getCol(index));
    } else if (value == 0) {
        resetBit(&(dc->bits[getRow(index)]), getCol(index));
    }


    return 0;
}
intPattern parseInt(int n) {
    intPattern  pattern;
    if (n < 0)  {
        pattern.sign = true;
        n = -1 * n;
    } else {
        pattern.sign = false;
    }
    pattern.number = (unsigned int) n;
    return pattern;
}

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
    unsigned int result = 0;

        intPattern intPat= parseInt(src);
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
    FloatConvert floatConvert;
    int sign = isSetBit(src.bits,127);
    int exp_10 = src.pat.exp;
    float tmp_fl;


    unsigned int mantis = 0;
    int exp_2 = 0;

    if (exp_10 > 0) {
        tmp_fl = src.bits[0];
        for (int i = 1; i < (exp_10+1); i++) {
            tmp_fl = tmp_fl/10.0;
        }
        if (sign) {
            tmp_fl = -tmp_fl;
        }
        *dst = tmp_fl;

    } else {
        for (int i = 95; i >= 0; i--) {
            if (isSetBit(&(src.bits[getRow(i)]), getCol(i))) {
                exp_2 = i - 1;
                break;
            }
        }
        // заполнение мантиссы
       // unsigned int bit = 0;
        int current_bit_index = 0;
        for (int i = 22; i >= 0; i--) {
            current_bit_index = (exp_2 - (22 - i));
            if (isSetBit(&(src.bits[getRow(current_bit_index)]), getCol(current_bit_index))) {
                mantis |= (1 << i);
            }
        }
        mantis = mantis >> (22 - exp_2);
        mantis = mantis << (22 - exp_2);
        FloatPattern floatPattern;
        floatPattern.mantis = 0;
        floatPattern.mantis = mantis;
        floatPattern.exp = 0;
        floatPattern.exp |= (exp_2 + 127 + 1) << 23;

        floatPattern.sign = 0;
        if (sign == 1) {
            floatPattern.sign |= (1 << 31);
        }

        floatConvert.un = (floatPattern.sign | floatPattern.exp | floatPattern.mantis);
        *dst = floatConvert.fl;

    }
    return 0;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
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
    long double exp_helper = 1000000; // отвечает за 7 значащих цифр
    if (tmp_src < exp_helper) { // 1-ый исход
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
    
    dst->pat.mnt1 = (unsigned int) tmp_src; // обработка случая больших чисел
    // округлятор --------------------
    
    unsigned int a =  (unsigned int) tmp_src;
    long double a_f = (long double)a;
    if ((tmp_src - a_f) >= 0.5) {
        dst->pat.mnt1 += 1;
    }
   // ------------------------------------
    while (exp < 0) {
        multByTen(dst);
        exp++;
    }
    dst->pat.exp = exp;
    if (flag_sign == 1) {
        inverseBit(&(dst->bits[3]), 31);
    }

    /* доделать обработку исключений
     *
    printf("input src  = %f\n", src);
    printf("base  = %i\n", (int)tmp_src);
    printf("exp = %i\n", exp);
     */
    return 0;
}
