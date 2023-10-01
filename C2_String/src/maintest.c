#include <stdio.h>
//#include "s21_string_funcs/headers/s21_string.h"
#include "s21_string_funcs/headers/s21_sscanf.h"
#include <string.h>
#include <stdint.h>

int main() {
    char format[] = "Hello %n ";
    char str[] = "Hello";
    int n1 = 0, n2 = 0;

     s21_sscanf(str, format, &n1);
     sscanf(str, format, &n2);


    printf("res1 = %i\n", n1);
    printf("res2 = %i\n", n2);



//    printf("d1 = %i\n", d1);
//    printf("d2 = %i\n", d2);
//
//    printf("q1 = %i\n", q1);
//    printf("q2 = %i\n", q2);
//
//    printf("z1 = %i\n", z1);
//    printf("z2 = %i\n", z2);
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


