#include "headers/s21_sscanf.h"
#include "stdio.h"

int s21_sscanf(const char *str, const char *format, ...) {

    Separator separator;
    separator.form = false;
    separator.str = false;

    CurrentSymbol currentSymbol;
    currentSymbol.format = format;
    currentSymbol.str = str;

    Counter counter;
    counter.assignedValues = 0;
    counter.readSymbols = 0;

    va_list factor;
    va_start(factor, format);

    int return_code;
    bool flag_stop = false;

    while (*(currentSymbol.format) != '\0' && *(currentSymbol.str) != '\0' &&
           !flag_stop) { // brute force of format characters
        separator_controller(&currentSymbol, &separator, &counter);
        return_code = dispatcher_specifier(&factor, separator, &currentSymbol, &counter);
        currentSymbol.format++;
        currentSymbol.str++;
        counter.readSymbols++;
        error_handler(return_code, &flag_stop, &counter);
    }
    va_end(factor);
    return counter.assignedValues;
}


int dispatcher_specifier(va_list *factor, Separator separator, CurrentSymbol *currentSymbol, Counter *counter) {
    int return_code = 0;
    Specifier  specifier;
    specifier = check_specifier(*currentSymbol);

    switch (specifier.symbol) {
        case 'c':
            return_code = specifier_c_handler(currentSymbol, separator, va_arg(*factor, char*), counter);
            break;
        case 'd':
            return_code = specifier_d_and_i_handler(currentSymbol, va_arg(*factor, int*), 'd', counter);
            break;
        case 'i':
            return_code = specifier_d_and_i_handler(currentSymbol, va_arg(*factor, int*), 'i', counter);
            break;
        case 'e':
            return_code = specifier_float_handler(currentSymbol, va_arg(*factor, float *), counter);
            break;
        case 'o':
            return_code = specifier_o_u_x_handler(currentSymbol, va_arg(*factor, unsigned int *), 'o', counter);
            break;
        case 's':
            return_code = specifier_s_handler(currentSymbol, va_arg(*factor, char *), counter);
            break;
        case 'u':
            return_code = specifier_o_u_x_handler(currentSymbol, va_arg(*factor, unsigned int *), 'u', counter);
            break;
        case 'x':
            return_code = specifier_o_u_x_handler(currentSymbol, va_arg(*factor, unsigned int *), 'x', counter);
            break;
        case 'p':
            return_code = specifier_p_handler(currentSymbol, va_arg(*factor, void **), counter);
            break;
        case '%':
            return_code = specifier_percent_handler(currentSymbol);
            break;
    }
    return return_code;
}
int specifier_percent_handler(CurrentSymbol *currentSymbol) {
    currentSymbol->format++;
    return 0;
}

int specifier_p_handler(CurrentSymbol *currentSymbol, void **tmp_p, Counter *counter) {
    char *end;
    unsigned int step = 0;
    unsigned long int tmp_uni = 0;
    int base = 16;
    Convert convert;
    carriage_leveler(&(currentSymbol->str), counter);
    currentSymbol->format = (currentSymbol->format + 1);

    if (*(currentSymbol->str) != '\0') {
        tmp_uni = (unsigned long int) strtoul(currentSymbol->str, &end, base);
        while ((currentSymbol->str + step) != end) {
            step++;
        }
        counter->readSymbols += step;
        currentSymbol->str = end;
    }
    convert.hex = tmp_uni;
    *tmp_p = convert.ptr;
    return 0;
}

void error_handler(int return_code, bool *flag_stop, Counter *counter) {
    if (!(*flag_stop)) {
        if (return_code == 1) {
            *flag_stop = true;
        } else if (return_code == 0) {
            counter->assignedValues = counter->assignedValues + 1;
        }
    }
}


int
specifier_s_handler(CurrentSymbol *currentSymbol, char *tmp_str, Counter *counter) {
    int i = 0;
    currentSymbol->format = currentSymbol->format + 1;
    while (*(currentSymbol->format) != '\0' && *(currentSymbol->str) != ' ') {
        *(tmp_str + i) = *(currentSymbol->str);
        currentSymbol->str = currentSymbol->str + 1;
        counter->readSymbols++;
        i++;
    }
    if (i > 0) {
        *(tmp_str + (i + 1)) = '\0';
    }
    return 0;
}


