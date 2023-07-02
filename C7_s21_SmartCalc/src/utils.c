#include "utils.h"

void list_to_stack(Node *list, Stack *stack) {
    Stack tmpStack;
    init_stack(&tmpStack);
    while (list) {
        push(&tmpStack, *list);
        list = list->next;
    }
    while(is_empty(tmpStack) == 0) {
        push(stack, pop(&tmpStack));
    }
}
