

all: clean main

main: s21_math.o main.o
	gcc -o main main.o s21_math.o
s21_math.o: s21_math.c
	gcc -c s21_math.c
main.o: main.c
	gcc -c main.c
clean:
	rm -rf *.o
	rm -rf main







