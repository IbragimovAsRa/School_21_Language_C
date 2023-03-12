#include <stdio.h>
//#include "s21_string_funcs/headers/s21_string.h"
#include "s21_string_funcs/headers/s21_sscanf.h"
#include <string.h>
#include <stdint.h>

int main() {
    char *end;
    char *str = "laruna";
    strtol(str, &end, 10);
    if (str != end) {
        printf("result = %s", end);
    }

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


