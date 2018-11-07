#include "testHelper.h"

void set_all_default(struct gameState * state)
{
	int i;

	state->deckCount[0] = 10;
	state->handCount[0] = 10;
	state->discardCount[0] = 10;

	for (i = 0; i < state->deckCount[0]; i++) { state->deck[0][i] = gold; }
	for (i = 0; i < state->handCount[0]; i++) { state->hand[0][i] = silver; }
	for (i = 0; i < state->discardCount[0]; i++) { state->discard[0][i] = copper; }
}


// Unit Test for fullDeckCount function in dominion.c file 
int main()
{
	printf("Unit Test 3 (fullDeckCount):\n");
	
	struct gameState state;

	// Test 1
	set_all_default(&state);

	assertTrue(fullDeckCount(0, tribute, &state), 0, "All piles full of money cards count number of tribute cards. Count");

	// Test 2
	state.deck[0][0] = tribute;
	state.hand[0][0] = tribute;
	state.discard[0][0] = tribute;

	assertTrue(fullDeckCount(0, tribute, &state), 3, "All piles full have 1 tribute card. Count");

	// Test 3
	state.deck[0][10] = tribute;

	assertTrue(fullDeckCount(0, tribute, &state), 3, "All piles full, have 1 tribute card. Deck also has 1 card outside deckCount. Count");

	printf("All Unit Test 3 tests ran\n");
	return 0;
}