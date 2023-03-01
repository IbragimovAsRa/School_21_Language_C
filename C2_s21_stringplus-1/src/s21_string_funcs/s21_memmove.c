#include "headers/s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {

    char *str_in = (char*) dest;
    char *str_out = (char*) src;

    for (s21_size_t i = 0; i < n; i ++) {
        *(str_in + i) = *(str_out);
    }
    return str_in;
}
