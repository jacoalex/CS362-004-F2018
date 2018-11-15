#include "testHelper.h"

#define NUM_ITERATIONS 1000
#define NUM_PLAYERS 4

int main(){
	struct gameState state;
	unsigned int old_handCount, playerNum;
	unsigned int numPassed_handCount = 0;

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           		 sea_hag, tribute, smithy};

    unsigned int i;
	for (i = 0; i < NUM_ITERATIONS; i++)
	{
		// passing -1 causes the random number gen to go off of current time
		initializeGame(NUM_PLAYERS, k, -1, &state);

		// pick a random player
		playerNum = genRandNum(0, NUM_PLAYERS - 1);

		state.whoseTurn = playerNum;

		old_handCount = state.handCount[playerNum];

		// call adventurer through card effect, all 0 values aren't used by adventurer
		cardEffect(adventurer, 0, 0, 0, &state, 0, 0);

		if (state.handCount[playerNum] == old_handCount + 2) numPassed_handCount++;
	}

	printf("Random Test Adventurer:\n");
	printf("HandCountsPassed: %.2f%%\n", (float)numPassed_handCount / NUM_ITERATIONS * 100.0);

	return 0;
}