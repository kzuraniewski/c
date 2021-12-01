CC = gcc
CFLAGS = -Wall -ansi
LDFLAGS = -lm

all: main.c print_bit.c
	$(CC) $(CFLAGS) -o bity main.c print_bit.c $(LDFLAGS)

*.c:
	$(CC) $(CFLAGS) -c *.c

main.c:
	$(CC) $(CFLAGS) -c main.c
