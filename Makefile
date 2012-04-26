CC=gcc
SHELL=/bin/sh
CFLAGS=-std=c99 -Wall -Wextra -g
DESTDIR=
PREFIX=/usr/local
INSTALL=install
INSTALL_PROGRAM=$(INSTALL)

.SUFFIXES:
.SUFFIXES: .c

randip: randip6.c
	$(CC) -o randip $(CFLAGS) randip6.c

install: randip
	$(INSTALL) randip $(DESTDIR)$(PREFIX)/bin

install-strip: randip
	$(MAKE) INSTALL_PROGRAM='$(INSTALL) -s' install

clean:
	-rm -f randip

uninstall:
	-rm -f $(DESTDIR)$(PREFIX)/bin/randip
