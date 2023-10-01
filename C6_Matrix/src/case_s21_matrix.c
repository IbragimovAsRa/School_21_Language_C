#include "s21_matrix_test.h"

// test s21_create_matrix
START_TEST(matrix_test_1) {
  matrix_t m;
  ck_assert_int_eq(1, s21_create_matrix(0, 1, &m));
}
END_TEST

// test s21_eq_matrix
START_TEST(matrix_test_2) {
  double a[] = {2, 5, 7, 6, 3, 4, 5, -2, -3};
  matrix_t m1;
  s21_matrix_init_helper(3, 3, a, &m1);
  matrix_t m2;
  s21_matrix_init_helper(3, 3, a, &m2);
  ck_assert_int_eq(1, s21_eq_matrix(&m1, &m2));
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
}
END_TEST

START_TEST(matrix_test_3) {
  double a1[] = {2, 5, 6, 6, 3, 4, 5, -2, -3};
  double a2[] = {2, 5, 1, 6, 3, 4, 5, -2, -3};
  matrix_t m1;
  s21_matrix_init_helper(3, 3, a1, &m1);
  matrix_t m2;
  s21_matrix_init_helper(3, 3, a2, &m2);
  ck_assert_int_eq(0, s21_eq_matrix(&m1, &m2));
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
}
END_TEST

// test s21_sum_matrix
START_TEST(matrix_test_4) {
  double a1[] = {2, 5, 6, 6, 3, 4, 5, -2, -3};
  double a2[] = {2, 0, 6, 0, 3, 0, 5, -2, -3};
  double a3[] = {4, 5, 12, 6, 6, 4, 10, -4, -6};
  matrix_t m1;
  s21_matrix_init_helper(3, 3, a1, &m1);
  matrix_t m2;
  s21_matrix_init_helper(3, 3, a2, &m2);
  matrix_t m3;
  s21_matrix_init_helper(3, 3, a3, &m3);
  matrix_t res;
  s21_sum_matrix(&m1, &m2, &res);
  int result = s21_eq_matrix(&m3, &res);
  ck_assert_int_eq(1, result);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&m3);
  s21_remove_matrix(&res);
}
END_TEST
// test s21_sub_matrix
START_TEST(matrix_test_5) {
  double a1[] = {4, 5, 12, 6, 6, 4, 10, -4, -6};
  double a2[] = {2, 5, 6, 6, 3, 4, 5, -2, -3};
  double a3[] = {2, 0, 6, 0, 3, 0, 5, -2, -3};
  matrix_t m1;
  s21_matrix_init_helper(3, 3, a1, &m1);
  matrix_t m2;
  s21_matrix_init_helper(3, 3, a2, &m2);
  matrix_t m3;
  s21_matrix_init_helper(3, 3, a3, &m3);
  matrix_t res;
  s21_sub_matrix(&m1, &m2, &res);
  int result = s21_eq_matrix(&m3, &res);
  ck_assert_int_eq(1, result);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&m3);
  s21_remove_matrix(&res);
}
END_TEST
// test s21_mult_number
START_TEST(matrix_test_6) {
  double a1[] = {4, 5, 12, 6, 6, 4, 10, -4, -6};
  double a2[] = {8, 10, 24, 12, 12, 8, 20, -8, -12};
  double number = 2;
  matrix_t m1;
  s21_matrix_init_helper(3, 3, a1, &m1);
  matrix_t m2;
  s21_matrix_init_helper(3, 3, a2, &m2);
  matrix_t res;
  s21_mult_number(&m1, number, &res);
  int result = s21_eq_matrix(&m2, &res);
  ck_assert_int_eq(1, result);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&res);
}
END_TEST

