

cmake_minimum_required(VERSION 3.17)
project(C3_SimpleBashUtils-0)

set(SOURCE_FILES src/grep/s21_grep.c src/grep/utils/list.c)
add_executable(main ${SOURCE_FILES})