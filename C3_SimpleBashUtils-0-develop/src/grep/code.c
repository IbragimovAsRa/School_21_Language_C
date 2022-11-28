//FILE *fp = fopen(filename, "r");
// флаги -e -i

// итерация по всем строкам файла
/*
    str_size = str_length(fp);
    str = (char*) malloc(str_size * sizeof (char));
    while(fgets(str, str_size + 2 , fp) != NULL) {
        if (search_by_pattern(str, pattern, cflag)) {
            printf("%s", str);
        }
        str_size = str_length(fp);
        free(str);
        str = (char*) malloc(str_size * sizeof (char));
    }
    free(str);
*/
/*
 *
 *    // ____________________________________________________________________________________ multi -e
    str_size = str_length(fp);
    str = (char*) malloc(str_size * sizeof (char));
    while(fgets(str, str_size + 2 , fp) != NULL) {
        if (pattern_finder_in_str(str, options, cflag)) {
            printf("%s", str);
        }
        str_size = str_length(fp);
        free(str);
        str = (char*) malloc(str_size * sizeof (char));
    }
    free(str);
    // ____________________________________________________________________________________
 */

// флаг -v

/*    str_size = str_length(fp);
    str = (char*) malloc(str_size * sizeof (char));
    while(fgets(str, str_size + 2 , fp) != NULL) {
        if (!(search_by_pattern(str, pattern, cflag))) {
            printf("%s", str);
        }
        str_size = str_length(fp);
        free(str);
        str = (char*) malloc(str_size * sizeof (char));
    }
    free(str);*/

// флаг -c
/*    int count = 0;
    str_size = str_length(fp);
    str = (char*) malloc(str_size * sizeof (char));
    while(fgets(str, str_size + 2 , fp) != NULL) {
        if (search_by_pattern(str, pattern, cflag)) {
            count++;
        }
        str_size = str_length(fp);
        free(str);
        str = (char*) malloc(str_size * sizeof (char));
    }
    free(str);
    printf("%i", count);*/

// флаг -l
/*    index_start_files = find_index_start_files(argc, argv);
    for (int i = index_start_files -1 ; i < argc; i ++) {
        if (pattern_is_in_file(argv[i], pattern)) {
            printf("%s\n", argv[i]);
        }
    }*/
// парсинг аргументов командной строки

// printf("options: %i, %i, %i, %i, %i", opt.e, opt.i, opt.v, opt.c, opt.l);


// flag -n
/*
if (options.n) {
printf("input");
int counter_str = 0;
FILE *fp = fopen(filename, "r");
str_size = str_length(fp);
str = (char*) malloc(str_size * sizeof (char));
while(fgets(str, str_size + 2 , fp) != NULL) {
counter_str++;
if (search_by_pattern(str, pattern, cflag)) {
printf("%i:%s",counter_str, str);
}
str_size = str_length(fp);
free(str);
str = (char*) malloc(str_size * sizeof (char));
}
free(str);
fclose(fp);
}
*/

// -e with several files
/*
if (options.e) {
bool multi_files = false;
FILE *fp;
// if count of files less than 1, that filename is not output.
if (argc - index_start_files > 1) {
multi_files = true;
}
if (multi_files) {
for (int i = index_start_files; i < argc; i ++) {
fp = fopen(argv[i], "r");
str_size = str_length(fp);
str = (char*) malloc(str_size * sizeof (char));
while(fgets(str, str_size + 2 , fp) != NULL) {
if (search_by_pattern(str, pattern, cflag)) {
printf("%s:%s",argv[i],str);
}
str_size = str_length(fp);
free(str);
str = (char*) malloc(str_size * sizeof (char));
}
free(str);
fclose(fp);
}
}
}*/




//fclose(fp);




















































#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include "string.h"
#include "utils/list.h"

// grep [options] pattern [files]

// risk of leaks !!!!!!!!!

typedef struct  {
    bool e;
    bool i;
    bool v;
    bool c;
    bool l;
    bool n;
    bool h;
    bool s;
    bool f;
    bool o;
    struct Node* pattern_storage;
} command_line_options; // structure of options

