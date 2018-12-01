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

# Assignment 5
testHelper.o: dominion.o testHelper.c
	gcc -c testHelper.c -g $(CFLAGS)

cardtest1: testHelper.o cardtest1.c
	gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o testHelper.o $(CFLAGS)

cardtest2: testHelper.o cardtest2.c
	gcc -o cardtest2 -g cardtest2.c dominion.o rngs.o testHelper.o $(CFLAGS)

cardtest3: testHelper.o cardtest3.c
	gcc -o cardtest3 -g cardtest3.c dominion.o rngs.o testHelper.o $(CFLAGS)

cardtest4: testHelper.o cardtest4.c
	gcc -o cardtest4 -g cardtest4.c dominion.o rngs.o testHelper.o $(CFLAGS)

allTests: cardtest1 cardtest2 cardtest3 cardtest4


RESULT_FILE = unittestresults.out
# remove -n flag to generate dominion.c.gcov file
GCOV_ARGS = -f -b -n

unittestresults: allTests
	echo "###########################################" > $(RESULT_FILE)
	echo "  Tests started at: $$(date '+%D %r')" >> $(RESULT_FILE)
	echo "###########################################" >> $(RESULT_FILE)
	echo >> $(RESULT_FILE)

	echo "#######################################" >> $(RESULT_FILE)
	./cardtest1 >> $(RESULT_FILE)
	echo "#######################################" >> $(RESULT_FILE)
	./cardtest2 >> $(RESULT_FILE)
	echo "#######################################" >> $(RESULT_FILE)
	./cardtest3 >> $(RESULT_FILE)
	echo "#######################################" >> $(RESULT_FILE)
	./cardtest4 >> $(RESULT_FILE)
	echo >> $(RESULT_FILE)

	echo "############" >> $(RESULT_FILE)
	echo "  Coverage  " >> $(RESULT_FILE)
	echo "############" >> $(RESULT_FILE)
	echo >> $(RESULT_FILE)

	gcov dominion.c $(GCOV_ARGS) >> $(RESULT_FILE)

cleanTests:
	rm -f randomtestcard1 randomtestcard2 randomtestadventurer
	rm -f unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 $(RESULT_FILE)
