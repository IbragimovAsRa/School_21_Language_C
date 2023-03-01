#include "headers/s21_string.h"


int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    char *s21_str1 = (char*)str1;
    char *s21_str2 = (char*)str2;

    int result = 0;

    for (s21_size_t i = 0; i < n; i ++) {
        if (*(s21_str1 + i) != *(s21_str2 + i)) {
            result += (int)(*(s21_str1 + i)) - (int)(*(s21_str2 + i));
            break;
        }
    }
    return result;
}