#include <stdio.h>
#include "s21_string.h"


int main() {

    char str1[1000];
    char str2[1000];

    s21_sscanf("my number", "%s %s", str1, str2);
    printf("%s %s\n", str1, str2);
    return 0;
}