// test s21_mult_matrix
START_TEST(matrix_test_7) {
  double a1[] = {1, 4, 2, 7, 6, 4, 1, -4, -6};
  /*
      1  4  2
      7  6  4
      1 -4 -6
  */
  double a2[] = {2, 5, 6, 6, 3, 4, 5, -2, -3};
  /*
      2  5  6
      6  3  4
      5 -2 -3
  */
  double a3[] = {36, 13, 16, 70, 45, 54, -52, 5, 8};
  /*
      36 13 16
      70 45 54
     -52  5  8
  */

  matrix_t m1;
  s21_matrix_init_helper(3, 3, a1, &m1);
  matrix_t m2;
  s21_matrix_init_helper(3, 3, a2, &m2);
  matrix_t m3;
  s21_matrix_init_helper(3, 3, a3, &m3);
  matrix_t res;
  s21_mult_matrix(&m1, &m2, &res);
  int result = s21_eq_matrix(&m3, &res);
  ck_assert_int_eq(1, result);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&m3);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(matrix_test_8) {
  double a1[] = {1, 4, 2, 7, 6, 4};
  /*
      1 4 2
      7 6 4
  */
  double a2[] = {2, 5, 6, 6, 3, 4};
  /*
      2 5
      6 6
      3 4
  */
  double a3[] = {32, 37, 62, 87};
  /*
      32 37
      62 87
  */

  matrix_t m1;
  s21_matrix_init_helper(2, 3, a1, &m1);
  matrix_t m2;
  s21_matrix_init_helper(3, 2, a2, &m2);
  matrix_t m3;
  s21_matrix_init_helper(2, 2, a3, &m3);
  matrix_t res;
  s21_mult_matrix(&m1, &m2, &res);
  int result = s21_eq_matrix(&m3, &res);
  ck_assert_int_eq(1, result);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&m3);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(matrix_test_9) {
  double a1[] = {1, 4, 2, 7, 6, 4};
  /*
      1 4
      2 7
      6 4
  */
  double a2[] = {2, 5, 6, 6, 3, 4};
  /*
      2 5 6
      6 3 4
  */
  double a3[] = {26, 17, 22, 46, 31, 40, 36, 42, 52};
  /*
      26 17 22
      46 31 40
      36 42 52
  */

  matrix_t m1;
  s21_matrix_init_helper(3, 2, a1, &m1);
  matrix_t m2;
  s21_matrix_init_helper(2, 3, a2, &m2);
  matrix_t m3;
  s21_matrix_init_helper(3, 3, a3, &m3);
  matrix_t res;
  s21_mult_matrix(&m1, &m2, &res);
  int result = s21_eq_matrix(&m3, &res);
  ck_assert_int_eq(1, result);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&m3);
  s21_remove_matrix(&res);
}
END_TEST

// // test s21_transponce
START_TEST(matrix_test_10) {
  double a1[] = {1, 4, 2, 7, 6, 4};
  /*
      1 4
      2 7
      6 4
  */
  double a2[] = {1, 2, 6, 4, 7, 4};
  /*
      1 2 6
      4 7 4
  */
  matrix_t m1;
  s21_matrix_init_helper(3, 2, a1, &m1);
  matrix_t m2;
  s21_matrix_init_helper(2, 3, a2, &m2);
  matrix_t res;
  s21_transpose(&m1, &res);

  int result = 0;
  result = s21_eq_matrix(&m2, &res);
  ck_assert_int_eq(1, result);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(matrix_test_11) {
  double a1[] = {1, 4, 2, 7, 6, 4};
  /*
      1 4 2
      7 6 4
  */
  double a2[] = {1, 7, 4, 6, 2, 4};
  /*
      +------------+------------+
      |  1.000     |  7.000     |
      +------------+------------+
      |  4.000     |  6.000     |
      +------------+------------+
      |  2.000     |  4.000     |
      +------------+------------+
  */

  matrix_t m1;
  s21_matrix_init_helper(2, 3, a1, &m1);
  matrix_t m2;
  s21_matrix_init_helper(3, 2, a2, &m2);
  matrix_t res;
  s21_transpose(&m1, &res);
  int result = s21_eq_matrix(&m2, &res);
  ck_assert_int_eq(1, result);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(matrix_test_12) {
  double a1[] = {1, 4, 2, 7, 6, 4, 1, -4, -6};
  /*
      1  4  2
      7  6  4
      1 -4 -6
  */
  double a2[] = {1, 7, 1, 4, 6, -4, 2, 4, -6};
  /*
      1	7	1
      4	6	-4
      2	4	-6
  */
  matrix_t m1;
  s21_matrix_init_helper(3, 3, a1, &m1);
  matrix_t m2;
  s21_matrix_init_helper(3, 3, a2, &m2);
  matrix_t res;
  s21_transpose(&m1, &res);
  int result = s21_eq_matrix(&m2, &res);
  ck_assert_int_eq(1, result);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&res);
}
END_TEST

// test s21_calc_complements

START_TEST(matrix_test_13) {
  double a1[] = {1, 2, 3, 0, 4, 2, 5, 2, 1};
  /*
      +------------+------------+------------+
      |  1.000     |  2.000     |  3.000     |
      +------------+------------+------------+
      |  0.000     |  4.000     |  2.000     |
      +------------+------------+------------+
      |  5.000     |  2.000     |  1.000     |
      +------------+------------+------------+
  */
  double a2[] = {0, 10, -20, 4, -14, 8, -8, -2, 4};
  /*
      +------------+------------+------------+
      |  0.000     |  10.000    |  -20.000   |
      +------------+------------+------------+
      |  4.000     |  -14.000   |  8.000     |
      +------------+------------+------------+
      |  -8.000    |  -2.000    |  4.000     |
      +------------+------------+------------+
  */
  matrix_t m1;
  s21_matrix_init_helper(3, 3, a1, &m1);
  matrix_t m2;
  s21_matrix_init_helper(3, 3, a2, &m2);
  matrix_t res;
  s21_calc_complements(&m1, &res);
  int result = s21_eq_matrix(&m2, &res);
  ck_assert_int_eq(1, result);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&res);
}
END_TEST
// test s21_determinant
START_TEST(matrix_test_14) {
  double a1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  /*
      +------------+------------+------------+
      |  1.000     |  2.000     |  3.000     |
      +------------+------------+------------+
      |  4.000     |  5.000     |  6.000     |
      +------------+------------+------------+
      |  7.000     |  8.000     |  9.000     |
      +------------+------------+------------+
  */
  double a2 = 0;
  double res = 1;

  matrix_t m1;
  s21_matrix_init_helper(3, 3, a1, &m1);
  s21_determinant(&m1, &res);
  ck_assert_double_eq_tol(a2, res, 1e-7);
  s21_remove_matrix(&m1);
}
END_TEST

