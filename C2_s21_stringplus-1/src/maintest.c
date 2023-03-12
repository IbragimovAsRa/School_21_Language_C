#include <stdio.h>
//#include "s21_string_funcs/headers/s21_string.h"
#include "s21_string_funcs/headers/s21_sscanf.h"
#include <string.h>
#include <stdint.h>

int main() {
    char format[] = "%i%i%i";
    // char str[] = "0123 +0198 -087";
    char str[] = "+0123 +0198";
    unsigned int d1, d2;
    unsigned int q1, q2;
    unsigned int z1, z2;

    int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
    int16_t res2 = sscanf(str, format, &d2, &q2, &z2);


    printf("res1 = %i\n", res1);
    printf("res2 = %i\n", res2);

    printf("d1 = %i\n", d1);
    printf("d2 = %i\n", d2);

    printf("q1 = %i\n", q1);
    printf("q2 = %i\n", q2);

    printf("z1 = %i\n", z1);
    printf("z2 = %i\n", z2);
    return 0;
}


//Tmp tmp;
//int a = 15;
//int v = 11;
//int *p_a ;
//char str[100];
//sprintf(str, "%p", &v);
//s21_sscanf(str , "%p", &p_a);
//printf("%i\n", *p_a);


