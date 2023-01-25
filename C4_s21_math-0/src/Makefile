CFLAGS = -Wall -Werror -Wextra
TST_LIBS = -lcheck -lm -lpthread -lrt -lsubunit

all: clean test

s21_math.o: s21_math.c
	gcc $(CFLAGS)  -c $(GCOVFL) s21_math.c

test.o: test.c
	gcc $(CFLAGS) -c $(GCOVFL) test.c

s21_math.a: s21_math.o
	ar -rcs	libs21_math.a s21_math.o

test: s21_math.a test.o
	gcc -o test  test.o $(TST_LIBS) -L. -ls21_math

coverage:
	gcov s21_math.c

gcovr-report: coverage ## Generate gcovr report
	gcovr --root . --html --html-details --output gcovr-report/coverage.html
run: clean test
	./test
gcov_report: test
clean:
	rm -rf *.o
	rm -rf main
	rm -rf a.out
	rm -rf *.a