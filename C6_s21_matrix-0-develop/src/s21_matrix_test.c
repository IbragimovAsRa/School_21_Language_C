#include "s21_matrix_test.h"

void test_func_s21(Suite *s);

int main(void) {
  Suite *test_case;
  test_case = get_suite_s21_matrix();
  test_func_s21(test_case);
  return 0;
}

void test_func_s21(Suite *s) {
  SRunner *runner = srunner_create(s);
  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  srunner_free(runner);
}