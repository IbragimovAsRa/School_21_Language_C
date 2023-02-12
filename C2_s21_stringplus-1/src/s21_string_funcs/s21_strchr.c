#include "../s21_string.h"



char *s21_strchr(const char *str, int c) {
    bool flag = true;
    char *tmp = (char*) str;
    int i = 0;
    char *result = s21_NULL;
    while (flag) {
        if (*(tmp + i) == '\0') {
            flag = false;
        } else if (*(tmp + i) == (char) c) {
            result = tmp + i;
        }
    }
    return result;
}
