#include "../s21_string.h"

// s21_size_t s21_strspn(const char *str1, const char *str2) {
//     s21_size_t counter = 0;
//     for (const char *first = str1; *first; first++) {
//         unsigned short cot = 0;
//         for (const char *second = str2; *second; second++) {
//             if (*first == *second) {
//                 counter++;
//                 cot = 1;
//                 break;
//             }
//         }
//         if (!cot)
//             break;
//     }
//     return counter;
// }

s21_size_t s21_strspn(const char *str1, const char *str2) {
    s21_size_t counter = 0;

    for (const char *a = str1; *a; a++) {
        unsigned short was = 0;
        for (const char *b = str2; *b; b++) {
            if (*a == *b) {
                counter++;
                was = 1;
                break;
            }
        }
        if (!was)
            break;
    }
    return counter;
}