#include "test_general.h"

Suite* get_suite_general() {
    Suite *s = suite_create("convert_test suite ");
    TCase *tc = tcase_create("convert_test test case");
    suite_add_tcase(s, tc);

    // tcase_add_test(tc, convert_test_1);
    // tcase_add_test(tc, convert_test_2);
    return s;
}
