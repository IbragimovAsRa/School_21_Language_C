#include "parse_input.h"

#include <string.h>

int parse_input_str(char *str, Node **head) {
    int result_code = 0;
    while (*str != '\0' && result_code == 0) {
        result_code = check_symb(str, head);
        result_code = check_num(&str, head);
        result_code = check_cmnd(&str, head);
        str++;
    }
    return result_code;
}

int check_symb(char *str, Node **head) {
    int result_code = 0;
    Data tmp_data;
    if (*str == '+' || *str == '-' || *str == '*' || *str == '/' ||
        *str == '(' || *str == ')' || *str == '^') {
        tmp_data.symb = *str;
        add_node(head, tmp_data, SYMB);
    }
    return result_code;
}

int check_num(char **str, Node **head) {  // добавить валидацию
    int result_code = 0;
    Data tmp_data;
    char *endptr = NULL;
    char num_str[STRMAX] = "!";
    int i = 0;
    while (((int)**str > 47 && (int)**str < 58) || **str == '.') {
        num_str[i] = **str;
        i++;
        *str = *str + 1;
    }
    if (i > 0) {
        tmp_data.num = 0;
        tmp_data.num = strtod(num_str, &endptr);
        add_node(head, tmp_data, NUM);
        *str = *str - 1;
    }
    return result_code;
}

int check_cmnd(char **str, Node **head) {
    int result_code = 0;
    char cmnd_str[CMNDMAX];
    int i = 0;
    Data tmp_data;

    while ((int)*(*str + i) > 96 && (int)*(*str + i) < 123) {
        if (i >= CMNDMAX) {
            result_code = 1;
        } else {
            cmnd_str[i] = *(*str + i);
            i++;
        }
    }
    if (i > 0 && result_code == 0) {
        char valid[CMNDCOUNT][CMNDMAX] = {{"cos"},  {"sin"},  {"tan"},
                                          {"acos"}, {"asin"}, {"atan"},
                                          {"sqrt"}, {"ln"},   {"log"}};
        // validity check
        result_code = 1;
        for (int j = 0; j < CMNDCOUNT; j++) {
            if (strcmp(valid[j], cmnd_str) == 0) {
                memcpy(tmp_data.cmnd, cmnd_str, sizeof(cmnd_str));
                add_node(head, tmp_data, CMND);
                *str = *str + (i - 1);
                result_code = 0;
                break;
            }
        }
    }
    return result_code;
}

/*
cos(x)
sin(x)
tan(x)
acos(x)
asin(x)
atan(x)
sqrt(x)
ln(x)
log(x)
*/
