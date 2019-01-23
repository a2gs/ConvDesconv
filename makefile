all: clean
	cc -o conv conv.c -Wall -g -std=c11
	cc -o desconv desconv.c -Wall -g -std=c11

clean:
	-rm conv desconv
