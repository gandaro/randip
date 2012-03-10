CC=cc
SHELL=/bin/sh
INSTALL=install
INSTALL_PROGRAM=$(INSTALL)
CFLAGS=-Wall -Wextra -g -std=c99
DESTDIR=
prefix=/usr/local
exec_prefix=$(prefix)
bindir=$(exec_prefix)/bin

all: randip

install: randip
	$(INSTALL_PROGRAM) randip $(DESTDIR)$(bindir)

install-strip: randip
	$(MAKE) INSTALL_PROGRAM='$(INSTALL) -s' install

clean:
	-rm -f randip

uninstall:
	-rm -f $(DESTDIR)$(bindir)/randip
