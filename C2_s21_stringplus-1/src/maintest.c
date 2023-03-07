#include <stdio.h>
//#include "s21_string_funcs/headers/s21_string.h"
#include "s21_string_funcs/headers/s21_sscanf.h"
#include <string.h>


int main() {
    float n;
    char *str = "number 12.32 65.45643";
    char *pattern= "number %*f %f";
    s21_sscanf(str, pattern, &n);
    printf("result = %f\n", n);
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


