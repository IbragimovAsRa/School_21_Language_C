#include "check.h"
#include "s21_math.h"



START_TEST(abs_first) {
    int r1 = s21_abs(-1);
    ck_assert_int_eq(r1, 1);
}
END_TEST

START_TEST(abs_second) {
    ck_assert_int_eq(1, 1);
}
END_TEST

START_TEST(abs_third) {
    ck_assert_int_eq(0, 0);
}
END_TEST

Suite *abs_suite() {
    Suite *s;
    TCase *tc_first, *tc_second, *tc_third;

    s = suite_create("Test_math_abs");

    tc_first = tcase_create("First");
    tcase_add_test(tc_first, abs_first);
    suite_add_tcase(s, tc_first);

    tc_second = tcase_create("Second");
    tcase_add_test(tc_second, abs_second);
    suite_add_tcase(s, tc_second);

    tc_third = tcase_create("Third");
    tcase_add_test(tc_third, abs_third);
    suite_add_tcase(s, tc_third);

    return s;
}

int main(void) {
    int failed = 0;
    Suite *s;
    SRunner *runner;

    s = abs_suite();
    runner = srunner_create(s);

    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (failed == 0) ? 1 : 0;
}