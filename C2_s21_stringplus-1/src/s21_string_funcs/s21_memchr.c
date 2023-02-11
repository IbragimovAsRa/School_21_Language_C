#include "../s21_string.h"


void *s21_memchr(const void *str, int c, s21_size_t n) {
    char *tmp = (char*)str;
    void *result = s21_NULL;

    for (s21_size_t i = 0; i < n; i ++) {
        if ((int)*(tmp + i) ==  c) {
            result = (tmp + i);
            break;
        }
    }
    return result;
}