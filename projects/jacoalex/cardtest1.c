#include "testHelper.h"

// Card Test for handle_card_smithy function in dominion.c file 
int main()
{
	printf("Card Test 1 (handle_card_smithy):\n");

	struct gameState state;
	
	int old_handCount, old_deckCount, old_playedCount;
	
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           		 sea_hag, tribute, smithy};

	initializeGame(2, k, 100, &state);

	state.whoseTurn = 0;

	old_handCount = state.handCount[0];
	old_deckCount = state.deckCount[0];
	old_playedCount = state.playedCardCount;

	//handle_card_smithy(0, &state, 1);
	cardEffect(smithy, 0, 0, 0, &state, 1, 0);

	// Test 1
	assertTrue(state.handCount[0], old_handCount + 2, "Hand count");

	// Test 2
	assertTrue(state.deckCount[0], old_deckCount - 3, "Deck count");

	// Test 3
	assertTrue(state.playedCardCount, old_playedCount + 1, "Played count");

	printf("All Card Test 1 tests ran\n");
	return 0;
}

// int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)