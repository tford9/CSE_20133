# Author: Trenton W. Ford
# E-mail: tford5@nd.edu

# CC is for the gcc compiler for C
CC := gcc

# CFLAGS are the required compiler flags for the CSE 20133 course
CFLAGS := 
evolve: evolve_testbed.o
	$(CC) $(CFLAGS) -o evolve_testbed evolve_testbed.o

evolve_optimized: evolve_testbed_optimized.o
	$(CC) $(CFLAGS) -o evolve_testbed_optimized evolve_testbed_optimized.o

# multiple dependencies
conways: conways_game.c conways_game_utilities.c 
	$(CC) $(CFLAGS) -o ConwaysGame conways_game.c conways_game_utilities.c

clean:
	rm -rf a.out *.o evolve_testbed evolve_testbed_optimized ConwaysGame
