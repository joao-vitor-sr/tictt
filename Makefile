CC = gcc

all: tictt

tictt: src/main.c
	$(CC) -o tictt ./src/*.c

simple: src/main.c
	$(CC) ./src/*.c
