CC=gcc
CFLAGS=-Wall -Wextra -std=c11 -shared -fPIC
SRCS=$(wildcard libq/*.c)
LIB=libq.so

$(LIB): $(SRCS) quarks.h
	@-mkdir bin
	$(CC) -o $@ $(CFLAGS) $(SRCS)
	mv $(LIB) bin/
