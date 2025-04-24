CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c99
SRCS=vlibc.c

all: build

build: vlibc.c vlibc.h
	$(CC) $(CFLAGS) -o test $(SRCS)

test: build
	./test && rm test