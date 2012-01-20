CFLAGS=-std=c99 -Wall -Wextra

all:
	gcc $(CFLAGS) -o randip randip6.c

clean:
	rm randip
