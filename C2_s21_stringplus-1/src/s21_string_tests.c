#include <check.h>

#include "s21_string_tests.h"

void test_func_s21(Suite *s);

int main(void) {

    printf("START TEST sscanf\n");
    Suite *s21_sscanf_test_cases[20];

    s21_sscanf_test_cases[0] = get_suite_s21_sscanf();
    s21_sscanf_test_cases[1] = get_suite_s21_sscanf_c();
    s21_sscanf_test_cases[2] = get_suite_s21_sscanf_d();
    s21_sscanf_test_cases[3] = get_suite_s21_sscanf_i();

    test_func_s21(s21_sscanf_test_cases[0]);
    test_func_s21(s21_sscanf_test_cases[1]);
    test_func_s21(s21_sscanf_test_cases[2]);
    test_func_s21(s21_sscanf_test_cases[3]);


    return 0;
}

void test_func_s21(Suite *s) {
    SRunner *runner = srunner_create(s);
    srunner_set_fork_status(runner, CK_NOFORK);
    srunner_run_all(runner, CK_NORMAL);
    srunner_free(runner);
}
