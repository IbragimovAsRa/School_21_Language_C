#include <check.h>
#include <math.h>

#include "s21_math.h"
#include "test_cases_s21_math.h"


void test_func_s21(Suite *s);

int main(void) {

    Suite *array_test_cases[15];

    array_test_cases[0] = get_suite_s21_ceil();
    array_test_cases[1] = get_suite_s21_exp();
    array_test_cases[2] = get_suite_s21_log();
    array_test_cases[3] = get_suite_s21_pow();
    array_test_cases[4] = get_suite_s21_sqrt();
    array_test_cases[5] = get_suite_s21_asin();
    array_test_cases[6] = get_suite_s21_acos();


    for (int i = 0; i < 7; i ++ ){
        test_func_s21(array_test_cases[i]);
    }

    return 0;
}

void test_func_s21(Suite *s) {
    SRunner * runner = srunner_create(s);
    srunner_set_fork_status(runner, CK_NOFORK);
    srunner_run_all(runner, CK_NORMAL);
    srunner_free(runner);
}
