#include <stdio.h>
// 128
// 256
int main() {
    FILE *fp = fopen("files/file4_v.txt", "w");
    for (int i = 0; i < 128; i++ ) {
        fprintf(fp, "%c", i);
    }
    fclose(fp);
}