#include "testHelper.h"

int compare(const void* a, const void* b);

// Unit Test for handCard function in dominion.c file 
int main()
{
	printf("Unit Test 4 (handCard):\n");

	struct gameState state;

	// Test 1
	state.whoseTurn = 1;
	state.hand[0][1] = 1;
	state.hand[1][1] = 5;

	assertTrue(handCard(1, &state), 5, "whoseTurn is 1 and card 1 of player 1 is 5.");

	// Test 2
	state.whoseTurn = 1;
	state.hand[0][1] = 8;
	state.hand[1][1] = 0;

	assertTrue(handCard(1, &state), 0, "whoseTurn is 1 and card 1 of player 1 is 0.");
	
	printf("All Unit Test 4 tests ran\n");
	return 0;
}