#include <check.h>

#include "s21_string_tests.h"

void test_func_s21(Suite *s);

int main(void) {
    Suite *array_test_cases[20];

    array_test_cases[0] = get_suite_s21_memchr();
    array_test_cases[1] = get_suite_s21_memcmp();
    array_test_cases[2] = get_suite_s21_memmove();
    array_test_cases[4] = get_suite_s21_strpbrk();
    array_test_cases[5] = get_suite_s21_strspn();

    for (int i = 0; i < 5; i++) {
        test_func_s21(array_test_cases[i]);
    }

    printf("START TEST sscanf\n");
    Suite *scan_test_cases[20];

    scan_test_cases[0] = get_suite_s21_sscanf();
    test_func_s21(scan_test_cases[0]);

    return 0;
}

void test_func_s21(Suite *s) {
    SRunner *runner = srunner_create(s);
    srunner_set_fork_status(runner, CK_NOFORK);
    srunner_run_all(runner, CK_NORMAL);
    srunner_free(runner);
}
