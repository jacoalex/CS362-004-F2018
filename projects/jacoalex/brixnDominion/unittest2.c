#include "testHelper.h"

// Unit Test for isGameOver function in dominion.c file 
int main()
{
	printf("Unit Test 2 (isGameOver):\n");
	
	struct gameState state;
	int i;

	// game setup
	state.supplyCount[province] = 0;

	assertTrue(isGameOver(&state), 1, "No province cards remain. Return value");

	// game setup
	for (i = 0; i < 25; i++) { state.supplyCount[i] = 1; }
	state.supplyCount[1] = 0;
	state.supplyCount[15] = 0;

	assertTrue(isGameOver(&state), 0, "Only 2 supply piles are empty. Return value");

	// game setup
	for (i = 0; i < 25; i++) { state.supplyCount[i] = 1; }
	state.supplyCount[1] = 0;
	state.supplyCount[15] = 0;
	state.supplyCount[24] = 0;

	assertTrue(isGameOver(&state), 1, "3 supply piles are empty. Return value");

	// game setup
	for (i = 0; i < 25; i++) { state.supplyCount[i] = 1; }
	state.supplyCount[1] = 0;
	state.supplyCount[15] = 0;
	state.supplyCount[24] = 0;
	state.supplyCount[7] = 0;

	assertTrue(isGameOver(&state), 1, "4 supply piles are empty. Return value");

	// game setup
	for (i = 0; i < 25; i++) { state.supplyCount[i] = 1; }
	state.supplyCount[province] = 0;
	state.supplyCount[15] = 0;

	assertTrue(isGameOver(&state), 1, "Only 2 supply piles are empty but one is the province supply. Return value");

	printf("All Unit Test 2 tests ran\n");
	return 0;
}