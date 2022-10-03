# Author: Trenton W. Ford
# E-mail: tford5@nd.edu
#
# This is the Makefile for Programming Challenge 01

# CC is for the gcc compiler for C
CC := gcc

# CFLAGS are the required compiler flags for the CSE 20133 course
CFLAGS := -Wall -Wextra -Wconversion -Werror -lm


malloc_example: malloc_example.o
	$(CC) $(CFLAGS) -o malloc_example malloc_example.o

malloc_example.o: malloc_example.c
	$(CC) $(CFLAGS) -c malloc_example.c

clean:
	rm -rf a.out *.o malloc_example
