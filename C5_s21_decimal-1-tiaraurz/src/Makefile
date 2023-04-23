CC= gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
SOURSES= s21_decimal.c test.c main.c arithmetic.c support.c compare.c
OBJECTS=$(SOURSES:.c=.o)
TEST_FLAGS=-lcheck $(shell pkg-config --cflags --libs check)
LIB=s21_decimal.a

ifeq ($(shell uname), Linux)
	TST_LIBS += -lpthread -lrt -lsubunit
endif

all: clean $(LIB)

$(LIB): arithmetic.o support.o compare.o convert.o
	ar rc $(LIB) arithmetic.o support.o compare.o convert.o
	ranlib $(LIB)

convert: $(LIB) main_convert.o
	$(CC) $(CFLAGS) main_convert.o $(LIB) -lm -o convert
	./convert


test: $(LIB) test.o
	$(CC) $(CFLAGS) test.o $(LIB) $(TEST_FLAGS) -o test
	./test

add_coverage_flag: 
	$(eval CFLAGS += --coverage)



run: test_convert
	./test_convert
memcheck: test_convert
	valgrind ./test_convert

test_convert: $(LIB) test_convert.o test_case_convert.o
	$(CC) $(CFLAGS) test_convert.o test_case_convert.o $(LIB) $(TEST_FLAGS) -o test_convert
	./test_convert

test_convert.o:
	$(CC) -c $(CFLAGS) test_convert.c -o test_convert.o 
test_case_convert.o:
	$(CC) -c $(CFLAGS) test_case_convert.c -o test_case_convert.o
.c.o:
	$(CC) -c $(CFLAGS) $< -o $@ 




clean:
	rm -rf *.o test *.a *.gcno *.gcda *.gcov  test_convert
	*.html *.css *.info report main/*.o s21_math debug convert


#--------------------------------------------------------------------------
#                                  convert

#--------------------------------------------------------------------------
