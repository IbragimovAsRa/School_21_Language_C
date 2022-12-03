#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include "string.h"
#include "utils/list.h"

typedef struct {
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
    struct Node *pattern_storage;
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
     bool second_flag_n_helper;
    bool flag_c_helper;
    bool flag_v_helper;
    bool default_helper;

} dispatcher_config;
dispatcher_config init_dispatcher_config(command_line_options options, int count_files);
int find_index_start_files(int argc, char **argv); // функция для определения индекса аргумента с которого должно начинаться перечисление файлов
int str_length(FILE *fp);
bool search_by_pattern(char *str, char *pattern, int cflag);
command_line_options command_line_dispatcher(int argc, char **argv);
bool patterns_finder_in_str(char *str, command_line_options clo, int cflag); // multi -e
dispatcher_config grep_dispatcher(command_line_options options, struct Node *files_storage_head); // add multi files / multi flags
struct Node *parse_files(int argc, char **argv);
void get_pattern_from_file(char *filename, struct Node **pattern_storage);
void output(dispatcher_config config);
bool str_read(FILE *fp, int length, char *output_str);
bool check_eof(FILE *fp); // вызывать когда на границе строки
int flag_o_solver(dispatcher_config config);
int free_all(dispatcher_config config,  struct Node *files_storage_head);

int main(int argc, char **argv) {

    command_line_options options = command_line_dispatcher(argc, argv);
    struct Node *files_storage_head = parse_files(argc, argv);
    if (options.e == false && options.f == false) {
        add_Node(&options.pattern_storage, argv[find_index_start_files(argc, argv) - 1]);
    }
    dispatcher_config config = grep_dispatcher(options, files_storage_head);
    free_all(config, files_storage_head);
    return 0;
}

