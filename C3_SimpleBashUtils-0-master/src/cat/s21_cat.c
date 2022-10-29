
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int nextRowIsEmpt(FILE *f);// возвращает 1 если строка следующая пустая, 0 в противном случае, 2 конец файла (вызывать только когда с = \n)
int main(int argc, char **argv) {
    FILE *f;
    // переменная в которую будет помещаться считанные символы
    char c;
    f = fopen("test.txt", "r");
    // Проверка открытия файла
    if (f == NULL) {
        printf("ошибка открытия файла\n");
        return -1;
    }
    for (int i = 0; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }

    if (argc == 1) {
        printf("Command line has no additional arguments\n");
    }
    if (argc == 2) {
        // считывание из файла посимвольно
        while (fscanf(f, "%c", &c) != EOF) {
            printf("%c", c);
        }
    }
    if (argc == 3 && strcmp(argv[1], "-b") == 0) {
        int i = 1;
        while (fscanf(f, "%c", &c) != EOF) {
            if (c == '\n' && i == 1) { //проверка пустоты первой строки
                printf("%c", c);
            } else if (i == 1 && nextRowIsEmpt(f) == 0) {
                printf("%6i\t", i);
                printf("%c", c);
                i++;
            } else {
                printf("%c", c);
                if (c == '\n' && nextRowIsEmpt(f) == 0) {
                    printf("%6i\t", i);
                    i++;
                }
            }
        }
    }
    if (argc == 3 && strcmp(argv[1], "-e") == 0) {
        while (fscanf(f, "%c", &c) != EOF) {
            if (c == '\n') {
                printf("$");
            }
            printf("%c", c);
        }
    }
    if (argc == 3 && strcmp(argv[1], "-n") == 0) {
        int i = 1;
        while (fscanf(f, "%c", &c) != EOF) {
            if (i == 1) {
                printf("%6i\t", i);
                i++;
            } else {
                printf("%c", c);
                if (c == '\n') {
                    printf("%6i\t", i);
                    i++;
                }
            }
        }
    }
    if (argc == 3 && strcmp(argv[1], "-s") == 0) {
        int flag = 1; // если 0, то надо ставить, 1 не надо ставить
int flagStart = 1;
        while (fscanf(f, "%c", &c) != EOF) {
            if (flagStart == 1) {
                if (c == '\n') {
                    printf("\n");
                }
                flagStart = 0;
            }
            // обработчик пустых строк
            if (c == '\n' && flagStart == 0) {
                // может быть всего 2 исхода, 1 - один entert, 2 - два enter
                if (flag == 0 && nextRowIsEmpt(f) == 1) {
                    printf("\n\n");
                } else if(flag == 0) {
                    printf("\n");
                }
                flag = 1;
            }
            if (c != '\n' && flagStart == 0) {
                printf("%c", c);
                flag = 0;
            }

        }
    }

    fclose(f);
    return 0;
}

int nextRowIsEmpt(FILE *f) {
    char next;
    if (fscanf(f, "%c", &next) != EOF) {
        fseek(f, -1, SEEK_CUR);
        if (next == '\n') {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 2;
    }
}
