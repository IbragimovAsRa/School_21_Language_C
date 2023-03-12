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
    dispatcher_specifier(&factor, separator, &currentSymbol, &counter);
   // error_handler(return_code, &flag_stop, &counter);

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
    if (ch == 'n') {
        return_code = specifier_n_handler( factor, counter);
    }
    if (ch == '%') {
        return_code = specifier_percent_handler(currentSymbol);
    }

    if (return_code != 1 && specifier.skip) {
        return_code = 3;
    }
    return return_code;
}

int specifier_n_handler(va_list *factor, Counter *counter) {
    int *count = va_arg(*factor, int *);
    *count = (counter->readSymbols) - 1 ;
    return 0;
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
    char *tmp_str = NULL ;
    wchar_t *tmp_lstr = NULL;
    if (!specifier.skip && specifier.lengthSymbol == 'l') {
        tmp_lstr = va_arg(*factor, int *);
    } else if (!specifier.skip) {
        tmp_str = va_arg(*factor, char *);
    }
    currentSymbol->format = currentSymbol->format + specifier.length;
    while (*(currentSymbol->format) != '\0' && *(currentSymbol->str) != ' ' && specifier.width > i) {
        if (!specifier.skip && specifier.lengthSymbol == 'l' ) {
            *(tmp_lstr + i) = (int)*(currentSymbol->str);
        } else if (!specifier.skip) {
            *(tmp_str + i) = *(currentSymbol->str);
        }
        currentSymbol->str = currentSymbol->str + 1;
        counter->readSymbols++;
        i++;
    }
    if (i > 0 && (!specifier.skip) && specifier.lengthSymbol != 'l') {
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
    TmpArgument tmpArgument;
    Convert convert;
    int return_code = 0;
    int base = 0;
    if (ch == 'o') {
        base = 8;
    } else if (ch == 'u' || ch == 'd') {
        base = 10;
    } else if (ch == 'x' || ch == 'p') {
        base = 16;
    }

    if (ch == 'e' || ch == 'E' || ch == 'f' || ch == 'g' || ch == 'G') {
        tmpArgument.llfl = (long double) strtof(str_conv, end);
        if (!specifier.skip) {
            if (specifier.lengthSymbol == 'l') {
                *(argument.lfl) = (double) tmpArgument.llfl;
            } else if (specifier.lengthSymbol == 'L') {
                *(argument.llfl) = tmpArgument.llfl;
            } else {
                *(argument.fl) = (float) tmpArgument.llfl;
            }
        }
    } else if (ch == 'd' || ch == 'i') {
        tmpArgument.lin = strtol(str_conv, end, base); // сделать проверку если не скип
        if (!specifier.skip) {
            if (specifier.lengthSymbol == 'h') {
                *(argument.shi) = (short int) tmpArgument.lin;
            } else if (specifier.lengthSymbol == 'l') {
                *(argument.lin) = (long int) tmpArgument.lin;
            } else {
                *(argument.in) = (int) tmpArgument.lin;
            }
        }
    } else if (ch == 'o' || ch == 'u' || ch == 'x' || ch == 'X' || ch == 'p') {
        tmpArgument.unli = (unsigned long int) strtoul(str_conv, end, base);
        if (!specifier.skip) {
            if (ch == 'p') {
                convert.hex = tmpArgument.unli;
                *(argument.pch) = convert.ptr;
            } else {
                if (specifier.lengthSymbol == 'h') {
                    *(argument.unshi) = (unsigned short int) tmpArgument.unli;
                } else if (specifier.lengthSymbol == 'l') {
                    *(argument.unli) = tmpArgument.unli;
                } else {
                    *(argument.uni) = (unsigned int) tmpArgument.unli;
                }
            }
        }
    }
    if (str_conv == *end) {
        return_code = 1;
    }
    return return_code;
}

//        while ((currentSymbol->str + step) != end) { счетчик считанных символов
//            step++;
//        }
//        counter->readSymbols += step;

int specifier_grl_handler(CurrentSymbol *currentSymbol, Specifier specifier, va_list *factor, Counter *counter) {
    char *end;
    char tmp_str[100];
    Argument argument;
    int return_code = 0;
    if (!specifier.skip) {
        if (specifier.symbol == 'p') {
            argument.pch = va_arg(*factor, void **);
        } else {
            argument.general = va_arg(*factor, void *);
        }
    } else {
        return_code = 3;
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
                return_code = convert_skip_helper(currentSymbol->str, specifier, argument, &end);
                currentSymbol->str = end - 1;
            } else {
                strncpy(tmp_str, currentSymbol->str, specifier.width);
                return_code = convert_skip_helper(tmp_str, specifier, argument, &end);
                currentSymbol->str += cur_str_helper(tmp_str, end) - 1;
            }
        } else {
            if (specifier.width == 10e8) {
                return_code = convert_skip_helper(currentSymbol->str, specifier, argument, &end);
                currentSymbol->str = end - 1;
            } else {
                convert_skip_helper(currentSymbol->str, specifier, argument, &end);
                currentSymbol->str += cur_str_helper(currentSymbol->str, end) - 1;
            }
        }
    }
    return return_code;
}
int cur_str_helper(const char *str, char *end) {
    int result = 0;
    while (str != end) {
        str++;
        result++;
    }
    return result;
}

int specifier_c_handler(CurrentSymbol *currentSymbol, Specifier specifier, va_list *factor, Separator separator,
                        Counter *counter) {
    char *tmp_c;
    wchar_t *tmp_lc;
    int return_code = 0;
    if (specifier.skip) {
        return_code = 3;
    }
    currentSymbol->format = (currentSymbol->format + specifier.length);
    if (separator.form) { // переместить курсор строки до первого символа не пробел
        carriage_leveler(&(currentSymbol->str), counter);
    }
    if (*(currentSymbol->str) != '\0') {
        if (!specifier.skip) {
            if (specifier.lengthSymbol == 'l') {
                tmp_lc = va_arg(*factor, int *);
                *tmp_lc = (int) *(currentSymbol->str);
            } else {
                tmp_c = va_arg(*factor, char *);
                *tmp_c = *(currentSymbol->str);
            }
        }
    }
    return return_code;
}

Specifier check_specifier(CurrentSymbol currentSymbol) { // handler specifier
    Specifier specifier;
    specifier.symbol = '!';
    specifier.skip = false;
    specifier.length = 1;

    if (*(currentSymbol.format) == '%') {

        skip_check(currentSymbol, &specifier);
        width_check(currentSymbol, &specifier);
        length_check(currentSymbol, &specifier);

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
        } else if (ch == 'X') {
            specifier.symbol = 'X';
        } else if (ch == 'n') {
            specifier.symbol = 'n';
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

int length_check(CurrentSymbol currentSymbol, Specifier *specifier) {
    char ch = *(currentSymbol.format + specifier->length);
    if (ch == 'h' || ch == 'l' || ch == 'L') {
        specifier->lengthSymbol = ch;
        specifier->length++;
    }
    return 0;
}

void carriage_leveler(const char **str, Counter *counter) {
    while (**str == ' ' || **str == '\n' || **str == '\t') {
        *str = *str + 1;
        counter->readSymbols++;
    }
}

bool check_separator(const char *ch) {
    bool result = false;
    if (*ch == ' ' || *ch == '\t' || *ch == '\n') {
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