int separator_controller(CurrentSymbol *currentSymbol, Separator *separator, Counter *counter) {
    separator->form = check_separator(currentSymbol->format);
    separator->str = check_separator(currentSymbol->str);
    if (check_specifier(*currentSymbol) == 'c') {
        if (separator->form && separator->str) { // выровнять каретки
            carriage_leveler(&(currentSymbol->str), counter);
            carriage_leveler(&(currentSymbol->format), counter);
        }
    } else {
        carriage_leveler(&(currentSymbol->str), counter);
        carriage_leveler(&(currentSymbol->format), counter);
    }

    return 0;
}

int specifier_o_u_x_handler(CurrentSymbol *currentSymbol, unsigned int *tmp_uni, char specifier, Counter *counter) {
    char *end;
    int base = 0;

    if (specifier == 'o') {
        base = 8;
    } else if (specifier == 'u') {
        base = 10;
    } else if (specifier == 'x') {
        base = 16;
    }
    carriage_leveler(&(currentSymbol->str), counter);
    currentSymbol->format = (currentSymbol->format + 1);

    if (*(currentSymbol->str) != '\0') {
        *tmp_uni = (unsigned int) strtoul(currentSymbol->str, &end, base);
        currentSymbol->str = end;
    }
    return 0;
}

int specifier_float_handler(CurrentSymbol *currentSymbol, float *tmp_fl, Counter *counter) {
    char *end;
    carriage_leveler(&(currentSymbol->str), counter);
    currentSymbol->format = (currentSymbol->format + 1);

    if (*(currentSymbol->str) != '\0') {
        *tmp_fl = (float) strtof(currentSymbol->str, &end);
        currentSymbol->str = end;
    }
    return 0;
}

int specifier_d_and_i_handler(CurrentSymbol *currentSymbol, int *tmp_d, char specifier, Counter *counter) {
    char *end;
    int base;
    if (specifier == 'd') {
        base = 10;
    } else {
        base = 0;
    }
    carriage_leveler(&(currentSymbol->str), counter);
    currentSymbol->format = (currentSymbol->format + 1);

    if (*(currentSymbol->str) != '\0') {
        *tmp_d = (int) strtol(currentSymbol->str, &end, base);
        currentSymbol->str = end;
    }
    return 0;
}


int specifier_c_handler(CurrentSymbol *currentSymbol, Separator separator, char *tmp_c, Counter *counter) {
    currentSymbol->format = (currentSymbol->format + 1);
    if (separator.form) { // переместить курсор строки до первого символа не пробел
        carriage_leveler(&(currentSymbol->str), counter);
    }
    if (*(currentSymbol->str) != '\0') {
        *tmp_c = *(currentSymbol->str);
    }
    return 0;
}

Specifier check_specifier(CurrentSymbol currentSymbol) { // handler specifier
    Specifier specifier;
    specifier.symbol = '!';
    specifier.skip = false;

    char ch = *(currentSymbol.format + 1);
    if (*(currentSymbol.format) == '%') {
        if (ch == 'c') {
            specifier.symbol = 'c';
        } else if (ch == 'd') {
            specifier.symbol = 'd';
        } else if (ch == 'i') {
            specifier.symbol = 'i';
        } else if (ch == 'e' || ch == 'E' || ch == 'f' || ch == 'g' || ch == 'G') {
            specifier.symbol = 'e';
        } else if (ch == 's') {
            specifier.symbol = 's';
        } else if (ch == 'u') {
            specifier.symbol = 'u';
        } else if (ch == 'x') {
            specifier.symbol = 'x';
        } else if (ch == 'p') {
            specifier.symbol = 'p';
        } else if (ch == '%') {
            specifier.symbol = '%';
        }
    }

    return specifier;
}

void carriage_leveler(const char **str, Counter *counter) {
    while (**str == ' ') {
        *str = *str + 1;
        counter->readSymbols++;
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
