cmake_minimum_required(VERSION 3.24)
project(C2_s21_stringplus_1 C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(C2_s21_stringplus_1
        code-samples/s21_strlen.c
        src/s21_string_funcs/s21_memchr.c
        src/s21_string.h src/test_cases/case_s21_memcmp.c src/s21_string_tests.c src/test_cases/case_s21_memchr.c src/s21_string_funcs/s21_memmove.c src/test_cases/case_s21_memmove.c src/s21_string_funcs/s21_strcat.c src/test_cases/case_s21_strcat.c src/s21_string_funcs/s21_strchr.c src/s21_string_funcs/s21_sscanf.c src/s21_string_funcs/utils/s21_find_count_pattern.c src/test_cases/case_s21_sscanf.c src/test_cases/case_s21_strpbrk.c src/test_cases/case_s21_strspn.c src/s21_string_funcs/s21_sscanf.c src/s21_string_funcs/s21_strlen.c)
