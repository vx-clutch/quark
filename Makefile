CC = gcc
CFLAGS = -std=c11 -fPIC
SRCS = $(wildcard libq/*.c)
OBJS = $(SRCS:libq/%.c=bin/obj/%.o)

all: bindir libq.so libq.a

bindir:
	@mkdir -p bin/share bin/archive bin/obj

bin/obj/%.o: libq/%.c quarks.h
	$(CC) $(CFLAGS) -c $< -o $@

libq.so: $(OBJS)
	$(CC) -shared $(CFLAGS) -o bin/share/libq.so $(OBJS)

libq.a: $(OBJS)
	ar rcs bin/archive/libq.a $(OBJS)

clean:
	@-rm -rf bin
	@-rm main
	@-rm $(OBJS)

test: main.c all
	@$(CC) -o main main.c -Lbin/share -lq -Wl,-rpath=bin/share
	@echo
	@./main
	@rm main
.PHONY: test clean bindir
