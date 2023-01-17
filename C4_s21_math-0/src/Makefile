CFLAGS = -Wall -Werror -Wextra


all: clean test

s21_math.o: s21_math.c
	gcc $(CFLAGS) -c s21_math.c

test.o: test.c
	gcc $(CFLAGS) -c test.c

s21_math.a: s21_math.o
	ar -rcs	libs21_math.a s21_math.o

test: s21_math.a test.o
	gcc -o test  test.o -lcheck -lm -lpthread -lrt -lsubunit -L. -ls21_math
clean:
	rm -rf *.o
	rm -rf main
	rm -rf a.out
	rm -rf *.a
