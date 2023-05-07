#include "stack_char.h"

void init(Stack *stk) { stk->top = 0; }

void push(Stack *stk, char ch) {
    if (stk->top < STRMAX) {
        stk->elem[stk->top] = ch;
        stk->elem[stk->top + 1] = '\0';
        stk->top++;
    } else {
        printf("Стек полон, количество элементов: %d !\n", stk->top);
    }
}

char pop(Stack *stk) {
    char result = '~';  // Stack is empty
    if ((stk->top) > 0) {
        stk->top--;
        result = stk->elem[stk->top];
        stk->elem[stk->top] = '\0';
    }
    return result;
}

char stkTop(Stack *stk) {
    char result = '~';
    if ((stk->top) > 0) {
        result = stk->elem[stk->top - 1];
    }
    return result;
}

int getCount(Stack *stk) { return stk->top; }

int isEmpty(Stack *stk) {  // Check empty stack
    int result = 0;
    if (stk->top == 0) {
        result = 1;
    }
    return result;
}

void stkPrint(Stack *stk) {
    int i = 0;
    i = stk->top - 1;
    if (isEmpty(stk) == 0) {
        while (i > -1) {
            printf("%c", stk->elem[i]);
            i--;
        }
    }
}