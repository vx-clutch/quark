CC = gcc
CFLAGS = -std=c11 -fPIC
SRCS = $(wildcard libq/*.c)
OBJS = $(SRCS:.c=.o)

all: bindir libq.so libq.a

bindir:
	@mkdir -p bin/share
	@mkdir -p bin/archive
	@mkdir -p bin/obj

libq.so: $(SRCS) quarks.h
	$(CC) -shared $(CFLAGS) -o bin/share/libq.so $(SRCS)

libq.a: $(OBJS)
	ar rcs bin/archive/libq.a $(OBJS)

libq/%.o: libq/%.c quarks.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf bin
	find libq -name '*.o' -delete

test: main.c
	gcc -o main main.c -Lbin/share -lq -Wl,-rpath=bin/share

