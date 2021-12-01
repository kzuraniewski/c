CC = gcc
CFLAGS = -Wall -ansi
LDFLAGS = -lm

all: main.o mzero.o funkcja.o
	$(CC) $(CFLAGS) -o mzero main.o mzero.o funkcja.o $(LDFLAGS)

*.o: *.c
	$(CC) $(CFLAGS) -c *.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

mzero.o: mzero.c mzero.h
	$(CC) $(CFLAGS) -c mzero.c

funkcja.o: funkcja.c funkcja.h
	$(CC) $(CFLAGS) -c funkcja.c