#include "transform_dkstr.h"

/* Правила:
1) Если встречается число
    - добавляем к выходной строке
*/

int getPriority(char ch) {
    int priority = 0;
    if (ch == '(') {
        priority = 1;
    } else if (ch == '+' || ch == '-') {
        priority = 2;
    } else if (ch == '*' || ch == '/') {
        priority = 3;
    } else if (ch == '^') {
        priority = 4;
    }
    return priority;
}

int transformDkstr(char *infixStr, char *postfixStr) {
    int i_inf = 0;
    int i_pos = 0;
    char crnt_sym;
    char tmp_stk;
    Stack stack = {};
    init(&stack);
    while (infixStr[i_inf] != '\0' && i_inf < STRMAX) {
        crnt_sym = infixStr[i_inf];
        if ((int)crnt_sym > 47 && (int)crnt_sym < 58) {  // проверка на число
            postfixStr[i_pos] = crnt_sym;
            i_pos++;
        } else if (crnt_sym == '(') {
            push(&stack, crnt_sym);
        } else if (crnt_sym == ')') {
            tmp_stk = '~';
            tmp_stk = pop(&stack);
            while (tmp_stk != '(') {
                postfixStr[i_pos] = tmp_stk;
                tmp_stk = pop(&stack);
                i_pos++;
            }
        } else {
            if (getPriority(stkTop(&stack)) < getPriority(crnt_sym)) {
                push(&stack, crnt_sym);
            } else {
                if (isEmpty(&stack) == 0) {
                    while (getPriority(stkTop(&stack)) >=
                           getPriority(crnt_sym)) {
                        if (isEmpty(&stack) == 0) {
                            tmp_stk = pop(&stack);
                            postfixStr[i_pos] = tmp_stk;
                            i_pos++;
                        } else {
                            break;
                        }
                    }
                    push(&stack, crnt_sym);
                }
            }
        }
        i_inf++;
    }

    if (infixStr[i_inf] == '\0') { // выталкиваем оставшиеся элемента из стека
        tmp_stk = '~';
        tmp_stk = pop(&stack);
        while (tmp_stk != '~') {
            postfixStr[i_pos] = tmp_stk;
            postfixStr[i_pos + 1] = '\0';
            tmp_stk = pop(&stack);
            i_pos++;
        }
    }
    
    return 0;
}