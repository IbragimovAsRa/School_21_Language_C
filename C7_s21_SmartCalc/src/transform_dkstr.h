#ifndef TRANSFORM_DKSTR_H
#define TRANSFORM_DKSTR_H

#include <stdio.h>

#include "stack_char.h"

// typedef struct Token {

// } Token

int transformDkstr(char *infixStr, char *postfixStr);
int getPriority(char ch);
int parseInfixStr(char *infixStr);

#endif  // TRANSFORM_DKSTR_H`