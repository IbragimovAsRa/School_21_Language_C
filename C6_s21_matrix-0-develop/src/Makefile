STD_FLAGS=-Wall -Wextra -Werror -std=c11
CC=gcc
LIB=s21_matrix.a

$(LIB):	s21_matrix.c
	$(CC) $(STD_FLAGS) -c s21_matrix.c
	ar rcs s21_matrix.a s21_matrix.o

run: main
	./main
main.o:	main.c
	$(CC) $(STD_FLAGS) -c main.c 
main: main.o $(LIB)
	$(CC) $(STD_FLAGS) main.o $(LIB) -o main
format:	
	clang-format -i *.c *.h
clean:	
	rm - rf *.o s21_matrix.a *.o

memcheck:	main
	valgrind --leak-check=full ./main



