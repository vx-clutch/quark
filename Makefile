srcdir = .
exec_prefix = /usr/local
bindir = $(exec_prefix)/bin

CC = gcc
CFLAGS = -Wall -Wextra -O2
LDFLAGS =

prefix = /usr/local/quark
includedir = $(prefix)/include
libdir = $(prefix)/lib
syslibdir = /lib

SRCS = $(wildcard src/*.c)
OBJ_DIR = obj
OBJS = $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(SRCS))

STATIC_LIB = lib/libq.a
SHARED_LIB = lib/libq.so
ALL_LIBS = $(STATIC_LIB) $(SHARED_LIB)

-include config.mak

ifeq ($(wildcard config.mak),)

all:
	@echo "File config.mak not found, run configure"
	@exit 1

else

all: $(ALL_LIBS)

$(OBJ_DIR):
	mkdir -p $@

lib:
	mkdir -p $@

$(STATIC_LIB): $(OBJS) | lib
	ar rcs $@ $^

$(SHARED_LIB): $(OBJS) | lib
	$(CC) -shared -o $@ $^

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

endif

clean:
	rm -rf $(OBJ_DIR) lib

clean-dist: clean
	rm config.mak

.PHONY: all clean clean-dist
