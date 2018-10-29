CFLAGS= -Wall -std=c99

all: testfile

testfile:
	gcc -o testme testme.c $(CFLAGS)

run: testme
	./testme

clean:
	rm -f testme
