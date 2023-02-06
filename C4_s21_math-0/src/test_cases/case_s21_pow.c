#include "../s21_math_tests.h"

START_TEST(pow_test_1) {
  ck_assert_ldouble_eq(s21_pow(max_inf, max_inf), pow(max_inf, max_inf));
}
END_TEST

START_TEST(pow_test_2) {
  ck_assert_ldouble_eq_tol(s21_pow(max_inf, min_inf), pow(max_inf, min_inf),
                           1e-8);
}
END_TEST
START_TEST(pow_test_3) { ck_assert_ldouble_nan(s21_pow(max_inf, max_nan)); }
END_TEST
START_TEST(pow_test_4) { ck_assert_ldouble_nan(s21_pow(max_inf, min_nan)); }
END_TEST
START_TEST(pow_test_5) {
  ck_assert_ldouble_eq(s21_pow(min_inf, max_inf), pow(min_inf, max_inf));
}
END_TEST
START_TEST(pow_test_6) {
  ck_assert_ldouble_eq_tol(s21_pow(min_inf, min_inf), pow(min_inf, min_inf),
                           1e-8);
}
END_TEST
START_TEST(pow_test_7) { ck_assert_ldouble_nan(s21_pow(min_inf, max_nan)); }
END_TEST
START_TEST(pow_test_8) { ck_assert_ldouble_nan(s21_pow(min_inf, min_nan)); }
END_TEST
START_TEST(pow_test_9) { ck_assert_ldouble_nan(s21_pow(max_nan, max_inf)); }
END_TEST
START_TEST(pow_test_10) { ck_assert_ldouble_nan(s21_pow(max_nan, min_inf)); }
END_TEST
START_TEST(pow_test_11) { ck_assert_ldouble_nan(s21_pow(max_nan, max_nan)); }
END_TEST
START_TEST(pow_test_12) { ck_assert_ldouble_nan(s21_pow(max_nan, min_nan)); }
END_TEST
START_TEST(pow_test_13) { ck_assert_ldouble_nan(s21_pow(min_nan, max_inf)); }
END_TEST
START_TEST(pow_test_14) { ck_assert_ldouble_nan(s21_pow(min_nan, min_inf)); }
END_TEST
START_TEST(pow_test_15) { ck_assert_ldouble_nan(s21_pow(min_nan, max_nan)); }
END_TEST
START_TEST(pow_test_16) { ck_assert_ldouble_nan(s21_pow(min_nan, min_nan)); }
END_TEST
START_TEST(pow_test_17) { ck_assert_ldouble_infinite(s21_pow(max_inf, 2.4)); }
END_TEST
START_TEST(pow_test_18) { ck_assert_ldouble_infinite(s21_pow(min_inf, 2.4)); }
END_TEST
START_TEST(pow_test_19) { ck_assert_ldouble_nan(s21_pow(max_nan, 2.4)); }
END_TEST
START_TEST(pow_test_20) { ck_assert_ldouble_nan(s21_pow(min_nan, 2.4)); }
END_TEST
START_TEST(pow_test_21) { ck_assert_ldouble_infinite(s21_pow(2.4, max_inf)); }
END_TEST

START_TEST(pow_test_22) {
  ck_assert_ldouble_eq_tol(s21_pow(2.4, min_inf), pow(2.4, min_inf), accuracy);
}
END_TEST

