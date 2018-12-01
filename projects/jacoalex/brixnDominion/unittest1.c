#include "testHelper.h"

// Unit Test for updateCoins function in dominion.c file 
int main()
{
	printf("Unit Test 1 (updateCoins):\n");
	struct gameState state;

	// Test 1
	state.handCount[0] = 3;
	state.coins = 0;

	// 1 copper + 1 silver + 1 gold = 6 coins
	state.hand[0][0] = copper;
	state.hand[0][1] = silver;
	state.hand[0][2] = gold;

	updateCoins(0, &state, 0);
	assertTrue(state.coins, 6, "1 copper, 1 silver, 1 gold. Coins");

	// Test 2
	state.handCount[0] = 6;
	state.coins = 0;

	// 3 copper + 1 silver + 2 gold + 5 bonus = 16 coins
	state.hand[0][0] = copper;
	state.hand[0][1] = silver;
	state.hand[0][2] = gold;
	state.hand[0][3] = copper;
	state.hand[0][4] = gold;
	state.hand[0][5] = copper;


	updateCoins(0, &state, 5);
	assertTrue(state.coins, 16, "3 copper, 1 silver, 2 gold with 5 bonus. Coins");

	// Test 3
	state.handCount[0] = 6;
	state.coins = 0;

	// 1 silver + 2 gold + 7 bonus = 15 coins
	state.hand[0][0] = smithy;
	state.hand[0][1] = adventurer;
	state.hand[0][2] = gold;
	state.hand[0][3] = mine;
	state.hand[0][4] = silver;
	state.hand[0][5] = gold;

	updateCoins(0, &state, 7);
	assertTrue(state.coins, 15, "Extra cards with 1 silver and 1 gold with 7 bonus. Coins");

	// Test 4
	state.handCount[0] = 0;
	state.coins = 0;

	// no currency = 0 coins

	updateCoins(0, &state, 0);
	assertTrue(state.coins, 0, "No copper, silver, or gold. No bonus. Coins");

	// Test 5
	state.handCount[0] = 0;
	state.coins = 0;

	// no currency + 3 bonus = 3 coins

	updateCoins(0, &state, 3);
	assertTrue(state.coins, 3, "No copper, silver, or gold. 3 bonus. Coins");

	printf("All Unit Test 1 tests ran\n");
	return 0;
}