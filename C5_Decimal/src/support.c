#include "support.h"

int isSetBit(unsigned int* num, int idx) {
    int idxRow = getRow(idx);
    int idxCol = getCol(idx);
    return (num[idxRow] & (1 << idxCol)) != 0;
}

void setBit(unsigned int* num, int idx) {
    int idxRow = getRow(idx);
    int idxCol = getCol(idx);
    num[idxRow] |= (1 << idxCol);
}

void resetBit(unsigned int* num, int idx) {
    int idxRow = getRow(idx);
    int idxCol = getCol(idx);
    num[idxRow] &= ~(1 << idxCol);
}

void inverseBit(unsigned int* num, int idx) {
    int idxRow = getRow(idx);
    int idxCol = getCol(idx);
    num[idxRow] ^= (1 << idxCol);
}

int getRow(int bit) { return (int)floor(bit >> 5); }

int getCol(int bit) { return bit % 32; }

void s21_zero_exp(s21_decimal* val) {
    val->pat.null1 = 0;
    val->pat.null2 = 0;
    // if (val->pat.exp > 28) val->pat.exp = 28;
}

s21_decimal* s21_reset(s21_decimal* value) {
    for (int x = 0; x < 4; x += 1) value->bits[x] = 0;
    return value;
}

// Возвращаемое значение
// 0 - равны
// 1 - val1 больше
// 2 - val2 больше
int mnt_comp(s21_decimal val1, s21_decimal val2) {
    int larger = 0;

    for (int idx = 95; idx >= 0; idx--) {
        if (isSetBit(val1.bits, idx) ^ isSetBit(val2.bits, idx)) {
            larger = isSetBit(val1.bits, idx) ? 1 : 2;
            break;
        }
    }

    return larger;
}

// Возвращаемое значение
// 0 - равны
// 1 - val1 больше
// 2 - val2 больше
int mntBigComp(bigDecimal val1, bigDecimal val2) {
    int larger = 0;

    for (int idx = 191; idx >= 0; idx--) {
        if (isSetBit(val1.bits, idx) ^ isSetBit(val2.bits, idx)) {
            larger = isSetBit(val1.bits, idx) ? 1 : 2;
            break;
        }
    }

    return larger;
}

void bigNormalization(bigDecimal* val1, bigDecimal* val2) {
    if (val1->pat.exp > val2->pat.exp) {
        mntBigNorm(val2, val1);
    } else if (val1->pat.exp < val2->pat.exp) {
        mntBigNorm(val1, val2);
    }
}

void mntBigNorm(bigDecimal* val1, bigDecimal* val2) {
    while (val1->pat.exp != val2->pat.exp) {
        multBigTen(val1);
        val1->pat.exp++;
    }
}

void mntBigShiftLeft(bigDecimal* val, int shift) {
    bigDecimal tmp = {};

    for (int i = 0; i < shift; i++) {
        //копирование в tmp
        mntCpyBig2Big(val, &tmp);

        //смещение мантиссы на 1
        for (int i = 1; i < 192; i++) {
            if (isSetBit(tmp.bits, i - 1)) {
                setBit(val->bits, i);
            } else {
                resetBit(val->bits, i);
            }
        }
        resetBit(val->bits, 0);
    }
}

void mntShiftLeft(s21_decimal* val, int shift) {
    s21_decimal tmp = {};

    for (int i = 0; i < shift; i++) {
        //копирование в tmp
        mntCpy(val, &tmp);

        //смещение мантиссы на 1
        for (int i = 1; i < 96; i++) {
            if (isSetBit(tmp.bits, i - 1)) {
                setBit(val->bits, i);
            } else {
                resetBit(val->bits, i);
            }
        }
        resetBit(val->bits, 0);
    }
}

void mntBigShiftRight(bigDecimal* val, int shift) {
    bigDecimal tmp = {};

    for (int i = 0; i < shift; i++) {
        //копирование в tmp
        mntCpyBig2Big(val, &tmp);

        //смещение мантиссы на 1
        for (int i = 190; i != -1; i--) {
            if (isSetBit(tmp.bits, i + 1)) {
                setBit(val->bits, i);
            } else {
                resetBit(val->bits, i);
            }
        }
        resetBit(val->bits, 191);
    }
}

void mntShiftRight(s21_decimal* val, int shift) {
    s21_decimal tmp = {};

    for (int i = 0; i < shift; i++) {
        //копирование в tmp
        mntCpy(val, &tmp);

        //смещение мантиссы на 1
        for (int i = 94; i != -1; i--) {
            if (isSetBit(tmp.bits, i + 1)) {
                setBit(val->bits, i);
            } else {
                resetBit(val->bits, i);
            }
        }
        resetBit(val->bits, 95);
    }
}

//копируе val1 в val2
void mntCpy(s21_decimal* val1, s21_decimal* val2) {
    for (int i = 0; i < 96; i++) {
        if (isSetBit(val1->bits, i))
            setBit(val2->bits, i);
        else
            resetBit(val2->bits, i);
    }
}

