#include "testHelper.h"

// Card Test for handle_card_outpost function in dominion.c file 
int main()
{
	printf("Card Test 3 (handle_card_outpost):\n");

	struct gameState state;

	int old_outpostPlayed, old_playCardCount;

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           		 sea_hag, tribute, smithy};

	initializeGame(2, k, 100, &state);

	state.whoseTurn = 0;

	old_outpostPlayed = state.outpostPlayed;
	old_playCardCount = state.playedCardCount;
	
	cardEffect(outpost, 0, 0, 0, &state, 0, 0);

	// Test 1
	assertTrue(state.outpostPlayed, old_outpostPlayed + 1, "Number of outposts played");

	// Test 2
	assertTrue(state.playedCardCount, old_playCardCount + 1, "Played card count");

	printf("All Card Test 3 tests ran\n");
	return 0;
}

// int handle_card_outpost(struct gameState *state, int handPos, int currentPlayer)
// int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)