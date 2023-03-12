#ifndef SRC_S21_STRING_TESTS_H_
#define SRC_S21_STRING_TESTS_H_

#include <check.h>
#include <string.h>
#include <stdio.h>

#include "s21_string_funcs/headers/s21_string.h"

Suite *get_suite_s21_memchr();
Suite *get_suite_s21_memcmp();
Suite *get_suite_s21_memmove();
Suite *get_suite_s21_strpbrk();
Suite *get_suite_s21_strspn();


Suite *get_suite_s21_sscanf();
Suite *get_suite_s21_sscanf_c();
Suite *get_suite_s21_sscanf_d();


#endif  // SRC_S21_STRING_TESTS_H_
