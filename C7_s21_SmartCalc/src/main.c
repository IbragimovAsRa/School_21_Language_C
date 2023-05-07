#include "transform_dkstr.h"

int main() {
    char *infixStr = "2/(3+2)*5";
    char postfixStr[STRMAX];
    transformDkstr(infixStr,postfixStr);
    printf("%s\n", postfixStr);

    return 0;
}