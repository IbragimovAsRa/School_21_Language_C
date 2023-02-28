
#include "../s21_string.h"
#include <stdbool.h>
#include <stdio.h>


int get_length_pattern(const char *str);

void filling_with_zeros(char *array, int array_size);

bool check_separator(const char *ch);

void carriage_leveler(const char **str);

char check_specifier(const char *sym_form_current);

// функции возвращают 0 в случае успешного считывания и записи в противном случае 1 (спецификатор не считан/не записан)

int specifier_c_handler(const char **sym_form_current, const char **sym_str_current, bool separator_form, char *tmp_c);

int
specifier_d_and_i_handler(const char **sym_form_current, const char **sym_str_current, int *tmp_d,
                          char specifier);

int specifier_float_handler(const char **sym_form_current, const char **sym_str_current, float *tmp_fl);


int specifier_o_u_x_handler(const char **sym_form_current, const char **sym_str_current, unsigned int *tmp_uni,
                              char specifier);

int
specifier_s_handler(const char **sym_form_current, const char **sym_str_current, char *tmp_str);


int separator_controller(const char **sym_form_current, const char **sym_str_current, bool *separator_form,
                         bool *separator_str);

void error_handler(int return_code, bool *flag_stop, int *counter);

// int dispatcher_specifier(va_list *factor, );

int s21_sscanf(const char *str, const char *format, ...) {
    bool separator_form = false;
    bool separator_str = false;
    const char *sym_form_current = format;
    const char *sym_str_current = str;
    va_list factor;
    va_start(factor, format);
    int counter = 0;
    bool flag_stop = false;
    int return_code = 0;

    while (*sym_form_current != '\0' && *sym_str_current != '\0' && !flag_stop) { // brute force of format characters
        separator_controller(&sym_form_current, &sym_str_current, &separator_form, &separator_str);
        switch (check_specifier(sym_form_current)) {
            case 'c':
                return_code = specifier_c_handler(&sym_form_current, &sym_str_current, separator_form,
                                                  va_arg(factor, char*));
                break;
            case 'd':
                return_code = specifier_d_and_i_handler(&sym_form_current, &sym_str_current, va_arg(factor, int*), 'd');
                break;
            case 'i':
                return_code = specifier_d_and_i_handler(&sym_form_current, &sym_str_current, va_arg(factor, int*), 'i');
                break;
            case 'e':
                return_code = specifier_float_handler(&sym_form_current, &sym_str_current, va_arg(factor, float *));
                break;
            case 'o':
                return_code = specifier_o_u_x_handler(&sym_form_current, &sym_str_current,
                                                        va_arg(factor, unsigned int *), 'o');
                break;
            case 's':
                return_code = specifier_s_handler(&sym_form_current, &sym_str_current,
                                                  va_arg(factor, char *));
                break;
            case 'u':
                return_code = specifier_o_u_x_handler(&sym_form_current, &sym_str_current,
                                                        va_arg(factor, unsigned int *), 'u');
                break;
            case 'x':
                return_code = specifier_o_u_x_handler(&sym_form_current, &sym_str_current,
                                                      va_arg(factor, unsigned int *), 'x');
                break;
        }
        sym_form_current++;
        sym_str_current++;
        error_handler(return_code, &flag_stop, &counter);
    }
    va_end(factor);
    return counter;
}


void error_handler(int return_code, bool *flag_stop, int *counter) {
    if (!(*flag_stop)) {
        if (return_code == 1) {
            *flag_stop = true;
        } else if (return_code == 0) {
            *counter = *counter + 1;
        }
    }
}


int
specifier_s_handler(const char **sym_form_current, const char **sym_str_current, char *tmp_str) {
    int i = 0;
    *sym_form_current = *sym_form_current + 1;
    while (**sym_str_current != '\0' && **sym_str_current != ' ') {
        *(tmp_str + i) = **(sym_str_current);
        *sym_str_current = *sym_str_current + 1;
        i++;
    }
    if (i > 0) {
        *(tmp_str + (i + 1)) = '\0';
    }
    return 0;
}


int separator_controller(const char **sym_form_current, const char **sym_str_current, bool *separator_form,
                         bool *separator_str) {
    *separator_form = check_separator(*sym_form_current);
    *separator_str = check_separator(*sym_str_current);
    if (check_specifier(*sym_form_current) == 'c') {
        if (*separator_form && *separator_str) { // выровнять каретки
            carriage_leveler(sym_str_current);
            carriage_leveler(sym_form_current);
        }
    } else {
        carriage_leveler(sym_str_current);
        carriage_leveler(sym_form_current);
    }

    return 0;
}

int specifier_o_u_x_handler(const char **sym_form_current, const char **sym_str_current, unsigned int *tmp_uni,
                              char specifier) {
    char *end;
    int base = 0;

    if (specifier == 'o') {
        base = 8;
    } else if (specifier == 'u') {
        base = 10;
    } else if (specifier == 'x') {
        base = 16;
    }
    carriage_leveler(sym_str_current);
    *sym_form_current = (*sym_form_current + 1);

    if (**sym_str_current != '\0') {
        *tmp_uni = (unsigned int) strtoul(*sym_str_current, &end, base);
        *sym_str_current = end;
    }
    return 0;
}

int specifier_float_handler(const char **sym_form_current, const char **sym_str_current, float *tmp_fl) {
    char *end;
    carriage_leveler(sym_str_current);
    *sym_form_current = (*sym_form_current + 1);

    if (**sym_str_current != '\0') {
        *tmp_fl = (float) strtof(*sym_str_current, &end);
        *sym_str_current = end;
    }
    return 0;
}

int specifier_d_and_i_handler(const char **sym_form_current, const char **sym_str_current, int *tmp_d,
                              char specifier) {
    char *end;
    int base;
    if (specifier == 'd') {
        base = 10;
    } else {
        base = 0;
    }
    carriage_leveler(sym_str_current);
    *sym_form_current = (*sym_form_current + 1);

    if (**sym_str_current != '\0') {
        *tmp_d = (int) strtol(*sym_str_current, &end, base);
        *sym_str_current = end;
    }
    return 0;
}


int
specifier_c_handler(const char **sym_form_current, const char **sym_str_current, bool separator_form, char *tmp_c) {
    *sym_form_current = (*sym_form_current + 1);
    if (separator_form) { // переместить курсор строки до первого символа не пробел
        carriage_leveler(sym_str_current);
    }
    if (**sym_str_current != '\0') {
        *tmp_c = **sym_str_current;
    }
    return 0;
}

char check_specifier(const char *sym_form_current) { // handler specifier
    char specifier = '!';
    char ch = *(sym_form_current + 1);
    if (*sym_form_current == '%') {
        if (ch == 'c') {
            specifier = 'c';
        } else if (ch == 'd') {
            specifier = 'd';
        } else if (ch == 'i') {
            specifier = 'i';
        } else if (ch == 'e' || ch == 'E' || ch == 'f' || ch == 'g' || ch == 'G') {
            specifier = 'e';
        } else if (ch == 's') {
            specifier = 's';
        } else if (ch == 'u') {
            specifier = 'u';
        } else if (ch == 'x') {
            specifier = 'x';
        }
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
    while (!(*str == '\0' || *str == ' ')) {
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


/*
 ______Documentation_______
 1) flag_stop
    = true
 then stop program
    = false
 then continue execution program

 2) return_code
    = 1
    error
    = 0
    success
 __________________________
 */
