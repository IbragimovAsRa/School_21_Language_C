#include "../../s21_string.h"


int s21_find_count_pattern(const char *str) {
    bool flag = true;
    int count_pattern = 0;
    int i = 0;
    while(flag) {
        if (*(str + i) == '%') {
            count_pattern++;
        }
        if (*(str + i) == '\0') {
            flag = false;
        } else {
            i++;
        }
    }
    return count_pattern;
}
