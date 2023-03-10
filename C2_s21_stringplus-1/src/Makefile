
STD_FLAGS = -Wall -Wextra -Werror -std=c11
COMPILER = gcc
COV_FLAGS = --coverage

TEST_FLAGS_LINUX = -lcheck -lrt -lpthread -lsubunit -lm
TEST_FLAGS_MACOS = -lcheck -lpthread -lm


SOURCES_0 = s21_*.o
SOURCES_1 = s21_string_funcs/s21_*.c
SOURCES_2 = s21_string_tests.c
SOURCES_3 = s21_string.a

all: clean s21_string.a test run gcov_report

s21_string_tests.o: s21_string_tests.c
	$(COMPILER) -g $(STD_FLAGS) -c  s21_string_tests.c

test_case: test_cases/*.c
	$(COMPILER) -g $(STD_FLAGS) -c  test_cases/*.c

s21_string.a:
	$(COMPILER)  -g -c $(SOURCES_1)
	ar rcs $(SOURCES_3) $(SOURCES_0)

test: s21_string_with_coverage s21_string_tests.o test_case
	$(COMPILER) -o test.out $(STD_FLAGS)  *.o   -L. $(SOURCES_3) $(COV_FLAGS) $(TEST_FLAGS_LINUX)

s21_string_with_coverage:
	$(COMPILER) $(STD_FLAGS) -c $(SOURCES_1) $(COV_FLAGS)
	ar rcs $(SOURCES_3) $(SOURCES_0)

test_macos: s21_string_with_coverage s21_string_tests.o test_case
	$(COMPILER) -o test.out $(STD_FLAGS)  *.o   -L. $(SOURCES_3) $(COV_FLAGS) $(TEST_FLAGS_MACOS)
run_macos: test_macos
	./test.out
	gcovr -r . --html --html-details -o coverage_report.html

gcov_report:
	gcovr -r . --html --html-details -o coverage_report.html

clean:
	rm -rf *.o
	rm -rf *.a
	rm -rf debug
	rm -rf *.html *.gcno *.gcda *.o *.out *.css *coverage* *.a


style_check: style_correct
	clang-format -style=google -n *.c *.h test_cases/*.c

style_correct:
	clang-format -style=google -i *.c *.h test_cases/*.c

run: test
	./test.out

test_main_debug: s21_string.a
	gcc -g $(STD_FLAGS) maintest.c -L. $(SOURCES_3) -o debug


test_debug: s21_string_with_coverage s21_string_tests.o test_case
	$(COMPILER) -o test.out -g $(STD_FLAGS)  *.o   -L. $(SOURCES_3) $(COV_FLAGS) $(TEST_FLAGS_LINUX)



