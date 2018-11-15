CFLAGS = -Wall -fpic -coverage -lm

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

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean: cleanTests
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe

# Assignment 4
randomTests = randomtestcard1 randomtestcard2 randomtestadventurer
# remove -n flag to generate dominion.c.gcov file
GCOV_ARGS = -f -b -n

testHelper.o: dominion.o testHelper.c
	gcc -c testHelper.c -g $(CFLAGS)

# runs for randomtestcard1, randomtestcard2, or randomtestadventurer
$(randomTests): %: %.c dominion.o rngs.o testHelper.o
	gcc -g $< dominion.o rngs.o testHelper.o -o $@ $(CFLAGS)

	echo "###########################################" > $@.out
	echo "  Tests started at: $$(date '+%D %r')" >> $@.out
	echo "###########################################" >> $@.out
	echo >> $@.out
	
	echo "#######################################" >> $@.out
	./$@ >> $@.out
	echo "#######################################" >> $@.out
	echo >> $@.out
	
	echo "############" >> $@.out
	echo "  Coverage  " >> $@.out
	echo "############" >> $@.out
	echo >> $@.out

	gcov dominion.c $(GCOV_ARGS) >> $@.out

randomtestresults: randomtestcard1 randomtestcard2 randomtestadventurer

cleanTests:
	rm -f randomtestcard1 randomtestcard2 randomtestadventurer
