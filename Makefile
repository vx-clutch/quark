srcdir = .
exec_prefix = /usr/local
bindir = $(exec_prefix)/bin

CC = gcc
CFLAGS = -Wall -Wextra -O2
LDFLAGS =

prefix = /usr/local
includedir = $(prefix)/include
libdir = $(prefix)/lib
syslibdir = /lib

SRCS = $(wildcard $(srcdir)/src/**/*.c)
HEADERS = $(wildcard $(srcdor)/src/**/*.h)
OBJ_DIR = obj
OBJS = $(SRCS:.c=.o)

STATIC_LIB = lib/libq.a
SHARED_LIB = lib/libq.so
ALL_LIBS = $(STATIC_LIB) $(SHARED_LIB)

-include config.mak

ifeq ($(wildcard config.mak),)

all:
	@echo "File config.mak not found, run configure"
	@exit 1

else

all: clean $(ALL_LIBS)

$(OBJ_DIR):
	mkdir -p $@

lib:
	mkdir -p $@

$(STATIC_LIB): $(OBJS) $(HEADERS) | lib
	ar rcs $@ $^

$(SHARED_LIB): $(OBJS) $(HEADERS) | lib
	$(CC) -I./include/ -shared -o $@ $(OBJS)

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

endif

install:
	@echo "NOT IMPL"
	exit 1

uninstall:
	@echo "NOT IMPL"
	exit 1

clean:
	rm -rf $(OBJ_DIR) lib

dist-clean: clean
	rm config.mak

.PHONY: all clean dist-clean install uninstall
