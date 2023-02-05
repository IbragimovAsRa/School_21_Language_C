#include <check.h>
#include "test_cases_s21_math.h"


void test_func_s21(Suite *s);

int main(void) {

    Suite *array_test_cases[15];

    array_test_cases[0] = get_suite_s21_ceil();
    array_test_cases[1] = get_suite_s21_exp();
    array_test_cases[2] = get_suite_s21_log();
    array_test_cases[3] = get_suite_s21_pow();
    array_test_cases[4] = get_suite_s21_sqrt();
    array_test_cases[5] = get_suite_s21_atan();
    array_test_cases[6] = get_suite_s21_asin();
    array_test_cases[7] = get_suite_s21_acos();
    array_test_cases[8] = get_suite_s21_cos();
    array_test_cases[9] = get_suite_s21_sin();
    array_test_cases[10] = get_suite_s21_tan();
    array_test_cases[11] = get_suite_s21_abs();
    array_test_cases[12] = get_suite_s21_fabs();
    array_test_cases[13] = get_suite_s21_floor();
    array_test_cases[14] = get_suite_s21_fmod();



    for (int i = 0; i < 15; i ++ ){
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
