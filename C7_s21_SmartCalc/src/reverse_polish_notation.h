#ifndef REVERSE_POLISH_NOTATION_H
#define REVERSE_POLISH_NOTATION_H

#include "stack_list.h"

// infix notation -> postfix notation

Node *get_postfix_notation(
    Node *listInfix);  // На вход поступает уже выражение прошедшее валидацию
void token_handler(Node token, Node **listPostfix, Stack *stackTokens);
void num_solver(Data data, Node **listPostfix);
void symb_solver(Data data, Node **listPostfix, Stack *stackTokens);
void cmnd_solver(Data data, Node **listPostfix, Stack *stackTokens);
int get_priority(char symb);

#endif  // REVERSE_POLISH_NOTATION_H