CC= gcc
CFLAGS = -g -Wall -Werror -Wextra -std=c11
SOURSES_C= stack_char.c transform_dkstr.c
SOURSES_O= stack_char.o transform_dkstr.o
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
clean:
	rm -rf *.o
	rm -rf *.a main
	rm -rf $(LIB)
