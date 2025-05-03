srcdir = .
exec_prefix = /usr/local
bindir = $(exec_prefix)/bin

prefix = /usr/local/quark
includedir = $(prefix)/include
libdir = $(prefix)/lib
syslibdir = /lib

SRCS = 

-include config.mak

all:
	@echo ""
	@exit 1
