
#include "reverse_polish_notation.h"

/*
-----------------------------------------------------
Алгоритм перевода в польскую нотацию:

    -Принцип работы алгоритма Дейкстра:

    -Проходим исходную строку;

    -При нахождении числа, заносим его в выходную строку;

    -При нахождении оператора, заносим его в стек;

    -Выталкиваем в выходную строку из стека все операторы, имеющие приоритет
    выше рассматриваемого;

    -При нахождении открывающейся скобки, заносим её в стек;

    -При нахождении закрывающей скобки, выталкиваем из стека все операторы до
    открывающейся скобки, а открывающуюся скобку удаляем из стека.
-----------------------------------------------------

|----------|-----------|
| Опеpация | Пpиоpитет |
|----------|-----------|
|    (     |     0     |
|    )     |     1     |
|   +|-    |     2     |
|   *|/    |     3     |
|   **     |     4     |
|----------|-----------|

*/

Node *get_postfix_notation(Node *listInfix) {
    Node *listPostfix;
    init_list(&listPostfix);

    Stack stackTokens;
    init_stack(&stackTokens);

    Node currentToken = NULL;

    while (listInfix) {
        currentToken = *listInfix;
        token_handler(currentToken);
        listInfix = listInfix->next;
    }
    return listPostfix;
}

void token_handler(Node token, Node **listPostfix, Stack *stackTokens) {
    switch (token.dataType) {
        case NUM:
            num_solver(token.data, listPostfix);
            break;
        case SYMB:
            symb_solver(token.data, listPostfix);
            break;
        case CMND:
            cmnd_solver(token.data, listPostfix, stackTokens);
            break;
        default:
            default;
    }
}

void num_solver(Data data, Node **listPostfix) {
    add_node(listPostfix, data, NUM);
}

void symb_solver(Data data, Node **listPostfix, Stack *stackTokens) {
    int priority = get_priority(data.symb);
    //- Выталкивание из стека токенов с меньшим приоритетом:
    Node *peekStack = peek(stackTokens);
    Node *tmpNode = NULL;
    while (peekStack != NULL && get_priority(peekStack) > priority ) {
        add_node_as_node(listPostfix, *(pop(stackTokens)));
        peekStack = peek(stackTokens);
    }
    //-
}

void cmnd_solver(Data data, Node **listPostfix, Stack *stackTokens) {}

int get_priority(char symb) {
    int priority
    

}
//
