#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include <math.h>

#include "datastructs/stack_list.h"
#include "datastructs/stack_num.h"

void calc(Stack *stackToken, double *result);
void token_processor(Node token, StackNum *stackNum);
void num_handler(double num, StackNum *stackNum);
void symb_handler(char symb, StackNum *stackNum);

#endif  // CALCULATIONS_H