typedef struct {
    int cflag;
    bool multi_files;

} options_config;




int find_index_start_files(int argc, char **argv); // функция для определения индекса аргумента с которого должно начинаться перечисление файлов
int str_length(FILE *fp);
bool search_by_pattern(char *str, char *pattern, int cflag);
bool pattern_is_in_file(char *filename, char *pattern);
command_line_options command_line_dispatcher(int argc, char **argv);
bool patterns_finder_in_str(char *str, command_line_options clo, int cflag); // multi -e
void grep_dispatcher(command_line_options options, struct Node* files_storage_head); // add multi files / multi flags
struct Node* parse_files( int argc, char **argv );
void get_pattern_from_file(char *filename, struct Node** pattern_storage);
void output(command_line_options options, char *str, int count, bool multi_files, char *filename, bool flag_l_helper, int flag_n_helper);

int main(int argc, char **argv) {
    command_line_options options = command_line_dispatcher(argc, argv);
    struct Node* files_storage_head = parse_files(argc, argv);
    grep_dispatcher(options, files_storage_head);
    return 0;
}

bool patterns_finder_in_str(char *str, command_line_options clo, int cflag) {
    bool result = false;
    for (int i = 0; i < get_size(clo.pattern_storage); i++ ) {
        if (search_by_pattern(str, get_by_index(clo.pattern_storage, i)->str, cflag)) {
            result = true;
            break;
        }
    }
    return result;
}
int find_index_start_files(int argc, char **argv) {
    int result = 0;
    bool flag = false;
    // 1 -  no flags ( a.out 'test' filename.txt )
    // 2 - is flags but without -e -files ( a.out -i 'test' filename.txt )
    // 3 - with -e or -files
    if (argv[1][0] != '-') {
        result = 2;
        flag = true;
    }
    if (flag == false) {
        int i = 0;
        while (i < argc) {
            if (argv[i][0] == '-') {
                if (strstr(argv[i], "e") != 0 || strstr(argv[i], "files") != 0) {
                    i++;
                    result++;
                }
                result++;
            }
            i++;
        }
        result = result + 1;
    }

    return result;
}
bool pattern_is_in_file(char *filename, char *pattern) {
    bool result = false;
    int str_size;
    char *str;
    int cflag = REG_ICASE;
    FILE *fp = fopen(filename, "r");
    str_size = str_length(fp);
    str = (char*) malloc(str_size * sizeof (char));
    while(fgets(str, str_size + 2 , fp) != NULL) {
        if (search_by_pattern(str, pattern, cflag)) {
            result = true;
        }
        str_size = str_length(fp);
        free(str);
        str = (char*) malloc(str_size * sizeof (char));
    }
    free(str);
    fclose(fp);
    return result;
}
bool search_by_pattern(char *str, char *pattern, int cflag) {
    bool result = false;
    regex_t regex;
    regcomp(&regex, pattern, cflag);
    if (regexec(&regex, str, 0, NULL, 0) == 0) {
        result = true;
    }
    return result;
}
int str_length(FILE *fp) {
    int length = 0;
    char ch;
    while (fscanf(fp, "%c", &ch) != EOF && ch != '\n') {
        length ++;
    }
    if ( ch == '\n') {
        length ++;
    }
    fseek(fp, -1 * length, SEEK_CUR);
    return length;
}
command_line_options command_line_dispatcher(int argc, char **argv) {
    command_line_options options = {false, false, false, false, false, false, false, false, false, false, NULL};
    int current_arg;
    char *opt_string = "e:ivclnhosf:";
    while ((current_arg = getopt(argc, argv, opt_string)) != -1) {
        switch (current_arg) {
            case 'e':
                options.e = true;
                add_Node(&options.pattern_storage, optarg);
                break;
            case 'i':
                options.i = true;
                break;
            case 'v':
                options.v = true;
                break;
            case 'c':
                options.c = true;
                break;
            case 'l':
                options.l = true;
                break;
            case 'n':
                options.n = true;
                break;
            case 'h':
                options.h = true;
                break;
            case 's':
                options.s = true;
                break;
            case 'f':
                options.f = true;
                get_pattern_from_file(optarg, &options.pattern_storage);
                break;
            case 'o':
                options.o = true;
                break;
        }
    }
    return options;
}
void get_pattern_from_file(char *filename, struct Node** pattern_storage) {
    FILE *fp;
    fp = fopen(filename, "r");
    int str_size = str_length(fp);
    char *str;
    str = (char *) malloc(str_size * sizeof(char));
    while (fgets(str, str_size + 2, fp) != NULL) {
        add_Node(pattern_storage, str);
        str_size = str_length(fp);
        free(str);
        str = (char *) malloc(str_size * sizeof(char));
    }
    free(str);
    fclose(fp);
}
void grep_dispatcher(command_line_options options, struct Node* files_storage_head) {
    // сочетающиеся флаги -e -i -v -files (для поиска) -c -l -n -h(для вывода) взаимоисключающие
    // не сочетающиеся флаги
    bool print;
    char *str;
    int cflag;
    bool flag_l_helper;
    int flag_n_helper;
    int counter = 0;
    int count_files = get_size(files_storage_head);
    bool multi_files = false;
    if (options.i){
        cflag = REG_ICASE;
    } else {
        cflag = 0;
    }
    if (get_size(files_storage_head) > 1) {
        multi_files = true;
    }
    int count;
    while (counter < count_files) {
        count = 0;
        flag_n_helper = 0;
        flag_l_helper = false;

        FILE *fp = fopen(get_by_index(files_storage_head,counter)->str, "r");
        int str_size = str_length(fp);
        str = (char *) malloc(str_size * sizeof(char));

        while (fgets(str, str_size + 2, fp) != NULL) {
            flag_n_helper++;
            if (patterns_finder_in_str(str, options, cflag)) {
                print = true;
            } else {
                print = false;
            }
            if (!((!print && !options.v) || (print && options.v))) {
                count++;
                if (!options.c) {
                    flag_l_helper = true;
                    if (multi_files == true && (!options.l) && (!options.h)) {
                        printf("%s:", get_by_index(files_storage_head, counter)->str);
                    }
                    if (options.n) {
                        printf("%i:", flag_n_helper);
                    }
                    if (!options.l) {
                        printf("%s", str);
                    }
                }
            }
            str_size = str_length(fp);
            free(str);
            str = (char *) malloc(str_size * sizeof(char));
        }
        if (options.c) {
            if (multi_files == true) {
                printf("%s:", get_by_index(files_storage_head, counter)->str);
            }
            printf("%i\n", count);
        }
        if (options.l && flag_l_helper) {
            printf("%s\n", get_by_index(files_storage_head, counter)->str);
        }

        counter++;
        free(str);
        fclose(fp);
    }
}
struct Node* parse_files( int argc, char **argv ) {
    struct Node* files_storage_head = NULL;
    int index_start_files;
    index_start_files = find_index_start_files(argc, argv);
    for (int i = index_start_files; i < argc; i++) {
        add_Node(&files_storage_head, argv[i]);
    }
    return files_storage_head;
}
void output(command_line_options options, char *str, int count, bool multi_files, char *filename, bool flag_l_helper, int flag_n_helper) {
    if (options.c) {
        if (multi_files) {
            printf("%s:", filename);
        }
        printf("%i\n", count);
    } else if (options.l && flag_l_helper) {
        printf("%s\n", filename);
    } else { // формирование выходной строки
        if (multi_files) {
            printf("%s:", filename);
        }
        if (options.n) {
            printf("%i:", flag_n_helper);
        }
        printf("%s", str);
    }

}























regex_t regex;
//        regcomp(&regex, config.options, config.cflag);
//        regmatch_t reg_match[1];
//        int match = 0;
//        int helper = 0;
//        while (match == 0) {
//            match = regexec(&regex, config.str + helper, 1, reg_match, 0);
//            if (match == 0) {
//                for (int i = reg_match[0].rm_so; i < reg_match[0].rm_eo; i++) {
//                    printf("%c", *(config.str + i + helper));
//                }
//                printf("\n");
//                helper = helper + reg_match[0].rm_eo;
//            }
//        }


