#include "testHelper.h"

int assertTrue(int left, int right, char * testString)
{
	int ret = left == right;
	const char * success = ret ? "PASSED" : "FAILED";
	
	printf("%s: %s should be %d is %d.\n", success, testString, right, left);

	return ret;
}


void genDeck(int numCard)
{

}

int genRandNum(unsigned int low, unsigned int high)
{
	return (rand() % high + 1 ) + low;
}