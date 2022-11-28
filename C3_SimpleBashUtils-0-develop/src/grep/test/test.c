#include "stdio.h"
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include "string.h"
#include "regex.h"

#include <stdbool.h>
#include <stdio.h>

// тест-о флага
int main() {
    char *pattern = "test";
    char *str = "test lalala test d";
    regex_t regex;
    regcomp(&regex, pattern, 0);
    regmatch_t reg_match[10];
    regexec(&regex, str, 10, reg_match, 0);

    return 0;
}
