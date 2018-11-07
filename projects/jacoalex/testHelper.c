#include "testHelper.h"

int assertTrue(int left, int right, char * testString)
{
	int ret = left == right;
	const char * success = ret ? "PASSED" : "FAILED";
	
	printf("%s: %s should be %d is %d.\n", success, testString, right, left);

	return ret;
}