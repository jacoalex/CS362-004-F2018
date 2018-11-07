#include "testHelper.h"

// Card Test for handle_card_adventurer function in dominion.c file 
int main()
{
	printf("Card Test 2 (handle_card_adventurer):\n");

	struct gameState state;

	int old_handCount, old_deckCount, old_discardCount;
	
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           		 sea_hag, tribute, smithy};

	initializeGame(2, k, 100, &state);

	state.whoseTurn = 0;

	old_handCount = state.handCount[0];
	old_deckCount = state.deckCount[0];
	old_discardCount = state.discardCount[0];
	
	//handle_card_adventurer(drawntreasure, &state, 0, temphand, z, cardDrawn);
	cardEffect(adventurer, 0, 0, 0, &state, 0, 0);

	// Test 1
	assertTrue(state.handCount[0], old_handCount + 2, "Hand count");

	// Test 2
	assertTrue(state.deckCount[0], old_deckCount - 2, "Deck count");

	// Test 3
	assertTrue(state.discardCount[0], old_discardCount, "Discard count");

	printf("All Card Test 2 tests ran\n");
	return 0;
}

// int handle_card_adventurer(int drawntreasure, struct gameState *state, int currentPlayer, int temphand[], int z, int cardDrawn)
// int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)