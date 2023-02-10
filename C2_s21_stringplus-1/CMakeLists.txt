cmake_minimum_required(VERSION 3.24)
project(C2_s21_stringplus_1 C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(C2_s21_stringplus_1
        code-samples/s21_strlen.c
        src/s21_string_funcs/s21_memchr.c
        src/s21_string.h)