void mntCpyBig2Big(bigDecimal* val1, bigDecimal* val2) {
    for (int i = 0; i < 192; i++) {
        if (isSetBit(val1->bits, i))
            setBit(val2->bits, i);
        else
            resetBit(val2->bits, i);
    }
}

void mntCpyBig2Std(bigDecimal* val1, s21_decimal* val2) {
    for (int i = 0; i < 96; i++) {
        if (isSetBit(val1->bits, i))
            setBit(val2->bits, i);
        else
            resetBit(val2->bits, i);
    }
    val2->pat.exp = val1->pat.exp;
    val2->pat.sgn = val1->pat.sgn;
}

void mntCpyStd2Big(s21_decimal* val1, bigDecimal* val2) {
    for (int i = 0; i < 96; i++) {
        if (isSetBit(val1->bits, i))
            setBit(val2->bits, i);
        else
            resetBit(val2->bits, i);
    }
    val2->pat.exp = val1->pat.exp;
    val2->pat.sgn = val1->pat.sgn;
}

// 0 - OK
// 1 - INF
int fixBigOverflow(bigDecimal* val) {
    int ret = 0;
    bigDecimal rem = {};
    bigDecimal max = {{0xffffffff, 0xffffffff, 0xffffffff, 0, 0, 0, 0}};

    while (val->bits[3] || val->bits[4] || val->bits[5]) {
        if (!(mntBigComp(max, *val))) ret = 1;
        if (val->pat.exp)
            val->pat.exp--;
        else
            ret = 1;
        mntBigDivByTen(*val, val, &rem);
    }

    mntBigRound(val, rem);

    return ret;
}

int mntBigSub(bigDecimal val1, bigDecimal val2, bigDecimal* res) {
    int ret = 0;
    int whoInv = 0;  // число для инверсии: 1 - val1, 2 - val2;
    mntBigZero(res);
    whoInv = mntBigComp(val1, val2) == 1 ? 1 : 2;
    for (int i = 0; i <= 191; i++) {
        inverseBit(whoInv == 1 ? val1.bits : val2.bits, i);
    }
    mntBigAdd(val1, val2, res);
    for (int i = 0; i <= 191; i++) {
        inverseBit(res->bits, i);
    }
    res->pat.sgn = whoInv == 1 ? 0 : 1;
    return ret;
}

void mntBigAdd(bigDecimal val1, bigDecimal val2, bigDecimal* res) {
    int addOne = 0;
    int rank = 192;

    // обнуляем мантиссу результата
    mntBigZero(res);

    int v1 = 0;
    int v2 = 0;

    for (int i = 0; i < rank; i++) {
        v1 = isSetBit(val1.bits, i);
        v2 = isSetBit(val2.bits, i);

        if (v1 == 0 && v2 == 0 && addOne == 0) {
            resetBit(res->bits, i);
            addOne = 0;
        } else if (v1 == 1 && v2 == 1 && addOne == 1) {
            setBit(res->bits, i);
            addOne = 1;
        } else if ((v1 ^ v2 ^ addOne) == 0) {
            resetBit(res->bits, i);
            addOne = 1;
        } else if ((v1 ^ v2 ^ addOne) == 1) {
            setBit(res->bits, i);
            addOne = 0;
        }
    }
}

int mntBigMul(bigDecimal val1, bigDecimal val2, bigDecimal* res) {
    int ret = 0;
    int rank = 192;

    mntBigZero(res);

    for (int i = rank - 1; i != -1; i--) {
        if (isSetBit(val2.bits, i)) {
            mntBigShiftLeft(&val1, i);
            mntBigAdd(*res, val1, res);
            mntBigShiftRight(&val1, i);
        }
    }
    res->pat.sgn = val1.pat.sgn ^ val2.pat.sgn;
    return ret;
}

int mntBigDiv(bigDecimal dividend, bigDecimal divisor, bigDecimal* res,
              bigDecimal* rem) {
    int ret = 0;

    mntBigZero(res);
    mntBigZero(rem);

    for (int i = 191; i >= 0; i--) {
        mntBigShiftLeft(rem, 1);

        rem->pat.mnt1 |= isSetBit(dividend.bits, i);
        if (mntBigComp(*rem, divisor) != 2) {
            mntBigSub(*rem, divisor, rem);
            setBit(res->bits, i);
        }
    }

    res->pat.sgn = dividend.pat.sgn ^ divisor.pat.sgn;

    return ret;
}

