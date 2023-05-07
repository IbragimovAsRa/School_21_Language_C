#ifndef STACK_CHAR_H
#define STACK_CHAR_H

#include <stdio.h>
#include <stdlib.h>
#define STRMAX 256
 

typedef struct Stack {
  char elem[STRMAX];
  int top;
} Stack;


void init(Stack *stk);
void push(Stack *stk, char ch);
char pop(Stack *stk);
char stkTop(Stack *stk);
int getCount(Stack *stk);
int isEmpty(Stack *stk);
void stkPrint(Stack *stk);

#endif // STACK_CHAR_H