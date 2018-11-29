/*
	Joshua Herrera
	CS 362
	Assignment 3
	10/28/18
	gcc -o tesComp unittest1.c dominion.c dominion_helpers.h rngs.c -Wall -fpic -coverage -lm -std=c99

*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

void testCompare()
{
	int testArr[5] = {-1, 0, 1, -999, 999};

	if (compare((int*)&testArr[0], (int*)&testArr[0]) == 0)
		printf("compare(): PASSED for equality\n");
	else
		printf("compare(): FAILED for equality\n");
	if (compare((int*)&testArr[0], (int*)&testArr[4]) == -1)
		printf("compare(): PASSED for a < b\n");
	else
		printf("compare(): FAILED for a < b\n");
	if (compare((int*)&testArr[0], (int*)&testArr[3]) == 1)
		printf("compare(): PASSED for a > b\n");
	else
		printf("compare(): FAILED for a > b\n");

}

int main(int argc, char const *argv[])
{
	testCompare();
	return 0;
}