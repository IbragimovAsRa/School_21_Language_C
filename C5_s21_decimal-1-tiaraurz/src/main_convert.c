#include "convert.h"
#include "support.h"
int main () {
//    s21_decimal b;
      //s21_decimal result
      // long  double d =
      //    printBit(a);
      //    printBit(a);
    //    s21_from_float_to_decimal(1.23332, &b);
//
//    s21_add(a, b, &result);
//    printBit(result);
//    inverseBit(&(result.bits[3]), 31);
//    printBit(result);\n", round(a));
   // ff /= 10000000000000000;

    //ff *= 10000000000000000;

    // -----------------------ТЗ--------------------------------------------------------------------
    /*
     *
     * 1) выявить все возможные исходы
     * 2) отработать и отладить для каждого (разобраться в какой функции ошибка)
     * 3) исправить дополнительный порядок

        ИСХОДЫ:
------------------------------------------------------------------------
        1) обычные значения
        - float =  758.321       ( float -> decimal ) done; ( decimal -> float ) done;
        - float =  -758.321      ( float -> decimal ) done; ( decimal -> float ) done;
        - float =   758          ( float -> decimal ) done; ( decimal -> float ) done;
        - float =   -758         ( float -> decimal ) done; ( decimal -> float ) done;
        - float =   1.28392      ( float -> decimal ) error; ( decimal -> float ) error;
        - float =   -1.28392     ( float -> decimal ) error; ( decimal -> float ) error;
        - float =   0.00758
        - float =   -0.00758
     */
//    s21_decimal dc;
//    float fl1 = -1.28392;
//    float fl2;
//    s21_from_float_to_decimal(fl1, &dc);
//    s21_from_decimal_to_float(dc, &fl2);
//    printf("         |        |\n");
    // printBit(dc);
//    printf("my = %f\n", fl2);
//    printf("orig = %f\n", fl1);
// ----------------------------------------------------------------------

// for (int i = 31; i >= 0; i--)
// {
//     printf("%d", (*p2 & (1 << i)) != 0);
//     }
//     printf("\n");

// int f2 = -2147483648;
// unsigned int *p2 = (unsigned int *)&f2;
// float a = 11234.1734;
float a = 0.0000000000000000000000002449420232 ;
s21_decimal dec1 = {
    {0b00000000000000000000100110010001, 0b00000000000000000000000000000000,
     0b00000000000000000000000000000000, 0b00000000000111000000000000000000}};
s21_decimal dec2 =ёё {};
s21_from_float_to_decimal(a, &dec2);

printBit(dec1);
printBit(dec2);

return 0;
}

// добавить проверку на ноль в конце
