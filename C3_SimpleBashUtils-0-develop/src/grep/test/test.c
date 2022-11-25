#include "stdio.h"
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include "string.h"

#include <stdbool.h>
#include <stdio.h>

int str_read(FILE *fp, int length, char *output_str);
int str_length(FILE *fp);
bool check_eof(FILE *fp); // вызывать когда на границе строки

int main() {
    char *str;
    FILE * fp = fopen("f.txt", "r");
    bool flag_eof = false;
    int str_size = str_length(fp);
    str = (char *) malloc(str_size * sizeof(char));
    while(!flag_eof) {
        str_read(fp, str_length(fp), str);
        printf("%s", str);
        flag_eof = check_eof(fp);
        str_size = str_length(fp);
        free(str);
        str = (char *) malloc(str_size * sizeof(char));
    }
    fclose(fp);
    return 0;
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
int str_read(FILE *fp, int length, char *output_str) {

    for (int i = 0; i < length - 1; i++) {
        fscanf(fp, "%c", output_str + i);
    }
    *(output_str + (length-1)) = '\n';
    return 0;
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