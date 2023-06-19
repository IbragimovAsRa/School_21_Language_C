#include "stack_num.h"

void init_stack_num(StackNum *stackNum) {
    stackNum->size = 0;
}

void push_stack_num(StackNum *stackNum, const double value) {
    stackNum->numbers[stackNum->size] = value;
    stackNum->size++;
}

double pop_stack_num(StackNum *stackNum) {
    double result;
    result = StackNum->numbers[stackNum->size];
    stackNum->size++;
}

int is_empty_stack_num(StackNum *stackNum) {
    int result = 0;
    if (stackNum->size == 1) {
        result = 1;
    }
    return result;
}