void divBigEngine(bigDecimal dividend, bigDecimal divisor, bigDecimal* bigRes,
                  bigDecimal remainder) {
    int sgn = dividend.pat.sgn ^ divisor.pat.sgn ? 1 : 0;
    int scale = dividend.pat.exp - divisor.pat.exp;
    bigDecimal zero = {};
    bigDecimal tmp = {};

    // надо тестить
    while (((mntBigComp(remainder, zero) != 0) && (scale < 28)) ||
           (scale < 0)) {
        multBigTen(&remainder);
        multBigTen(bigRes);
        scale++;
        mntBigDiv(remainder, divisor, &tmp, &remainder);
        mntBigAdd(*bigRes, tmp, bigRes);
    };

    bigRes->pat.exp = (unsigned int)scale;
    bigRes->pat.sgn = sgn ? 1 : 0;
}

int mntBigDivByTen(bigDecimal dividend, bigDecimal* res,
                   bigDecimal* remainder) {
    bigDecimal ten = {{10, 0, 0, 0, 0, 0, 0}};

    int ret = 0;
    mntBigZero(res);
    mntBigZero(remainder);

    for (int i = 191; i >= 0; i--) {
        mntBigShiftLeft(remainder, 1);

        remainder->pat.mnt1 |= isSetBit(dividend.bits, i);
        if (mntBigComp(*remainder, ten) != 2) {
            mntBigSub(*remainder, ten, remainder);
            setBit(res->bits, i);
        }
    }

    return ret;
}

int mntBigDiv2(bigDecimal dividend, bigDecimal divisor, bigDecimal* res,
               bigDecimal* rem) {
    bigDecimal tmp = {};
    int ret = 0;
    int offset = 0;

    mntBigZero(res);

    while (mntBigComp(dividend, divisor) == 1) {
        offset = 0;
        mntCpyBig2Big(&divisor, &tmp);
        while (mntBigComp(tmp, dividend) == 2) {
            offset++;
            mntBigShiftLeft(&tmp, 1);
        }
        offset--;
        mntBigShiftRight(&tmp, 1);
        setBit(res->bits, offset);
        mntBigSub(dividend, tmp, &dividend);
    }
    mntCpyBig2Big(&dividend, rem);

    return ret;
}

void multBigTen(bigDecimal* val) {
    bigDecimal tmp = {};
    mntCpyBig2Big(val, &tmp);
    mntBigShiftLeft(val, 3);
    mntBigShiftLeft(&tmp, 1);
    mntBigAdd(*val, tmp, val);
}

void multByTen(s21_decimal* res) {
    bigDecimal val = {};
    bigDecimal tmp = {};

    mntCpyStd2Big(res, &val);
    mntCpyBig2Big(&val, &tmp);
    mntBigShiftLeft(&val, 3);
    mntBigShiftLeft(&tmp, 1);
    mntBigAdd(val, tmp, &val);

    mntCpyBig2Std(&val, res);
}

void mntZero(s21_decimal* res) {
    for (int i = 0; i < 96; i++) resetBit(res->bits, i);
}

void mntBigZero(bigDecimal* res) {
    for (int i = 0; i < 192; i++) resetBit(res->bits, i);
}

void printBit(s21_decimal val) {
    for (int i = 127; i >= 0; i--) {
        if (i == 95 || i == 126 || i == 127) printf(" ");
        printf("%u", isSetBit(val.bits, i));
    }
    printf("\n");
}

void printBigBit(bigDecimal val) {
    for (int i = 223; i >= 0; i--) {
        if (i == 191 || i == 222 || i == 223) printf(" ");
        printf("%u", isSetBit(val.bits, i));
    }
    printf("\n");
}

// С сохранением конечных нулей
void mntBigTruncate(bigDecimal* val) {
    uint32_t scale = (uint32_t)val->pat.exp;
    bigDecimal rem = {};
    while (scale) {
        mntBigDivByTen(*val, val, &rem);
        scale--;
    }
    val->pat.exp = scale;
}

void mntBigRound(bigDecimal* val, bigDecimal rem) {
    if (rem.pat.mnt1 == (uint32_t)5) {
        if (val->pat.mnt1 % (uint32_t)2 == 1) val->pat.mnt1++;
    } else if (rem.pat.mnt1 > (uint32_t)5) {
        val->pat.mnt1++;
    }
}

// Функции конвертации из строки в decimal (для тестов, для удобства)
void convertStr2Dec(char* str, s21_decimal* val) {
    int scale = 0;
    int i = 0;
    int c = 0;
    bigDecimal tmp = {};
    bigDecimal res = {};
    char* end = str;
    mntZero(val);
    while (*end) end++;
    end--;

    while (end != str - 1) {
        c = *end;
        if (c == '-') {
            res.pat.sgn = 1;
        } else if (c == '.') {
            res.pat.exp = scale;
        } else {
            c -= '0';
            for (int j = 0; c != 0; j++) {
                if (c & 1) setBit(tmp.bits, j);
                c >>= 1;
            }
            for (int j = 0; j < i; j++) {
                multBigTen(&tmp);
            }
            mntBigAdd(tmp, res, &res);
            mntBigZero(&tmp);
            i++;
            scale++;
        }
        end--;
    }
    mntCpyBig2Std(&res, val);
}
