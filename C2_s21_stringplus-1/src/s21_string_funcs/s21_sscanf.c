
#include "../s21_string.h"
#include <string.h>

// символ с - пример - sscanf("ab")
int get_length_pattern(const char *str);
void filling_with_zeros(char *array, int array_size);
bool check_separator(const char *ch);
void carriage_leveler(const char **str);
char check_specifier(const char *sym_form_current);
void specifier_c_handler(const char **sym_form_current, const char **sym_str_current, bool separator_form, char *tmp_c);
void specifier_d_handler();


int s21_sscanf(const char *str, const char *format, ...) {
    va_list factor;
    bool separator_form = false;
    bool separator_str = false;

    va_start(factor, format);
    const char *sym_form_current = format;
    const char *sym_str_current = str;
    char *tmp_c;
    int *tmp_d;
    char tmp_str[100];
    int length_pattern;
    filling_with_zeros(tmp_str, 100);

    //int read_char = 0;

    while (*sym_form_current != '\0' && *sym_str_current != '\0') { // brute force of format characters

        separator_form = check_separator(sym_form_current);
        separator_str = check_separator(sym_str_current);

        if (separator_form && separator_str) { // выровнять каретки
            carriage_leveler(&sym_str_current);
            carriage_leveler(&sym_form_current);
        }

        switch (check_specifier(sym_form_current)) {
            case 'c':
                tmp_c = va_arg(factor, char*);
                specifier_c_handler(&sym_form_current, &sym_str_current, separator_form, tmp_c);
                break;
            case 'd':
                carriage_leveler(&sym_str_current);
                sym_form_current = (sym_form_current + 1);
                tmp_d = va_arg(factor, int*);
                if (separator_form) { // переместить курсор строки до первого символа не пробел
                    while (*sym_str_current == ' ' ) {
                        sym_str_current += 1;
                    }
                }
                if (*sym_str_current != '\0') {
                    length_pattern = get_length_pattern(sym_str_current);
                    strncpy(tmp_str, sym_str_current, length_pattern);
                    *tmp_d = atoi(tmp_str); // обработать на ошибки
                    sym_str_current = sym_str_current + length_pattern;
                    filling_with_zeros(tmp_str, 100);
                }
                break;
        }



        sym_form_current++;
        sym_str_current++;

    }
    va_end(factor);
    return 0;
}

void specifier_c_handler(const char **sym_form_current, const char **sym_str_current, bool separator_form, char *tmp_c) {
    *sym_form_current = (*sym_form_current + 1);
    if (separator_form) { // переместить курсор строки до первого символа не пробел
        carriage_leveler(sym_str_current);
    }
    if (**sym_str_current != '\0') {
        *tmp_c = **sym_str_current;
    }
}

char check_specifier(const char *sym_form_current) {
    char specifier = '!';
    if (*sym_form_current == '%' && *(sym_form_current + 1) == 'c') {
        specifier = 'c';
    }
    if (*sym_form_current == '%' && *(sym_form_current + 1) == 'd') {
        specifier = 'd';
    }
    return specifier;
}



void carriage_leveler(const char **str) {
    while (**str == ' ') {
        *str = *str + 1;
    }
}



bool check_separator(const char *ch) {
    bool result = false;
    if (*ch == ' ') {
        result = true;
    }
    return result;
}

int get_length_pattern(const char *str) {
    int count = 0;
    while (!(*str ==  '\0'  ||  *str == ' ')) {
        str++;
        count++;
    }
    return count;
}
void filling_with_zeros(char *array, int array_size) {
    for (int i = 0; i < array_size; i++) {
        array[i] = '\0';
    }
}

// ФЛАГ %C (возможные исходы)
// 1) sscanf("ab", "%c%c", &ch_1, &ch_2) - классический случай
// 2) sscanf("a b", "%c%c", &ch_1, &ch_2) - нюансы с пробелами
// 3) sscanf("a b", "     %c %c", &ch_1, &ch_2) - нюансы с пробелами


// ФЛАГ %D (возможные исходы)
// 1) sscanf("mu number 1222223", "my number %d", &in_1) - классический случай
// 2) sscanf("1222223", "%d", &ch_1, &ch_2) - классический случай


// Документация (sscanf)
// все строится на разделителях