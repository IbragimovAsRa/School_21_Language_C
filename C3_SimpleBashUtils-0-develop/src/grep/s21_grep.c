#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include "string.h"
#include "utils/list.h"

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
    int count_pattern_in_file;
    char *filename;
    char *str;
    command_line_options options;
    int cflag;
    bool multi_files;
    bool flag_l_helper;
    int flag_n_helper;
    bool flag_c_helper;
    bool flag_v_helper;

} dispatcher_config;

dispatcher_config init_dispatcher_config(command_line_options options, int count_files);
int find_index_start_files(int argc, char **argv); // функция для определения индекса аргумента с которого должно начинаться перечисление файлов
int str_length(FILE *fp);
bool search_by_pattern(char *str, char *pattern, int cflag);
bool pattern_is_in_file(char *filename, char *pattern);
command_line_options command_line_dispatcher(int argc, char **argv);
bool patterns_finder_in_str(char *str, command_line_options clo, int cflag); // multi -e
void grep_dispatcher(command_line_options options, struct Node* files_storage_head); // add multi files / multi flags
struct Node* parse_files( int argc, char **argv );
void get_pattern_from_file(char *filename, struct Node** pattern_storage);
void output(dispatcher_config config);
bool str_read(FILE *fp, int length, char *output_str);
bool check_eof(FILE *fp); // вызывать когда на границе строки

int main(int argc, char **argv) {
    command_line_options options = command_line_dispatcher(argc, argv);
    struct Node* files_storage_head = parse_files(argc, argv);
    grep_dispatcher(options, files_storage_head);


    return 0;
}
bool str_read(FILE *fp, int length, char *output_str) {

    for (int i = 0; i < length - 1; i++) {
        fscanf(fp, "%c", output_str + i);
    }
    *(output_str + (length-1)) = '\n';
    //fseek(fp, 1, SEEK_CUR);
    return true;
}
bool patterns_finder_in_str(char *str, command_line_options options, int cflag) {
    bool result = false;
    for (int i = 0; i < get_size(options.pattern_storage); i++ ) {
        if (search_by_pattern(str, get_by_index(options.pattern_storage, i)->str, cflag)) {
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
    length ++;
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
    bool flag_eof;

    int counter_files = 0;
    int count_files = get_size(files_storage_head);
    dispatcher_config config = init_dispatcher_config(options, count_files);

    while (counter_files < count_files) {
        flag_eof = false;
        config.count_pattern_in_file = 0;
        config.flag_n_helper = 0;
        config.flag_l_helper = false;
        config.filename = get_by_index(files_storage_head,counter_files)->str;
        FILE *fp = fopen(config.filename, "r");

        if (fp == NULL) {
            if (!options.s) {
                printf("grep: %s: No such file or directory\n", config.filename);
            }
            counter_files++;
            continue;
        }



        int str_size = str_length(fp);
        config.str = (char *) malloc(str_size * sizeof(char));
        while (!flag_eof) {
            str_read(fp, str_size, config.str);
            printf("%s", config.str);
            flag_eof = check_eof(fp);
           // config.flag_n_helper++;
//            if (patterns_finder_in_str(config.str, options, config.cflag)) {
//                config.flag_v_helper = true;
//            } else {
//                config.flag_v_helper = false;
//            }
//            if (!((!config.flag_v_helper && !options.v) || (config.flag_v_helper && options.v))) {
//                config.count_pattern_in_file++;
//                //output(config);
//            }
            str_size = str_length(fp);
            free(config.str);
            config.str = (char *) malloc(str_size * sizeof(char));
        }



        if (config.count_pattern_in_file > 0) {
            config.flag_l_helper = true;
        }
        config.flag_c_helper = true;
        //output(config);
        config.flag_c_helper = false;
        counter_files++;
        free(config.str);
        fclose(fp);
    }
}
bool check_eof(FILE *fp) {
    bool result;
    char ch;
    if (fscanf(fp,"%c", &ch) == EOF) {
        result = true;
    } else if (fscanf(fp,"%c", &ch) == EOF) {
        result = true;
    } else {
        result =false;
        fseek(fp, -1, SEEK_CUR);
    }
    return result;
}
dispatcher_config init_dispatcher_config(command_line_options options, int count_files){
    dispatcher_config config;
    config.flag_c_helper = false;
    if (options.i){
        config.cflag = REG_ICASE;
    } else {
        config.cflag = 0;
    }
    if (count_files > 1) {
        config.multi_files = true;
    } else {
        config.multi_files = false;
    }
    config.options = options;
    return config;
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
void output(dispatcher_config config) {
    if (config.options.c) {
        if (config.flag_c_helper) {
            if (config.multi_files) {
                printf("%s:", config.filename);
            }
            printf("%i\n", config.count_pattern_in_file);
        }
    } else if (config.options.l) {
        if (config.flag_l_helper) {
            printf("%s\n", config.filename);
        }
    } else { // формирование выходной строки
        if (config.multi_files && (!config.options.h)) {
            printf("%s:", config.filename);
        }
        if (config.options.n) {
            printf("%i:", config.flag_n_helper);
        }
        printf("%s", config.str);
    }
}
