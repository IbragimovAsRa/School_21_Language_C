#include <stdio.h>
#include <string.h>


int main() {
    char *s1 = "1231111111111111111056";
    char *s2 = "1231111111111111111367";
    int s;
    s = memcmp(s1, s2, strlen(s1));
    printf("%i", s);
    return 0;
}