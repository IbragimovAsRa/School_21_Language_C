#include "parse_input.h"
#include "reverse_polish_notation.h"

int main() {
    char* str1 = "2*(3^2-1)+2";
    char* str2 = "2*(3-1)+2";
    Node* head1 = NULL;
    Node* head2 = NULL;

    parse_input_str(str1, &head1);
    parse_input_str(str2, &head2);
    int result = is_equal(head1, head2);
    printf("result = %i\n", result);
    destroy(head2);
    destroy(head1);

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
1) переименовать переменные кака положено

*/