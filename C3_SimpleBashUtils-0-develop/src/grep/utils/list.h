#ifndef UTILS_LIST_H_
#define UTILS_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "list.h"

struct Node {
    char *str;
    struct Node *next;
};
void add_Node(struct Node **head, char *pattern);
struct Node* newNode(char *pattern);
void printList(struct Node* head);
struct Node* get_by_index(struct Node *head, int index);
void destroy(struct Node *head);
int get_size(struct Node *head);

#endif  // UTILS_LIST_H_