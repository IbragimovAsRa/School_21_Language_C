#include <stdio.h>
#include "s21_string.h"


int main() {
    char ch_1;
    char ch_2;

    s21_sscanf("ab", "%c%c", &ch_1, &ch_2);
    printf("ch_1 = %c\nch_2 = %c\n", ch_1, ch_2);
    return 0;
}