


all: clean s21_grep
s21_grep.o:
	gcc -c  -O0 -g  s21_grep.c
list.o:
	gcc -c  -O0 -g utils/list.c
s21_grep: list.o s21_grep.o
	gcc -o  s21_grep  list.o s21_grep.o
clean:
	rm -rf s21_grep
	rm -rf *.o
	rm -rf *.out
	rm -rf a.txt
	rm -rf b.txt
	rm -rf log_file.txt
