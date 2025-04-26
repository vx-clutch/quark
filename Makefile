CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c99
SRCS=quark.c

all: build

build: quark.c quark.h
	$(CC) $(CFLAGS) -o test $(SRCS)

test: build
	./test && rm test
