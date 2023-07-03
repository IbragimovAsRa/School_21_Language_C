#include <math.h>

#include "calculations.h"
#include "parse_input.h"
#include "reverse_polish_notation.h"
#include "utils.h"

int main() {
    char* str = "-2*-5";
    Node* infixStr = NULL;
    Node* postfixStr = NULL;
    double result;
    Stack stackToken;
    init_stack(&stackToken);

    parse_input_str(str, &infixStr);
    infix_to_postfix_notation(infixStr, &postfixStr);
    list_to_stack(postfixStr, &stackToken);
    calc(&stackToken, &result);

    destroy(infixStr);
    destroy(postfixStr);
    printf("result = %lf\n", result);
    return 0;
}

/* Стиль

- примитивные типы данных, имена файлов, имена функций через нижнее
подчеркивание
- имена структурух и юнионов кэмелкейс

*/

/* Полезные ссылки
- Реализация стека (https://learnc.info/adt/stack.html)
- Онлайн конвертер (https://www.semestr.online/informatics/polish.php)

*/

/*  Сделать
1) доделать си библиотеку
2) изучить cmake
3) слить

*/