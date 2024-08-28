GCC=gcc
CFLAGS=-std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
EXEC = a1

all: a1.c
	$(GCC) $(CFLAGS) -o $(EXEC) a1.c
	
clean:
	rm -f $(EXEC)
	rm -f *.o