int free_all(dispatcher_config config,  struct Node *files_storage_head) {
    destroy(config.options.pattern_storage);
    destroy(files_storage_head);
    return 0;
}
bool str_read(FILE *fp, int length, char *output_str) {

    for (int i = 0; i < length - 1; i++) {
        fscanf(fp, "%c", output_str + i);
    }
    *(output_str + (length - 1)) = '\n';
    return true;
}
bool patterns_finder_in_str(char *str, command_line_options options, int cflag) {
    bool result = false;
    for (int i = 0; i < get_size(options.pattern_storage); i++) {
        if (search_by_pattern(str, get_by_index(options.pattern_storage, i)->str, cflag)) {
            result = true;
            break;
        }
    }
    return result;
}
int find_index_start_files(int argc, char **argv) {
    int result = 1;
    bool flag = false;
    // 1 -  no flags ( a.out 'test' filename.txt )
    // 2 - is flags but without -e -files ( a.out -i 'test' filename.txt )
    // 3 - with -e or -files


    // возможные исходы

    // 'test' files/file1.txt 1
    // -i  'test' files/file1.txt 1
    // -e 'test' files/file1.txt 1
    // -i -e 'test' files/file1.txt 1
    // -ie 'test' files/file1.txt 1
    // -f files/pat1.txt files/file1.txt 1
    // -f files/pat1.txt -e 'test' files/file1.txt 1
    //  -e 'test' -f files/pat1.txt  files/file1.txt

    if (argv[1][0] != '-') { // случай когда флагов нет
        result = 2;
        flag = true;
    }

    if (!flag) {
        int i = 1;
        bool flag_e;
        bool flag_f;

        while (i < argc) {


            if (argv[i][0] != '-') {
                if (flag_e || flag_f) {
                    break;
                }
                result++;
                break;
            }
            flag_e = false;
            flag_f = false;
            if ((argv[i][0] == '-')&& strstr(argv[i], "e") != 0 ){
                flag_e = true;
            }
            if ((argv[i][0] == '-')&& strstr(argv[i], "f") != 0 ){
                flag_f = true;
            }

            if (flag_e) {
                result ++;
                i++;
            }
            if (flag_f) {
                result ++;
                i++;
            }
            result++;
            i++;
        }
    }

//    if (flag == false) { // флаги есть
//        int i = 0;
//        while (i < argc) {
//            if (argv[i][0] == '-') {
//                if (strstr(argv[i], "e") != 0 || strstr(argv[i], "files") != 0) {
//                    i++;
//                    result++;
//                }
//                result++;
//            }
//            i++;
//        }
//        result = result + 1;
//    }

    return result;
}
bool search_by_pattern(char *str, char *pattern, int cflag) {
    bool result = false;
    regex_t regex;
    regcomp(&regex, pattern, cflag);
    if (regexec(&regex, str, 0, NULL, 0) == 0) {
        result = true;
    }
    regfree(&regex);
    return result;
}
int str_length(FILE *fp) {
    int length = 0;
    char ch;
    while (fscanf(fp, "%c", &ch) != EOF && ch != '\n') {
        length++;
    }
    length++;
    if (ch != '\n') {
        fseek(fp, 1, SEEK_CUR);
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
void get_pattern_from_file(char *filename, struct Node **pattern_storage) {
    FILE *fp;
    fp = fopen(filename, "r");
    char str[100];
    while (fscanf(fp, "%s", str) != EOF) {
        add_Node(pattern_storage, str);
    }
    fclose(fp);
}
dispatcher_config grep_dispatcher(command_line_options options, struct Node *files_storage_head) {
    bool flag_eof;

    int counter_files = 0;
    int count_files = get_size(files_storage_head);
    dispatcher_config config = init_dispatcher_config(options, count_files);
    config.second_flag_n_helper = true;
    while (counter_files < count_files) {
        flag_eof = false;
        config.count_pattern_in_file = 0;
        config.flag_n_helper = 0;
        config.flag_l_helper = false;
        config.filename = get_by_index(files_storage_head, counter_files)->str;
        FILE *fp = fopen(config.filename, "r");

        if (fp == NULL) {
            if (!options.s) {
                printf("grep: %s: No such file or directory\n", config.filename);
            }
            counter_files++;
            continue;
        }
        int iter = 1;
        int str_size = str_length(fp);
        config.str = (char *) malloc(str_size * sizeof(char));
        if (config.options.n) {
            config.second_flag_n_helper = config.options.n;
        }
        config.default_helper = true;
        while (!flag_eof) {

            str_read(fp, str_size, config.str);
            flag_eof = check_eof(fp);

            config.flag_n_helper++;
            if (patterns_finder_in_str(config.str, options, config.cflag)) {
                config.flag_v_helper = true;
            } else {
                config.flag_v_helper = false;
            }
            if (!((!config.flag_v_helper && !options.v) || (config.flag_v_helper && options.v))) {
                config.count_pattern_in_file++;
                output(config);
            }
            str_size = str_length(fp);
            free(config.str);
            config.str = (char *) calloc(str_size, sizeof(char));
            iter++;
        }
        config.default_helper = false;
        if (config.options.n) {
            config.second_flag_n_helper = false;
        }
        if (config.count_pattern_in_file > 0) {
            config.flag_l_helper = true;
        }
        config.flag_c_helper = true;
        output(config);
        config.flag_c_helper = false;
        counter_files++;
        free(config.str);
        fclose(fp);
    }
    return config;
}
bool check_eof(FILE *fp) {
    bool result;
    char ch;
    if (fscanf(fp, "%c", &ch) == EOF) {
        result = true;
    } else if (fscanf(fp, "%c", &ch) == EOF) {
        result = true;
    } else {
        result = false;
        fseek(fp, -1, SEEK_CUR);
    }
    return result;
}
dispatcher_config init_dispatcher_config(command_line_options options, int count_files) {
    dispatcher_config config;
    config.flag_c_helper = false;
    if (options.i) {
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
struct Node *parse_files(int argc, char **argv) {
    struct Node *files_storage_head = NULL;
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
    } else if (config.options.o) {
        flag_o_solver(config);
    } else { // формирование выходной строк
        if(config.default_helper) {
            if (config.second_flag_n_helper) {
                if (config.multi_files && (!config.options.h)) {
                    printf("%s:", config.filename);
                }
                if (config.options.n) {
                    printf("%i:", config.flag_n_helper);
                }
                printf("%s", config.str);
            }
        }
    }
}
int flag_o_solver(dispatcher_config config) {
    regex_t regex;
    regmatch_t reg_match[1];
    int match;
    int helper = 0;
    int so;
    int eo;
    int flag_match = 1;
    int patterns_count = get_size(config.options.pattern_storage);
    while (flag_match == 1) {
        flag_match = 0;
        for (int i = 0; i < patterns_count; i++) {
            if (i == 0) {
                so = 1000;
                eo = 1000;
            }
            regcomp(&regex, get_by_index(config.options.pattern_storage, i)->str, 0);
            match = regexec(&regex, config.str + helper, 1, reg_match, 0);
            if (reg_match[0].rm_so < so) {
                so = reg_match[0].rm_so;
                eo = reg_match[0].rm_eo;
            }
            if (match == 0) {
                flag_match = 1;
            }
        }
        reg_match[0].rm_so = so;
        reg_match[0].rm_eo = eo;
        if (flag_match == 1) {
            if(config.default_helper) {
                if (config.second_flag_n_helper) {
                    if (config.multi_files && (!config.options.h)) {
                        printf("%s:", config.filename);
                    }
                    if (config.options.n) {
                        printf("%i:", config.flag_n_helper);
                    }
                }
            }
            for (int i = reg_match[0].rm_so; i < reg_match[0].rm_eo; i++) {
                printf("%c", *(config.str + i + helper));
            }
            printf("\n");
            helper = helper + reg_match[0].rm_eo;
        }
    }
    regfree(&regex);
    return 0;
}
