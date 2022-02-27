CC = gcc
CFLAGS = -Wall -o 
lib = -lncurses
main: main.c
	$(CC) main.c $(CFLAGS) $@ $(lib)
clean:
	rm -f main a.out
