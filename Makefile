CC=gcc
CFLAGS=-Wall -Wextra -std=c99 -g -Wno-unused-parameter

MAIN=main.c
LIBS=functions.c

.PHONY: all
all:
	$(CC) $(MAIN) $(LIBS) -o hinfosvc $(CFLAGS) -g


.PHONY: run
run: all
	./hinfosvc