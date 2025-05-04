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
OBJS = $(SRCS:.c=.o)

OBJ_DIR = obj/

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

$(ALL_LIBS): | $(OBJ_DIRS)

$(OBJ_DIR):
	mkdir -p $@

$(STATIC_LIB): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

$(SHARED_LIB): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRCS):/%.c
	$(CC) $(CFLAGS) -c $< -o $@

endif

clean:
	rm -rf obj lib

.PHONY all clean
