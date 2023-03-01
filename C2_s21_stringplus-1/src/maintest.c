#include <stdio.h>
#include "s21_string_funcs/headers/s21_string.h"

int test_func(CurrentSymbol *currentSymbol);
int main() {
    CurrentSymbol currentSymbol;
    currentSymbol.str = "hello world";
   // char str1[1000];
//    char str2[1000];
//
//    s21_sscanf("my number", "%s %s", str1, str2);
    test_func(&currentSymbol);
       printf("%s\n", currentSymbol.str);

    return 0;
}


int test_func(CurrentSymbol *currentSymbol) {
    printf("%c", *(currentSymbol->str + 1));
    return 0;
}