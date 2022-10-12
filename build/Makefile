# Author: Trenton W. Ford
# E-mail: tford5@nd.edu
#
# This is the Makefile for Programming Challenge 02

# CC is for the gcc compiler for C
CC := gcc

# CFLAGS are the required compiler flags for the CSE 20133 course
CFLAGS :=

problem1: problem1.o
	$(CC) $(CFLAGS) -o problem1 problem1.o

problem1.o:
	$(CC) $(CFLAGS) -c problem1.c

problem2: problem2.o
	$(CC) $(CFLAGS) -o problem2 problem2.o

problem2.o:
	$(CC) $(CFLAGS) -c problem2.c

problem3: problem3.o
	$(CC) $(CFLAGS) -o problem3 problem3.o

problem3.o:
	$(CC) $(CFLAGS) -c problem3.c

all: problem1 problem2 problem3

clean:
	rm -rf a.out *.o problem1 problem2 problem3
