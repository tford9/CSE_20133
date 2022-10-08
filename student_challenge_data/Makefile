# Author: Trenton W. Ford
# E-mail: tford5@nd.edu
#
# This is the Makefile for Programming Challenge 02

# CC is for the gcc compiler for C
CC := gcc

# CFLAGS are the required compiler flags for the CSE 20133 course
CFLAGS :=


# Compilation for the problem1 program
# Command: make problem1
paycheck: paycheck.o
	$(CC) $(CFLAGS) -o paycheck paycheck.o

paycheck.o: paycheck.c
	$(CC) $(CFLAGS) -c paycheck.c

number_scanner: number_scanner.o
	$(CC) $(CFLAGS) -o number_scanner number_scanner.o

number_scanner.o: number_scanner.c
	$(CC) $(CFLAGS) -c number_scanner.c

prog_paycheck: prog_paycheck.o
	$(CC) $(CFLAGS) -o prog_paycheck prog_paycheck.o

prog_paycheck.o: prog_paycheck.c
	$(CC) $(CFLAGS) -c prog_paycheck.c

sphere_volume: sphere_volume.o
	$(CC) $(CFLAGS) -o sphere_volume sphere_volume.o

sphere_volume.o: sphere_volume.c
	$(CC) $(CFLAGS) -c sphere_volume.c

clean:
	rm -rf a.out *.o paycheck number_scanner
