#include "linked_list.h"

void init_list(Node **head) {
    *head = NULL;
}
Node *new_node(Data data, DataType dataType) { // ssgsdg
    Node *node;
    node = malloc(sizeof(Node));
    node->dataType = dataType;
    node->data = data;
    node->next = NULL;
    return node;
}

void add_node(Node **head, Data data, DataType dataType) {
    Node *current = *head;
    Node *node = new_node(data, dataType);
    if (current == NULL) {
        *head = node;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
}

void add_node_as_node(Node **head, Node newNode) {
    Node *current = *head;
    Node *node = new_node(newNode.data, newNode.dataType);
    if (current == NULL) {
        *head = node;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
}

Node *get_by_index(Node *head, int index) {
    Node *ptr = head;
    int counter = 0;
    while (ptr && counter != index) {
        counter++;
        ptr = ptr->next;
    }
    return ptr;
}
void destroy(Node *head) {
    Node *prev = head;
    while (head != NULL) {
        head = head->next;
        free(prev);
        prev = head;
    }
}
void print_list(Node *head) {
    struct Node *ptr = head;
    int i = 0;
    while (ptr) {
        switch (ptr->dataType) {
            case 0:
                printf("Elem %i: type = NUM, num = %f  ->\n", i, ptr->data.num);
                break;
            case 1:
                printf("Elem %i: type = SYMB, symb = '%c'  ->\n", i,
                       ptr->data.symb);
                break;
            case 2:
                printf("Elem %i: type = CMND, cmnd = %s  ->\n", i,
                       ptr->data.cmnd);
                break;
            default:
                printf("Elem %i: XZ\n", i);
        }
        ptr = ptr->next;
        i++;
    }
}
