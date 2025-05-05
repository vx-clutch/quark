srcdir = .
exec_prefix = /usr/local
bindir = $(exec_prefix)/bin

CC = gcc
CFLAGS = -Wall -Wextra -O2
LDFLAGS =

prefix = /usr/local/
includedir = $(prefix)/include
libdir = $(prefix)/lib
syslibdir = /lib

SRCS = $(wildcard src/**/*.c)
HEADERS = $(wildcard include/**/*.h)
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
	install -d $(DESTDIR)$(bindir)
	install -m 755 $(SHARED_LIB) $(DESTDIR)$(bindir)
	install -d $(DESTDIR)$(includedir)
	install -m 644 $(HEADERS) $(DESTDIR)$(includedir)

uninstall:
	rm -f $(DESTDIR)$(bindir)/$(notdir $(SHARED_LIB))
	rm -rf $(DESTDIR)$(includedir)
	
clean:
	rm -rf $(OBJ_DIR) lib

dist-clean: clean
	rm config.mak

.PHONY: all clean dist-clean install uninstall
