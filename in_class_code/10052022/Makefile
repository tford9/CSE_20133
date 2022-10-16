# Author: Trenton W. Ford
# E-mail: tford5@nd.edu
#

# CC is for the gcc compiler for C
CC := gcc

# CFLAGS are the required compiler flags for the CSE 20133 course
CFLAGS := -Wall -Wconversion -Werror -Wextra 


malloc_example: malloc_example.o 
	$(CC) $(CFLAGS) -o malloc_example.exe malloc_example.o

malloc_example.o: 
	$(CC) $(CFLAGS) -c malloc_example.c

type_casting: type_casting.o
	$(CC) $(CFLAGS) -o type_casting.exe type_casting.o

type_casting.o: 
	$(CC) $(CFLAGS) -c type_casting.c

all: malloc_example type_casting
	
clean:
	rm -rf a.out *.o *.exe
