CC = gcc
CFLAGS = -g -Wall -std=c11 -D_XOPEN_SOURCE=700

RM = rm -rf

all: clean
	$(CC) -o conv conv.c $(CFLAGS)
	$(CC) -o desconv desconv.c $(CFLAGS)

clean:
	-$(RM) conv desconv
