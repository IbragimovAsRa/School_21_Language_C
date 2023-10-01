TARGET=tests.out

CC=gcc
STD_FLAGS=-Wall -Wextra -Werror -std=c11
COV_FLAGS=--coverage
TEST_FLAGS_MACOS=-lcheck -lpthread -lm
TEST_FLAGS_LINUX=-lcheck -lrt -lpthread -lsubunit -lm
CHECK_FLAGS_LIB=-L"$(shell brew --prefix check)/lib"
CHECK_FLAGS_INC=-I"$(shell brew --prefix check)/include"
SOURCES_0 = s21_*.o
SOURCES_1 = math_func/s21_*.c
SOURCES_2 = s21_math_tests.c
SOURCES_3 = s21_math.a
SOURCES_4 = test_cases/*.c


all: clean s21_math.a test run gcov_report

test: s21_math_with_coverage s21_math_tests.o test_case
	$(CC) -o $(TARGET) $(STD_FLAGS) $(CHECK_FLAGS_LIB) *.o  -L. $(SOURCES_3) $(COV_FLAGS) $(TEST_FLAGS_MACOS)

s21_math_tests.o:
	gcc $(STD_FLAGS) $(CHECK_FLAGS_INC) -c $(SOURCES_2)

test_case:
	gcc $(STD_FLAGS) $(CHECK_FLAGS_INC) -c $(SOURCES_4)

s21_math.a:
	$(CC) $(STD_FLAGS) -c $(SOURCES_1)
	ar rcs $(SOURCES_3) $(SOURCES_0)

s21_math_with_coverage:
	$(CC) $(STD_FLAGS) -c $(SOURCES_1) $(COV_FLAGS)
	ar rcs $(SOURCES_3) $(SOURCES_0)

gcov_report:
	gcovr -r . --html --html-details -o coverage_report.html

run: test
	./tests.out


linux: clean s21_math_with_coverage test_linux run_linux gcov_report

test_linux: s21_math.a s21_math_tests_linux.o test_case_linux
	$(CC) -o $(TARGET) $(STD_FLAGS)  *.o  -L. $(SOURCES_3) $(COV_FLAGS) $(TEST_FLAGS_LINUX)

s21_math_tests_linux.o:
	gcc $(STD_FLAGS) -c $(SOURCES_2)

test_case_linux:
	gcc $(STD_FLAGS) -c $(SOURCES_4)

run_linux: test_linux
	./tests.out


style_check:
	clang-format -style=google -n *.c *.h test_cases/*.c math_func/*.c

style_correct:
	clang-format -style=google -i *.c *.h test_cases/*.c math_func/*.c

clean:
	rm -rf *.html *.gcno *.gcda *.o *.out *.css *coverage* *.a *.gch s21_math