START_TEST(pow_test_23) { ck_assert_ldouble_nan(s21_pow(2.4, max_nan)); }
END_TEST
START_TEST(pow_test_24) { ck_assert_ldouble_nan(s21_pow(2.4, min_nan)); }
END_TEST
START_TEST(pow_test_25) {
  ck_assert_ldouble_eq_tol(s21_pow(0, 2.4), pow(0, 2.4), accuracy);
}
END_TEST
START_TEST(pow_test_26) {
  ck_assert_ldouble_eq_tol(s21_pow(-0, 2.4), pow(-0, 2.4), accuracy);
}
END_TEST
START_TEST(pow_test_27) {
  ck_assert_ldouble_eq_tol(s21_pow(2.4, 0), pow(2.4, 0), accuracy);
}
END_TEST
START_TEST(pow_test_28) {
  ck_assert_ldouble_eq_tol(s21_pow(2.4, -0), pow(2.4, -0), accuracy);
}
END_TEST
START_TEST(pow_test_29) {
  ck_assert_ldouble_eq_tol(s21_pow(2.4, 0.5), pow(2.4, 0.5), accuracy);
}
END_TEST
START_TEST(pow_test_30) {
  ck_assert_ldouble_eq_tol(s21_pow(2.4, -0.5), pow(2.4, -0.5), accuracy);
}
END_TEST
START_TEST(pow_test_31) { ck_assert_ldouble_nan(s21_pow(-2.4, 0.5)); }
END_TEST
START_TEST(pow_test_32) { ck_assert_ldouble_nan(s21_pow(-2.4, -0.5)); }
END_TEST
START_TEST(pow_test_33) { ck_assert_ldouble_nan(s21_pow(-2.4, 2.1)); }
END_TEST
START_TEST(pow_test_34) { ck_assert_ldouble_nan(s21_pow(-2.4, -2.1)); }
END_TEST
START_TEST(pow_test_35) {
  ck_assert_ldouble_eq_tol(s21_pow(-2.4, 2), pow(-2.4, 2), accuracy);
}
END_TEST
START_TEST(pow_test_36) {
  ck_assert_ldouble_eq_tol(s21_pow(2.4, 2), pow(2.4, 2), accuracy);
}
END_TEST
START_TEST(pow_test_37) {
  ck_assert_ldouble_eq_tol(s21_pow(-2.4, -1), pow(-2.4, -1), accuracy);
}
END_TEST
START_TEST(pow_test_38) { ck_assert_ldouble_nan(s21_pow(-2.4, -1.2)); }
END_TEST
START_TEST(pow_test_39) { ck_assert_ldouble_nan(s21_pow(-2.4, -0.4)); }
END_TEST
START_TEST(pow_test_40) {
  ck_assert_ldouble_eq_tol(s21_pow(2.4, 1), pow(2.4, 1), 1e-8);
}
END_TEST
START_TEST(pow_test_41) {
  ck_assert_ldouble_eq_tol(s21_pow(2.4, 3), pow(2.4, 3), 1e-8);
}
END_TEST

START_TEST(pow_test_42) {
  ck_assert_ldouble_eq_tol(s21_pow(2.4, -3), pow(2.4, -3), 1e-8);
}
END_TEST
START_TEST(pow_test_43) {
  ck_assert_ldouble_eq_tol(s21_pow(66666.4, 1.5), pow(66666.4, 1.5), accuracy);
}
END_TEST
START_TEST(pow_test_44) {
  ck_assert_ldouble_eq_tol(s21_pow(66666.4, -1.5), pow(66666.4, -1.5),
                           accuracy);
}
END_TEST
START_TEST(pow_test_45) {
  ck_assert_ldouble_eq_tol(s21_pow(3.3, 13.2), pow(3.3, 13.2), accuracy);
}
END_TEST

Suite *get_suite_s21_pow() {
  Suite *s = suite_create("s21_pow suite ");
  TCase *tc = tcase_create("s21_pow test case");
  suite_add_tcase(s, tc);

  tcase_add_test(tc, pow_test_1);
  tcase_add_test(tc, pow_test_2);
  tcase_add_test(tc, pow_test_3);
  tcase_add_test(tc, pow_test_4);
  tcase_add_test(tc, pow_test_5);
  tcase_add_test(tc, pow_test_6);
  tcase_add_test(tc, pow_test_7);
  tcase_add_test(tc, pow_test_8);
  tcase_add_test(tc, pow_test_9);

  tcase_add_test(tc, pow_test_10);
  tcase_add_test(tc, pow_test_11);
  tcase_add_test(tc, pow_test_12);
  tcase_add_test(tc, pow_test_13);
  tcase_add_test(tc, pow_test_14);
  tcase_add_test(tc, pow_test_15);
  tcase_add_test(tc, pow_test_16);
  tcase_add_test(tc, pow_test_17);
  tcase_add_test(tc, pow_test_18);
  tcase_add_test(tc, pow_test_19);

  tcase_add_test(tc, pow_test_20);
  tcase_add_test(tc, pow_test_21);
  tcase_add_test(tc, pow_test_22);
  tcase_add_test(tc, pow_test_23);
  tcase_add_test(tc, pow_test_24);
  tcase_add_test(tc, pow_test_25);
  tcase_add_test(tc, pow_test_26);
  tcase_add_test(tc, pow_test_27);
  tcase_add_test(tc, pow_test_28);
  tcase_add_test(tc, pow_test_29);

  tcase_add_test(tc, pow_test_30);
  tcase_add_test(tc, pow_test_31);
  tcase_add_test(tc, pow_test_32);
  tcase_add_test(tc, pow_test_33);
  tcase_add_test(tc, pow_test_34);
  tcase_add_test(tc, pow_test_35);
  tcase_add_test(tc, pow_test_36);
  tcase_add_test(tc, pow_test_37);
  tcase_add_test(tc, pow_test_38);
  tcase_add_test(tc, pow_test_39);

  tcase_add_test(tc, pow_test_40);
  tcase_add_test(tc, pow_test_41);
  tcase_add_test(tc, pow_test_42);
  tcase_add_test(tc, pow_test_43);
  tcase_add_test(tc, pow_test_44);
  tcase_add_test(tc, pow_test_45);

  return s;
}
