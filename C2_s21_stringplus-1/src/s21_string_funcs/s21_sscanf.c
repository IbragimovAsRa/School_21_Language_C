#include "headers/s21_sscanf.h"
#include "stdio.h"
#include "string.h"

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
    Specifier specifier;
    specifier = check_specifier(*currentSymbol);
    char ch = specifier.symbol;
    if (ch == 'c') {
        return_code = specifier_c_handler(currentSymbol, specifier, factor, separator, counter);
    }
    if (ch == 'e' || ch == 'E' || ch == 'f' || ch == 'g' || ch == 'G' || ch == 'd' || ch == 'i' || ch == 'o' ||
        ch == 'u' || ch == 'x' || ch == 'p') {
        return_code = specifier_grl_handler(currentSymbol, specifier, factor, counter);
    }
    if (ch == 's') {
        return_code = specifier_s_handler(currentSymbol, specifier, factor, counter);
    }
    if (ch == '%') {
        return_code = specifier_percent_handler(currentSymbol);
    }
    return return_code;
}

int specifier_percent_handler(CurrentSymbol *currentSymbol) {
    currentSymbol->format++;
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
specifier_s_handler(CurrentSymbol *currentSymbol, Specifier specifier, va_list *factor, Counter *counter) {
    unsigned int i = 0;
    char *tmp_str;
    if (!specifier.skip) {
        tmp_str = va_arg(*factor, char *);
    }

    currentSymbol->format = currentSymbol->format + specifier.length;
    while (*(currentSymbol->format) != '\0' && *(currentSymbol->str) != ' ' && specifier.width > i) {
        if (!specifier.skip) {
            *(tmp_str + i) = *(currentSymbol->str);
        }
        currentSymbol->str = currentSymbol->str + 1;
        counter->readSymbols++;
        i++;
    }
    if (i > 0 && (!specifier.skip)) {
        *(tmp_str + i) = '\0';
    }
    return 0;
}


int separator_controller(CurrentSymbol *currentSymbol, Separator *separator, Counter *counter) {
    separator->form = check_separator(currentSymbol->format);
    separator->str = check_separator(currentSymbol->str);
    if (check_specifier(*currentSymbol).symbol == 'c') {
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


int convert_skip_helper(const char *str_conv, Specifier specifier, Argument argument, char **end) {
    char ch = specifier.symbol;
    int base = 0;
    TmpArgument tmpArgument;
    Convert convert;

    if (ch == 'o') {
        base = 8;
    } else if (ch == 'u' || ch == 'd') {
        base = 10;
    } else if (ch == 'x' || ch == 'p') {
        base = 16;
    }

    if (ch == 'e' || ch == 'E' || ch == 'f' || ch == 'g' || ch == 'G') {
        tmpArgument.fl = (float) strtof(str_conv, end);
        if (!specifier.skip) {
            *(argument.fl) = tmpArgument.fl;
        }
    } else if (ch == 'd' || ch == 'i') {
        tmpArgument.in = (int) strtol(str_conv, end, base);
        if (!specifier.skip) {
            *(argument.in) = tmpArgument.in;
        }
    } else if (ch == 'o' || ch == 'u' || ch == 'x') {
        tmpArgument.uni = (unsigned int) strtoul(str_conv, end, base);
        if (!specifier.skip) {
            *(argument.uni) = tmpArgument.uni;
        }
    } else if (ch == 'p') {
        tmpArgument.unli = (unsigned long int) strtoul(str_conv , end, base);
        if (!specifier.skip) {
            convert.hex = tmpArgument.unli;
            *(argument.pch) = convert.ptr;
        }
    }
    return 0;
}

//        while ((currentSymbol->str + step) != end) { счетчик считанных символов
//            step++;
//        }
//        counter->readSymbols += step;

int specifier_grl_handler(CurrentSymbol *currentSymbol, Specifier specifier, va_list *factor, Counter *counter) {
    char *end;
    char tmp_str[100];
    Argument argument;
    if (!specifier.skip) {
        if (specifier.symbol == 'p') {
            argument.pch = va_arg(*factor, void **);
        } else {
            argument.general = va_arg(*factor, void *);
        }
    } else {
        if (specifier.symbol == 'p') {
            argument.pch = NULL;
        } else {
            argument.general = NULL;
        }
    }
    carriage_leveler(&(currentSymbol->str), counter);
    currentSymbol->format = (currentSymbol->format + specifier.length);
    if (*(currentSymbol->str) != '\0') {
        if (!specifier.skip) {
            if (specifier.width == 10e8) {
                convert_skip_helper(currentSymbol->str, specifier, argument, &end);
                currentSymbol->str = end;
            } else {
                strncpy(tmp_str, currentSymbol->str, specifier.width);
                convert_skip_helper(tmp_str, specifier, argument, &end);
                currentSymbol->str += specifier.width;
            }
        } else {
            if (specifier.width == 10e8) {
                convert_skip_helper(currentSymbol->str, specifier, argument, &end);
                currentSymbol->str = end;
            } else {
                currentSymbol->str += (specifier.width - 1);
            }
        }
    }
    return 0;
}


int specifier_c_handler(CurrentSymbol *currentSymbol, Specifier specifier, va_list *factor, Separator separator,
                        Counter *counter) {
    char *tmp_c;
    currentSymbol->format = (currentSymbol->format + specifier.length);
    if (separator.form) { // переместить курсор строки до первого символа не пробел
        carriage_leveler(&(currentSymbol->str), counter);
    }
    if (*(currentSymbol->str) != '\0') {
        if (!specifier.skip) {
            tmp_c = va_arg(*factor, char *);
            *tmp_c = *(currentSymbol->str);
        }
    }
    return 0;
}

Specifier check_specifier(CurrentSymbol currentSymbol) { // handler specifier
    Specifier specifier;
    specifier.symbol = '!';
    specifier.skip = false;
    specifier.length = 1;

    if (*(currentSymbol.format) == '%') {

        skip_check(currentSymbol, &specifier);
        width_check(currentSymbol, &specifier);

        char ch = *(currentSymbol.format + specifier.length);

        if (ch == 'c') {
            specifier.symbol = 'c';
        } else if (ch == 'd') {
            specifier.symbol = 'd';
        } else if (ch == 'i') {
            specifier.symbol = 'i';
        } else if (ch == 'e') {
            specifier.symbol = 'e';
        } else if (ch == 'E') {
            specifier.symbol = 'E';
        } else if (ch == 'f') {
            specifier.symbol = 'f';
        } else if (ch == 'g') {
            specifier.symbol = 'g';
        } else if (ch == 'G') {
            specifier.symbol = 'G';
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

int parse_width(CurrentSymbol currentSymbol, Specifier *specifier) {
    char tmp_str[100];
    char *end;
    int flag = 0;
    if (specifier->skip) {
        flag = 1;
    }
    strncpy(tmp_str, currentSymbol.format + flag + 1, specifier->length - 1);
    specifier->width = strtoul(tmp_str, &end, 10);
    return 0;
}

// %s
int width_check(CurrentSymbol currentSymbol, Specifier *specifier) {
    specifier->width = 10e8;
    int num_length = 0;
    char current_fch = *(currentSymbol.format + specifier->length + num_length);

    while ((int) current_fch >= 48 && (int) current_fch <= 57) {
        num_length++;
        current_fch = *(currentSymbol.format + specifier->length + num_length);
    }
    specifier->length += num_length;
    if (num_length > 0) {
        parse_width(currentSymbol, specifier);
    }

    return 0;
}

int skip_check(CurrentSymbol currentSymbol, Specifier *specifier) {
    if (*(currentSymbol.format + 1) == '*') {
        specifier->skip = true;
        specifier->length++;
    }
    return 0;
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
