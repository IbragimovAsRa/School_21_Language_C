


all: clean s21_grep
s21_grep.o:
	gcc -c   s21_grep.c
list.o:
	gcc -c  utils/list.c
s21_grep: list.o s21_grep.o
	gcc  -o s21_grep list.o s21_grep.o
clean:
	rm -rf *.o
	rm -rf *.out
run: clean s21_grep
	./s21_grep -e test files/file1.txt