#ifndef PARSE_INPUT_H
#define PARSE_INPUT_H

#define CMNDCOUNT 9

#include "datastructs/linked_list.h"

// input str -> structured linked list (должна осуществляться валидация входной
// строки)

int parse_input_str(char *str, Node **head);
int check_symb(char *str, Node **head);
int check_num(char **str, Node **head);
int check_cmnd(char **str, Node **head);

#endif  // PARSE_INPUT_H