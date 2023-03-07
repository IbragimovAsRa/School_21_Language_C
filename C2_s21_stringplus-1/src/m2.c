#include <stdio.h>

#include <string.h>


int main() {

    s21_sscanf(test_str, pattern, &n1);
    sscanf(test_str, pattern, &n2);
    ck_assert_float_eq(n1, n2);

    test_str = "hello 12.1223 12.11";
    pattern = "hello %*f %f";
    printf("result = %i", a);


    return 0;
}
