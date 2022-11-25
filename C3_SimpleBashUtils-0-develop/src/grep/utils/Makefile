
all: clean list_test

list.o:
	gcc -c list.c
test_list.o:
	gcc -c test_list.c
list_test: list.o test_list.o
	gcc list.o test_list.o
clean:
	rm -rf *.o
	rm -rf *.out
test_memory: clean list_test
	leaks -atExit -- ./a.out 1 2 3 4 5
