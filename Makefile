CC = gcc
CFLAGS = -o
main: main.c
	$(CC) main.c $(CFLAGS)  main -lncurses
