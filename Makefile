CC = gcc
CFLAGS = -Wall -o 
lib = -lncurses
main: main.c logic.c select.c file.c input.c status.c
	$(CC) main.c $(CFLAGS) $@ $(lib)
clean:
	rm -f main
