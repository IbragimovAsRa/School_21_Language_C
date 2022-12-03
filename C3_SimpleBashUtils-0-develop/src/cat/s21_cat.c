#include "stdio.h"
#include "string.h"
#include "stdbool.h"

typedef struct {
    bool b;
    bool number_non_blank;
    bool e;
    bool E;
    bool n;
    bool number;
    bool s;
    bool squeeze_blank;
    bool t;
    bool T;
    bool no_options;
} config;

config command_line_dispatcher(int argc, char **argv);

int next_row_is_empty(
        FILE *fp); // возвращает 1 если строка следующая пустая, 0 в противном случае, 2 конец файла (вызывать только когда с = \n)
int solver_default(int argc, char **argv);

int solver_b(int argc, char **argv, FILE *fp);

int solver_e(int argc, char **argv, FILE *fp);

int solver_E(int argc, char **argv, FILE *fp);

int solver_n(int argc, char **argv, FILE *fp);

int solver_s(int argc, char **argv, FILE *fp);

int solver_t(int argc, char **argv, FILE *fp);

int solver_T(int argc, char **argv, FILE *fp);

int handler(config options, int argc, char **argv);

int main(int argc, char **argv) {
    config options = command_line_dispatcher(argc, argv);
    handler(options, argc, argv);
    return 0;
}

int handler(config options, int argc, char **argv) {
    if (options.no_options) {
        solver_default(argc, argv);
    } else {
        FILE *fp = fopen(argv[2], "r");

        if (options.b || options.number_non_blank) {
            solver_b(argc, argv, fp);
        }
        if (options.e) {
            solver_e(argc, argv, fp);
        }
        if (options.E) {
            solver_E(argc, argv, fp);
        }
        if (options.n || options.number) {
            solver_n(argc, argv, fp);
        }
        if (options.s || options.squeeze_blank) {
            solver_s(argc, argv, fp);
        }
        if (options.t) {
            solver_t(argc, argv, fp);
        }
        if (options.T) {
            solver_T(argc, argv, fp);
        }
        fclose(fp);
    }
    return 0;
}

config command_line_dispatcher(int argc, char **argv) {
    config options = {false, false, false, false, false, false, false, false, false, false, false};
    if (argv[1][0] != '-') {
        options.no_options = true;
        return options;
    }
    if (strcmp(argv[1], "-b") == 0) {
        options.b = true;
    }
    if (strcmp(argv[1], "--number-nonblank") == 0) {
        options.number_non_blank = true;
    }
    if (strcmp(argv[1], "-e") == 0) {
        options.e = true;
    }
    if (strcmp(argv[1], "-E") == 0) {
        options.E = true;
    }
    if (strcmp(argv[1], "-n") == 0) {
        options.n = true;
    }
    if (strcmp(argv[1], "--number") == 0) {
        options.number = true;
    }
    if (strcmp(argv[1], "-s") == 0) {
        options.s = true;
    }
    if (strcmp(argv[1], "--squeeze-blank") == 0) {
        options.squeeze_blank = true;
    }
    if (strcmp(argv[1], "-t") == 0) {
        options.t = true;
    }
    if (strcmp(argv[1], "-T") == 0) {
        options.T = true;
    }
    return options;
}

int solver_default(int argc, char **argv) {
    char ch;
    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        while (fscanf(fp, "%c", &ch) != EOF) {
            printf("%c", ch);
        }
        fclose(fp);
    }
    return 0;
}

int solver_b(int argc, char **argv, FILE *fp) {
    char ch;
    int i = 1;
    while (fscanf(fp, "%c", &ch) != EOF) {
        if (ch == '\n' && i == 1) { //проверка пустоты первой строки
            printf("%c", ch);
        } else if (i == 1 && next_row_is_empty(fp) == 0) {
            printf("%6i\t", i);
            printf("%c", ch);
            i++;
        } else {
            printf("%c", ch);
            if (ch == '\n' && next_row_is_empty(fp) == 0) {
                printf("%6i\t", i);
                i++;
            }
        }
    }
    return 0;
}

int solver_e(int argc, char **argv, FILE *fp) {
    int sim;
    char ch;
    while (fscanf(fp, "%c", &ch) != EOF) {
        sim = (int) ch;
        if (ch == '\n') {
            printf("$");
            printf("\n");
        } else if ((int) ch == 9) {
            printf("%c", ch);
            continue;
        } else if (sim >= 0 && sim < 32 && sim != 10 && sim != 9) {
            printf("^%c", sim + 64);
        } else if (sim == 127) {
            printf("^?");

        } else {
            printf("%c", ch);
        }
    }
    return 0;
}

int solver_E(int argc, char **argv, FILE *fp) {
    char ch;
    while (fscanf(fp, "%c", &ch) != EOF) {
        if (ch == '\n') {
            printf("$");
        }
        printf("%c", ch);
    }
    return 0;
}

int solver_n(int argc, char **argv, FILE *fp) {
    int i = 1;
    char ch;
    printf("%6i\t", i);
    i++;
    while (fscanf(fp, "%c", &ch) != EOF) {
        if (next_row_is_empty(fp) == 2 && ch == '\n') {
            printf("\n");
            break;
        }
        printf("%c", ch);
        if (ch == '\n') {
            printf("%6i\t", i);
            i++;
        }
    }
    return 0;
}

int solver_s(int argc, char **argv, FILE *fp) {
    int flag = 1; // если 0, то надо ставить, 1 не надо ставить
    int flagStart = 1;
    char ch;
    while (fscanf(fp, "%c", &ch) != EOF) {
        if (flagStart == 1) {
            if (ch == '\n') {
                printf("\n");
            }
            flagStart = 0;
        }
        // обработчик пустых строк
        if (ch == '\n') {
            // может быть всего 2 исхода, 1 - один entert, 2 - два enter
            if (flag == 0 && next_row_is_empty(fp) == 1) {
                printf("\n\n");
            } else if (flag == 0) {
                printf("\n");
            }
            flag = 1;
        }
        if (ch != '\n') {
            printf("%c", ch);
            flag = 0;
        }
    }
    return 0;
}

int solver_t(int argc, char **argv, FILE *fp) {
    int sim;
    char ch;
    while (fscanf(fp, "%c", &ch) != EOF) {
        sim = (int) ch;
        if (ch == '\t') {
            printf("^I");
        } else
        if (ch == '\n') {
            printf("\n");
        } else if (ch == 9) {
            printf("%c", ch);
            continue;
        } else if (sim >= 0 && sim < 32 && sim != 10 && sim != 9) {
            printf("^%c", sim + 64);
        } else if (sim == 127) {
            printf("^?");

        } else {
            printf("%c", ch);
        }
    }
    return 0;
}

int solver_T(int argc, char **argv, FILE *fp) {
    char ch;
    while (fscanf(fp, "%c", &ch) != EOF) {
        if (ch == '\t') {
            printf("^I");
        } else {
            printf("%c", ch);
        }
    }
    return 0;
}

int next_row_is_empty(FILE *fp) {
    char next;
    if (fscanf(fp, "%c", &next) != EOF) {
        fseek(fp, -1, SEEK_CUR);
        if (next == '\n') {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 2;
    }
}