#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define STRMAX 256
#define CMNDMAX 5

#include <stdio.h>
#include <stdlib.h>

typedef enum DataType {
    NUM,
    SYMB,  // + - / * ^ ( )
    CMND
} DataType;

typedef union Data {
    double num;
    char symb;
    char cmnd[CMNDMAX];
} Data;

typedef struct Node {
    DataType dataType;
    Data data;
    struct Node *next;
} Node;

void init_list(Node **head);

Node* new_node(Data data, DataType dataType);
void add_node(Node **head, Data data, DataType dataType);
void add_node_as_node(Node **head, Node newNode);
void destroy(Node *head);
Node* get_by_index(Node *head, int index);
void print_list(Node *head);

#endif  // LINKED_LIST_H