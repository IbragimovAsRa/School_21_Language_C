#include "../s21_string.h"

char *s21_strcat(char *dest, const char *src) {
    char *str_in = dest;
    char *str_out = (char *) src;

    s21_size_t str_in_length = s21_strlen(dest);
    s21_size_t str_out_length = s21_strlen(src);

    for (s21_size_t i = 0; i < str_out_length; i++) {
        *(str_in + str_in_length + i) = *(str_out + i);
    }
    *(str_in + str_in_length + str_out_length + 1) = '\0';
    return str_in;
}
