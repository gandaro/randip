CC=gcc
SHELL=/bin/sh
CFLAGS=-std=c99 -Wall -Wextra

.SUFFIXES:
.SUFFIXES: .c

all:
	$(CC) $(CFLAGS) -o randip randip6.c

install:
	$(CC) $(CFLAGS) -o /usr/local/bin/randip randip6.c

clean:
	rm randip

uninstall:
	rm /usr/local/bin/randip
