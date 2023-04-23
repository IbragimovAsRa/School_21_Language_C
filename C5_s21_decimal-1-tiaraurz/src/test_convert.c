#include "test_convert.h"


void test_func_s21(Suite *s);

int main(void) {

    printf("START TEST convert\n");
    Suite *convert_test_cases[20];

    convert_test_cases[0] = get_suite_convert();
    test_func_s21(convert_test_cases[0]);

    return 0;
}

void test_func_s21(Suite *s) {
    SRunner *runner = srunner_create(s);
    srunner_set_fork_status(runner, CK_NOFORK);
    srunner_run_all(runner, CK_NORMAL);
    srunner_free(runner);
}
