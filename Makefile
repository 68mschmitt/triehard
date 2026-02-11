CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2 -Iinclude
LDFLAGS =

SRCS = src/wordlib.c
OBJS = $(SRCS:.c=.o)

all: wordlib

wordlib: $(OBJS) cli/main.o
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o$@ $<

src/wordlib.o: src/wordlib.c include/wordlib.h

clean:
	rm -f $(OBJS) cli/main.o wordlib

.PHONY: all clean