START_TEST(matrix_test_15) {
  double a1[] = {1, 2, 3, 0, 4, 2, 5, 2, 1};
  /*
      +------------+------------+------------+
      |  1.000     |  2.000     |  3.000     |
      +------------+------------+------------+
      |  0.000     |  4.000     |  2.000     |
      +------------+------------+------------+
      |  5.000     |  2.000     |  1.000     |
      +------------+------------+------------+
  */
  double a2 = -40;
  double res = -a2;

  matrix_t m1;
  s21_matrix_init_helper(3, 3, a1, &m1);
  s21_determinant(&m1, &res);
  ck_assert_double_eq_tol(a2, res, 1e-7);
  s21_remove_matrix(&m1);
}
END_TEST

// test s21_inverse_matrix
START_TEST(matrix_test_16) {
  double a1[] = {2, 5, 7, 6, 3, 4, 5, -2, -3};
  /*
      +------------+------------+------------+
      |  2.000     |  5.000     |  7.000     |
      +------------+------------+------------+
      |  6.000     |  3.000     |  4.000     |
      +------------+------------+------------+
      |  5.000     |  -2.000    |  -3.000    |
      +------------+------------+------------+
  */
  double a2[] = {1, -1, 1, -38, 41, -34, 27, -29, 24};
  /*
      +------------+------------+------------+
      |  -1.000    |  1.000     |  -1.000    |
      +------------+------------+------------+
      |  38.000    |  -41.000   |  34.000    |
      +------------+------------+------------+
      |  -27.000   |  29.000    |  -24.000   |
      +------------+------------+------------+
  */
  matrix_t m1;
  s21_matrix_init_helper(3, 3, a1, &m1);
  matrix_t m2;

  s21_matrix_init_helper(3, 3, a2, &m2);

  matrix_t res;
  s21_inverse_matrix(&m1, &res);
  int result = s21_eq_matrix(&m2, &res);
  ck_assert_int_eq(1, result);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&res);
}
END_TEST

Suite *get_suite_s21_matrix() {
  Suite *s = suite_create("s21_matrix suite");
  TCase *tc = tcase_create("s21_matrix case");
  suite_add_tcase(s, tc);

  tcase_add_test(tc, matrix_test_1);
  tcase_add_test(tc, matrix_test_2);
  tcase_add_test(tc, matrix_test_3);
  tcase_add_test(tc, matrix_test_4);
  tcase_add_test(tc, matrix_test_5);
  tcase_add_test(tc, matrix_test_6);
  tcase_add_test(tc, matrix_test_7);
  tcase_add_test(tc, matrix_test_8);
  tcase_add_test(tc, matrix_test_9);
  tcase_add_test(tc, matrix_test_10);
  tcase_add_test(tc, matrix_test_11);
  tcase_add_test(tc, matrix_test_12);
  tcase_add_test(tc, matrix_test_13);
  tcase_add_test(tc, matrix_test_14);
  tcase_add_test(tc, matrix_test_15);
  tcase_add_test(tc, matrix_test_16);

  return s;
}