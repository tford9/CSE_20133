# Author: Trenton W. Ford
# E-mail: tford5@nd.edu
#

# CC is for the gcc compiler for C
CC := gcc

# CFLAGS are the required compiler flags for the CSE 20133 course
CFLAGS := -Wall -Wextra -Wconversion -Werror -lm


malloc_example: malloc_example.o
	$(CC) -o malloc_example malloc_example.o

malloc_example.o: malloc_example.c
	$(CC) -c malloc_example.c

type_casting: type_casting.o
	$(CC) $(CFLAGS) -o type_casting type_casting.o

type_casting.o: type_casting.c
	$(CC) $(CFLAGS) -c type_casting.c

clean:
	rm -rf a.out *.o malloc_example type_casting
