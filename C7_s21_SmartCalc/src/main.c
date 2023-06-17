

#include <clog.h>

int main() {
    clog_init(CLOG_LEVEL_DEBUG);  // Инициализация clog с уровнем DEBUG

    clog_debug("Это отладочное сообщение");
    clog_info("Это информационное сообщение");
    clog_warn("Это предупреждение");
    clog_error("Это сообщение об ошибке");
    clog_fatal("Это фатальная ошибка");

    return 0;
}

// #include "parse_input.h"
// #include "stack_list.h"

// int main() {
//     // test parseInput
//     char* str = "+-121sin(3)1.231*^/";
//     Node* head = NULL;
//     parse_input_str(str, &head);
//     print_list(head);
//     destroy(head);

//     return 0;
// }

// стиль

/*
- примитивные типы данных, имена файлов, имена функций через нижнее
подчеркивание
- имена структурух и юнионов кэмелкейс
*/
