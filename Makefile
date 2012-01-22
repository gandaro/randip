CC=gcc
SHELL=/bin/sh
CFLAGS=-std=c99 -Wall -Wextra
DESTDIR=
PREFIX=/usr/local

.SUFFIXES:
.SUFFIXES: .c

all:
	$(CC) $(CFLAGS) -o randip randip6.c

install:
	$(CC) $(CFLAGS) -o $(DESTDIR)$(PREFIX)/bin/randip randip6.c

clean:
	rm randip

uninstall:
	rm $(DESTDIR)$(PREFIX)/bin/randip
