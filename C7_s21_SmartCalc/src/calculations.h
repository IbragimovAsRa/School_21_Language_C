#ifndef CALCULATIONS_H
#define CALCULATIONS_H


#include <math.h>
#include "datastructs/stack_list.h"
#include "datastructs/stack_num.h"


double calc(Stack *stackToken);
void token_processor(Node token, StackNum *StackNum);

#endif  // CALCULATIONS_H