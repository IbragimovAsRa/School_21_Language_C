CC= gcc
CFLAGS = -g #-Wall -Werror -Wextra -std=c11
SOURSES_C= datastructs/*.c parse_input.c reverse_polish_notation.c calculations.c utils.c
SOURSES_O= linked_list.o stack_list.o parse_input.o reverse_polish_notation.o calculations.o utils.o stack_num.o
LIB=SmartCalc.a

main.o:	
	$(CC) $(CFLAGS) -c main.c

$(LIB):	$(SOURSES_C)
	$(CC)  -g -c $(SOURSES_C) 
	ar rcs $(LIB)  $(SOURSES_O) 
	ranlib $(LIB)`

main: main.o $(LIB)
	$(CC) -g main.o $(LIB) -o main -lm 

memcheck:	main
	valgrind --leak-check=full --track-origins=yes ./main

run: clean main
	./main

format:
	clang-format -i *.c *.h  datastructs/*.c datastructs/*.h

clean:
	rm -rf *.o
	rm -rf *.a main
	rm -rf $(LIB)
