#include "headers/s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
    char *result = s21_NULL;
    for (const char *first = str1; *first; first++) {
        for (const char *second = str2; *second; second++) {
            if (*first == *second) {
                result = (char*)first;
                break;
            }
        }
        if (result) {
            break;
        }
    }
    return result;
}
