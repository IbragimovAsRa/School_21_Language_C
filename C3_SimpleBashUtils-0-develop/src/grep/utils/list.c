#include "list.h"


void add_Node(struct Node **head, char *pattern) {
    struct Node* current = *head;
    struct Node* node = newNode(pattern);
    if (current == NULL) {
        *head = node;
    }
    else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
}
struct Node* newNode(char *pattern) {
    struct Node *node;
    node = malloc(sizeof (struct Node));
    node->str = malloc(strlen(pattern)*sizeof (char));
    strcpy(node->str, pattern);
    node->next = NULL;
    return node;
}
struct Node* get_by_index(struct Node *head, int index) {
    struct Node* ptr = head;
    int counter = 0;
    while (ptr && counter != index ) {
        counter++;
        ptr = ptr->next;
    }
    return ptr;
}
void printList(struct Node* head) {
    struct Node* ptr = head;

    while (ptr)
    {
        printf("%s —> ", ptr->str);
        ptr = ptr->next;
    }

    printf("NULL\n");
}
void destroy(struct Node *head) {
    struct Node *tmp;
    while(head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp->str);
        free(tmp);
    }
}
int get_size(struct Node *head) {
    int size = 0;
    while (head != NULL) {
        size++;
        head = head->next;
    }
    return size;
}