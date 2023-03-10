#include <stdio.h>
//#include "s21_string_funcs/headers/s21_string.h"
#include "s21_string_funcs/headers/s21_sscanf.h"
#include <string.h>


int main() {

    char *test_str = "hello world";
    char *pattern = "hello world%n";
    unsigned int count1;
    unsigned int count2;


    s21_sscanf(test_str, pattern, &count1);
    sscanf(test_str, pattern, &count2);

    printf("result 1 = %i", count1);
    printf("result 2 = %i", count2);

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


