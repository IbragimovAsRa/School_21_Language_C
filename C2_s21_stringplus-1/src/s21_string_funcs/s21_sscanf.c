#include "headers/s21_sscanf.h"
#include "stdio.h"
int s21_sscanf(const char *str, const char *format, ...) {

    Separator separator;
    separator.form = false;
    separator.str = false;

    CurrentSymbol currentSymbol;
    currentSymbol.format = format;
    currentSymbol.str = str;

    va_list factor;
    va_start(factor, format);
    int counter = 0;
    bool flag_stop = false;
    int return_code = 0;

    while (*(currentSymbol.format) != '\0' && *(currentSymbol.str) != '\0' &&
           !flag_stop) { // brute force of format characters
        separator_controller(&currentSymbol, &separator);
        return_code = dispatcher_specifier(&factor, separator, &currentSymbol);
        currentSymbol.format++;
        currentSymbol.str++;
        error_handler(return_code, &flag_stop, &counter);
    }
    va_end(factor);
    return counter;
}


int dispatcher_specifier(va_list *factor, Separator separator, CurrentSymbol *currentSymbol) {
    int return_code = 0;
    switch (check_specifier(*currentSymbol)) {
        case 'c':
            return_code = specifier_c_handler(currentSymbol, separator, va_arg(*factor, char*));
            break;
        case 'd':
            return_code = specifier_d_and_i_handler(currentSymbol, va_arg(*factor, int*), 'd');
            break;
        case 'i':
            return_code = specifier_d_and_i_handler(currentSymbol, va_arg(*factor, int*), 'i');
            break;
        case 'e':
            return_code = specifier_float_handler(currentSymbol, va_arg(*factor, float *));
            break;
        case 'o':
            return_code = specifier_o_u_x_handler(currentSymbol, va_arg(*factor, unsigned int *), 'o');
            break;
        case 's':
            return_code = specifier_s_handler(currentSymbol, va_arg(*factor, char *));
            break;
        case 'u':
            return_code = specifier_o_u_x_handler(currentSymbol, va_arg(*factor, unsigned int *), 'u');
            break;
        case 'x':
            return_code = specifier_o_u_x_handler(currentSymbol, va_arg(*factor, unsigned int *), 'x');
            break;
        case 'p':
            return_code = specifier_p_handler(currentSymbol, va_arg(*factor, void **));
            break;
    }
    return return_code;
}
int specifier_p_handler(CurrentSymbol *currentSymbol, void **tmp_p) {
    // 1) считать шестнадцетиричное число
    char *end;
    unsigned long int tmp_uni = 0;
    int base = 16;
    Tmp tmp;

    carriage_leveler(&(currentSymbol->str));
    currentSymbol->format = (currentSymbol->format + 1);

    if (*(currentSymbol->str) != '\0') {
        tmp_uni = (unsigned long int) strtoul(currentSymbol->str, &end, base);
        currentSymbol->str = end;
    }
    tmp.b = tmp_uni;
    *tmp_p = tmp.a;
    return 0;
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
specifier_s_handler(CurrentSymbol *currentSymbol, char *tmp_str) {
    int i = 0;
    currentSymbol->format = currentSymbol->format + 1;
    while (*(currentSymbol->format) != '\0' && *(currentSymbol->str) != ' ') {
        *(tmp_str + i) = *(currentSymbol->str);
        currentSymbol->str = currentSymbol->str + 1;
        i++;
    }
    if (i > 0) {
        *(tmp_str + (i + 1)) = '\0';
    }
    return 0;
}


int separator_controller(CurrentSymbol *currentSymbol, Separator *separator) {
    separator->form = check_separator(currentSymbol->format);
    separator->str = check_separator(currentSymbol->str);
    if (check_specifier(*currentSymbol) == 'c') {
        if (separator->form && separator->str) { // выровнять каретки
            carriage_leveler(&(currentSymbol->str));
            carriage_leveler(&(currentSymbol->format));
        }
    } else {
        carriage_leveler(&(currentSymbol->str));
        carriage_leveler(&(currentSymbol->format));
    }

    return 0;
}

int specifier_o_u_x_handler(CurrentSymbol *currentSymbol, unsigned int *tmp_uni, char specifier) {
    char *end;
    int base = 0;

    if (specifier == 'o') {
        base = 8;
    } else if (specifier == 'u') {
        base = 10;
    } else if (specifier == 'x') {
        base = 16;
    }
    carriage_leveler(&(currentSymbol->str));
    currentSymbol->format = (currentSymbol->format + 1);

    if (*(currentSymbol->str) != '\0') {
        *tmp_uni = (unsigned int) strtoul(currentSymbol->str, &end, base);
        currentSymbol->str = end;
    }
    return 0;
}

int specifier_float_handler(CurrentSymbol *currentSymbol, float *tmp_fl) {
    char *end;
    carriage_leveler(&(currentSymbol->str));
    currentSymbol->format = (currentSymbol->format + 1);

    if (*(currentSymbol->str) != '\0') {
        *tmp_fl = (float) strtof(currentSymbol->str, &end);
        currentSymbol->str = end;
    }
    return 0;
}

int specifier_d_and_i_handler(CurrentSymbol *currentSymbol, int *tmp_d,
                              char specifier) {
    char *end;
    int base;
    if (specifier == 'd') {
        base = 10;
    } else {
        base = 0;
    }
    carriage_leveler(&(currentSymbol->str));
    currentSymbol->format = (currentSymbol->format + 1);

    if (*(currentSymbol->str) != '\0') {
        *tmp_d = (int) strtol(currentSymbol->str, &end, base);
        currentSymbol->str = end;
    }
    return 0;
}


int specifier_c_handler(CurrentSymbol *currentSymbol, Separator separator, char *tmp_c) {
    currentSymbol->format = (currentSymbol->format + 1);
    if (separator.form) { // переместить курсор строки до первого символа не пробел
        carriage_leveler(&(currentSymbol->str));
    }
    if (*(currentSymbol->str) != '\0') {
        *tmp_c = *(currentSymbol->str);
    }
    return 0;
}

char check_specifier(CurrentSymbol currentSymbol) { // handler specifier
    char specifier = '!';
    char ch = *(currentSymbol.format + 1);
    if (*(currentSymbol.format) == '%') {
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
        } else if (ch == 'p') {
            specifier = 'p';
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
