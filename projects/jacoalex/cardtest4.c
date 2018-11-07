#include "testHelper.h"

// Card Test for handle_card_village function in dominion.c file 
int main()
{
	printf("Card Test 4 (handle_card_village):\n");

	struct gameState state;

	int old_handCount, old_deckCount, old_playedCount, old_numActions;

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           		 sea_hag, tribute, smithy};

	initializeGame(2, k, 100, &state);

	state.whoseTurn = 0;

	old_handCount = state.handCount[0];
	old_deckCount = state.deckCount[0];
	old_playedCount = state.playedCardCount;
	old_numActions = state.numActions;
	
	cardEffect(village, 0, 0, 0, &state, 0, 0);

	// Test 1
	assertTrue(state.handCount[0], old_handCount, "Hand count");

	// Test 2
	assertTrue(state.deckCount[0], old_deckCount - 1, "Deck count");

	// Test 3
	assertTrue(state.playedCardCount, old_playedCount + 1, "Played count");

	// Test 4
	assertTrue(state.numActions, old_numActions + 2, "Num Actions");

	printf("All Card Test 4 tests ran\n");
	return 0;
}

// int handle_card_village(int currentPlayer, struct gameState *state, int handPos)
// int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)