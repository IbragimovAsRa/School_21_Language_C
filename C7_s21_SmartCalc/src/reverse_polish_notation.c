
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

    Node currentToken;

    while (listInfix) {
        currentToken = *listInfix;
        token_handler(currentToken, &listPostfix, &stackTokens);
        listInfix = listInfix->next;
    }
    // выгрузка оставшихся операторов в стеке
    Node tmp_node;
    while (peek(stackTokens) != NULL) {
        tmp_node = pop(&stackTokens);
        if (tmp_node.data.symb != ')') {
            add_node_as_node(&listPostfix, tmp_node);
        }
    }

    return listPostfix;
}

void token_handler(Node token, Node **listPostfix, Stack *stackTokens) {
    switch (token.dataType) {
        case NUM:
            num_solver(token, listPostfix);
            break;
        case SYMB:
            symb_solver(token, listPostfix, stackTokens);
            break;
        // case CMND:
        //     cmnd_solver(token.data, listPostfix, stackTokens);
        //     break;
        default:
            break;
    }
}

void num_solver(Node token, Node **listPostfix) {
    add_node_as_node(listPostfix, token);
}

void symb_solver(Node token, Node **listPostfix, Stack *stackTokens) {
    int prior = get_priority(token);

    //- Выталкивание из стека токенов с меньшим приоритетом:
    Node *peekStack = peek(*stackTokens);
    if (token.data.symb != '(') {
        while (peekStack != NULL && get_priority(*peekStack) >= prior) {
            if (peekStack->data.symb != '(') {
                add_node_as_node(listPostfix, pop(stackTokens));
            } else {
                pop(stackTokens);
                break;
            }
            peekStack = peek(*stackTokens);
        }
    }
    if (token.data.symb != ')') {
        push(stackTokens, token);
    }
}

// void cmnd_solver(Data data, Node **listPostfix, Stack *stackTokens) {}

int get_priority(Node token) {
    int priority = 0;
    switch (token.data.symb) {
        case ')':
            priority = 0;
            break;
        case '(':
            priority = 1;
            break;
        case '+':
        case '-':
            priority = 2;
            break;
        case '*':
        case '/':
            priority = 3;
            break;
        case '^':
            priority = 4;
            break;
        default:
            break;
    }
    return priority;
}
//
