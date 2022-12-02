#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include "string.h"

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
        FILE *f); // возвращает 1 если строка следующая пустая, 0 в противном случае, 2 конец файла (вызывать только когда с = \n)
int solver_default(int argc, char **argv);

int solver_b(int argc, char **argv);

int solver_e(int argc, char **argv);

int solver_E(int argc, char **argv);

int solver_n(int argc, char **argv);

int solver_s(int argc, char **argv);

int solver_t(int argc, char **argv);

int solver_T(int argc, char **argv);

int handler(config options, int argc, char **argv);

int main(int argc, char **argv) {
    config options = command_line_dispatcher(argc, argv);
    handler(options, argc, argv);
    return 0;
}

int handler(config options, int argc, char **argv) {
    if (options.no_options) {
        solver_default(argc, argv);
    }
    if (options.b || options.number_non_blank) {
        solver_b(argc, argv);
    }
    if (options.e) {
        solver_e(argc, argv);
    }
    if (options.e) {
        solver_e(argc, argv);
    }
    if (options.e) {
        solver_e(argc, argv);
    }
    if (options.e) {
        solver_e(argc, argv);
    }
    if (options.e) {
        solver_e(argc, argv);
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

int solver_b(int argc, char **argv) {
    return 0;
}

int next_row_is_empty(FILE *f) {
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