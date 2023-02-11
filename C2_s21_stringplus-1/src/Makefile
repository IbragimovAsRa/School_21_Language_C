
STD_FLAGS = -Wall -Wextra -Werror -std=c11
COMPILER = gcc
COV_FLAGS = --coverage -lgcov
TEST_FLAGS = -lcheck -lrt -lpthread -lsubunit -lm

SOURCES_0 = s21_*.o
SOURCES_1 = s21_string_funcs/s21_*.c
SOURCES_2 = s21_string_tests.c
SOURCES_3 = s21_string.a

all: clean s21_string.a test run gcov_report

s21_math_tests.o: s21_string_tests.c
	$(COMPILER) $(STD_FLAGS) -c  s21_string_tests.c

test_case:
	$(COMPILER) $(STD_FLAGS) -c test_cases/*.c

s21_string.a:
	$(COMPILER) $(STD_FLAGS) -c $(SOURCES_1)
	ar rcs $(SOURCES_3) $(SOURCES_0)

test: s21_math_with_coverage s21_math_tests.o test_case
	$(CC) -o test.out $(STD_FLAGS)  *.o   -L. -l:$(SOURCES_3) $(COV_FLAGS) $(TEST_FLAGS)

s21_math_with_coverage:
	$(COMPILER) $(STD_FLAGS) -c $(SOURCES_1) $(COV_FLAGS)
	ar rcs $(SOURCES_3) $(SOURCES_0)


clean:
	rm -rf *.o
	rm -rf *.a
	rm -rf *.html *.gcno *.gcda *.o *.out *.css *coverage* *.a


style_check: style_correct
	clang-format -style=google -n *.c *.h test_cases/*.c

style_correct:
	clang-format -style=google -i *.c *.h test_cases/*.c

run: test
	./test.out

test_main:
	gcc maintest.c
	./a.out

s21_string.a:

