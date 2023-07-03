#include "calculations.h"

#include <math.h>

/*
Алгоритм:
1) Если число - помещается в стек
2) Если оператор - достается последние два выражения из стека и вычисляются
результат кладется обратно в стек


*/

void calc(Stack *stackToken, double * result) {
    StackNum stackNum;
    init_stack_num(&stackNum);

    while (is_empty(*stackToken) == 0) {
        token_processor(pop(stackToken), &stackNum);
    }
    *result = pop_num(&stackNum);
}

void token_processor(Node token, StackNum *stackNum) {
    switch (token.dataType) {
        case NUM:
            num_handler(token.data.num, stackNum);
            break;
        case SYMB:
            symb_handler(token.data.symb, stackNum);
            break;
        case CMND:
            break;
        default:
            break;
    }
}

void num_handler(double num, StackNum *stackNum) {
    push_num(stackNum, num);
}

void symb_handler(char symb, StackNum *stackNum) {
    double num_1;
    double num_2;

    num_1 = pop_num(stackNum);
    num_2 = pop_num(stackNum);

    switch (symb) {
        case '+':
            push_num(stackNum, (num_1 + num_2));
            break;
        case '-':
            push_num(stackNum, (num_2 - num_1));
            break;
        case '*':
            push_num(stackNum, (num_1 * num_2));
            break;
        case '/':
            push_num(stackNum, (num_2 / num_1));
            break;
        case '^':
            double a = pow(num_2, num_1);
            push_num(stackNum, a);
            break;
        default:
            break;
    }
}
