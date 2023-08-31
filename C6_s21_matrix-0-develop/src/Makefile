STD_FLAGS=-Wall -Wextra -Werror -std=c11
CC=gcc
LIB=s21_matrix.a
TEST_FLAGS=-lcheck -lrt -lpthread -lsubunit -lm
COV_FLAGS=--coverage

all: clean $(LIB) test run gcov_report

$(LIB):	s21_matrix.c
	$(CC) $(STD_FLAGS) -c s21_matrix.c
	ar rcs s21_matrix.a s21_matrix.o

s21_matrix_with_coverage:
	$(CC) $(STD_FLAGS) -c s21_matrix.c $(COV_FLAGS)
	ar rcs s21_matrix.a s21_matrix.o

test: s21_matrix_with_coverage s21_matrix_test.o case_s21_matrix.o 
	 $(CC) -o test $(STD_FLAGS) s21_matrix_test.o case_s21_matrix.o -L. s21_matrix.a  $(COV_FLAGS) $(TEST_FLAGS)

test_without_coverage: $(LIB) s21_matrix_test.o case_s21_matrix.o
	$(CC) -o test_without_coverage $(STD_FLAGS) s21_matrix_test.o case_s21_matrix.o  s21_matrix.a $(TEST_FLAGS)

run_without_coverage: test_without_coverage
	./test_without_coverage

run: test
	./test
gcov_report:
	gcovr -r . --html --html-details -o coverage_report.html

s21_matrix_test.o:
	$(CC) $(STD_FLAGS)  -c s21_matrix_test.c
case_s21_matrix.o:
	$(CC) $(STD_FLAGS)  -c case_s21_matrix.c
format:	
	clang-format -i *.c *.h
clean:	
	rm -rf *.o s21_matrix.a *.o main test  *.html *.css *.gcda *.gcno test_without_coverage
memcheck: clean test
	valgrind --tool=memcheck --track-origins=yes --leak-check=full ./test > /dev/null

