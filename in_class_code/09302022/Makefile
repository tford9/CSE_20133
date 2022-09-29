# Author: Trenton W. Ford
# E-mail: tford5@nd.edu

# CC is for the gcc compiler for C
CC := gcc

# CFLAGS are the required compiler flags for the CSE 20133 course
CFLAGS := -Wall -Wextra -Wconversion -Werror -lm

evolve: evolve_testbed.o
	$(CC) $(CFLAGS) -o evolve_testbed evolve_testbed.o

evolve_optimized: evolve_testbed_optimized.o
	$(CC) $(CFLAGS) -o evolve_testbed_optimized evolve_testbed_optimized.o

clean:
	rm -rf a.out *.o evolve_testbed.o evolve_testbed_optimized.o
