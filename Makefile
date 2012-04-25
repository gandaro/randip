CC=gcc
SHELL=/bin/sh
CFLAGS=-std=c99 -Wall -Wextra -g
DESTDIR=
PREFIX=/usr/local
INSTALL=install
INSTALL_PROGRAM=$(INSTALL)

.SUFFIXES:
.SUFFIXES: .c

all:
	$(CC) -o randip $(CFLAGS) randip6.c

install:
	$(INSTALL) randip $(DESTDIR)$(PREFIX)/bin

install-strip:
	$(MAKE) INSTALL_PROGRAM='$(INSTALL) -s' install

clean:
	rm randip

uninstall:
	rm $(DESTDIR)$(PREFIX)/bin/randip
