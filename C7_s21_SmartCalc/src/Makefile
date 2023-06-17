CC= gcc
CFLAGS = -g -Wall -Werror -Wextra -std=c11
DATASTRUCTS_C = datastructs/*.c
SOURSES_C= datastructs/*.c parse_input.c
SOURSES_O= linked_list.o stack_list.o parse_input.o 
LIB=SmartCalc.a

main.o:	
	$(CC) $(CFLAGS) -c main.c

$(LIB):	$(SOURSES_C)
	$(CC) $(CFLAGS) -c $(SOURSES_C)
	ar rcs $(LIB)  $(SOURSES_O)
	ranlib $(LIB)

main: main.o $(LIB)
	$(CC) $(CFLAGS) main.o $(LIB) -o main
memcheck:	main
	valgrind --leak-check=full ./main
run: main
	./main
format:
	clang-format -i *.c *.h
clean:
	rm -rf *.o
	rm -rf *.a main
	rm -rf $(LIB)
