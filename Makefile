CC=gcc
CFLAGS=-Wall -Wextra -std=c11
SRCS=$(wildcard libq/*.c)

all: libq.so libq.a

bindir:
	@mkdir -p bin/share
	@mkdir -p bin/archive
	@mkdir -p bin/obj

libq.so: $(SRCS) quarks.h
	$(CC) -shared -fPIC -o bin/share/$@ $(CFLAGS) $(SRCS)

libq.a: $(SRCS) quarks.h
	$(CC) -co bin/obj/$@ $(CFLAGS) $(SRCS)
	ar rcs bin/obj/$@
