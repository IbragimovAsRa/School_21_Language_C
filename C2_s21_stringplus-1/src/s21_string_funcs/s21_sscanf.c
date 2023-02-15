
#include "../s21_string.h"


// символ с - пример - sscanf("ab")

int s21_sscanf(const char *str, const char *format, ...) {
    va_list factor;
    bool separator = false;
    va_start(factor, format);
    const char *sym_form_current = format;
    const char *sym_str_current = str;
    char *tmp_c;

    while (*sym_form_current != '\0' && *sym_str_current != '\0') { // brute force of format characters
        if (*sym_form_current == ' ') {
            separator = true;
            sym_form_current = (sym_form_current + 1);
        } else {
            separator = false;
        }
        if (*sym_form_current == '%' && *(sym_form_current + 1) == 'c') { // processing the specifier
            sym_form_current = (sym_form_current + 1);
            tmp_c = va_arg(factor, char*);
            if (separator) { // переместить курсор строки до первого символа не пробел
                while (*sym_str_current == ' ' ) {
                    sym_str_current += 1;
                }
            }
            if (*sym_str_current != '\0') {
                *tmp_c = *sym_str_current;
                sym_str_current = sym_str_current + 1;
            }
        }
        sym_form_current = (sym_form_current + 1);
    }
    va_end(factor);
    return 0;
}


// ФЛАГ %C (возможные исходы)
// 1) sscanf("ab", "%c%c", &ch_1, &ch_2) - классический случай
// 2) sscanf("a b", "%c%c", &ch_1, &ch_2) - нюансы с пробелами
// 3) sscanf("a b", "     %c %c", &ch_1, &ch_2) - нюансы с пробелами

// Документация (sscanf)
