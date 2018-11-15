CFLAGS= -Wall -g -fpic -coverage -lm -std=c99 -fprofile-generate

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

unittestresults.out: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.o rngs.o
	
	echo "Result for running unit tests:" > unittestresults.out
	echo "unittest1.c:" >> unittestresults.out
	gcc -o unittest1.bin dominion.o rngs.o unittest1.c $(CFLAGS)
	./unittest1.bin >> unittestresults.out
	gcov dominion.o -f -b >> unittestresults.out
	
	echo "unittest2.c:" >> unittestresults.out
	gcc -o unittest2.bin dominion.o rngs.o unittest2.c $(CFLAGS)
	./unittest2.bin >> unittestresults.out
	gcov dominion.c -f -b >> unittestresults.out
	
	echo "unittest3.c:" >> unittestresults.out
	gcc -o unittest3.bin dominion.o rngs.o unittest3.c $(CFLAGS)
	./unittest3.bin >> unittestresults.out
	gcov dominion.c -f -b >> unittestresults.out
	
	echo "unittest4.c:" >> unittestresults.out
	gcc -o unittest4.bin dominion.o rngs.o unittest4.c $(CFLAGS)
	./unittest4.bin >> unittestresults.out
	gcov dominion.c -f -b >> unittestresults.out
	
	echo "cardtest1.c:" >> unittestresults.out
	gcc -o cardtest1.bin dominion.o rngs.o cardtest1.c $(CFLAGS)
	./cardtest1.bin >> unittestresults.out
	gcov dominion.c -f -b >> unittestresults.out
	
	echo "cardtest2.c:" >> unittestresults.out
	gcc -o cardtest2.bin dominion.o rngs.o cardtest2.c $(CFLAGS)
	./cardtest2.bin >> unittestresults.out
	gcov dominion.c -f -b >> unittestresults.out
	
	echo "cardtest3.c:" >> unittestresults.out
	gcc -o cardtest3.bin dominion.o rngs.o cardtest3.c $(CFLAGS)
	./cardtest3.bin >> unittestresults.out
	gcov dominion.c -f -b >> unittestresults.out
	
	echo "cardtest4.c:" >> unittestresults.out
	gcc -o cardtest4.bin dominion.o rngs.o cardtest4.c $(CFLAGS)
	./cardtest4.bin >> unittestresults.out
	gcov dominion.c -f -b >> unittestresults.out

randomtestcard1.out: randomtestcard1.c dominion.o rngs.o
	
	echo "Result for running random tests:" > randomtestcard1.out
	echo "randomtestcard1.c:" >> randomtestcard1.out
	gcc -o randomtestcard1.bin dominion.o rngs.o randomtestcard1.c $(CFLAGS)
	./randomtestcard1.bin >> randomtestcard1.out
	gcov dominion.o -f -b >> randomtestcard1.out

randomtestcard2.out: randomtestcard2.c dominion.o rngs.o
	
	echo "Result for running random tests:" > randomtestcard2.out
	echo "randomtestcard2.c:" >> randomtestcard2.out
	gcc -o randomtestcard2.bin dominion.o rngs.o randomtestcard2.c $(CFLAGS)
	./randomtestcard2.bin >> randomtestcard2.out
	gcov dominion.o -f -b >> randomtestcard2.out

randomtestadventurer.out: randomtestadventurer.c dominion.o rngs.o
	
	echo "Result for running random tests:" > randomtestadventurer.out
	echo "randomtestadventurer.c:" >> randomtestadventurer.out
	gcc -o randomtestadventurer.bin dominion.o rngs.o randomtestadventurer.c $(CFLAGS)
	./randomtestadventurer.bin >> randomtestadventurer.out
	gcov dominion.o -f -b >> randomtestadventurer.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe *.bin
