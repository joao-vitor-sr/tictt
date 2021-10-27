
include config.mk

CC = gcc

all: tictt

tictt: src/main.c
	${CC} -o tictt ./src/*.c
	chmod +x ./tictt

install: tictt
	mv ./tictt ${PREFIX}

uninstall:
	rm -rf ${PREFIX}/tictt
