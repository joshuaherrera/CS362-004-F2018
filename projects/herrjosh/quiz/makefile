CFLAGS= -Wall -std=c99

all: run

testfile:
	gcc -o testme testme.c $(CFLAGS)

run: testfile
	./testme

clean:
	rm -f testme
