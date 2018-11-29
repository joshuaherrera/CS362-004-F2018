/*
	Joshua Herrera
	CS 362
	Assignment 3
	10/28/18
	gcc -o test2 unittest1.c dominion.c dominion_helpers.h rngs.c -Wall -fpic -coverage -lm -std=c99

int whoseTurn(struct gameState *state) {
  return state->whoseTurn;
}

}

*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

void testWhoseTurn()
{
	struct gameState G;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	int numPlayers = 2;
	int seed = 1000;
	initializeGame(numPlayers, k, seed, &G);

	if (whoseTurn(&G) == 0)
		printf("whoseTurn(): PASSED for player 0\n");
	else
		printf("whoseTurn(): FAILED for player 0\n");
	G.whoseTurn++;

	if (whoseTurn(&G) == 1)
		printf("whoseTurn(): PASSED for player 1\n");
	else
		printf("whoseTurn(): FAILED for player 1\n");
	G.whoseTurn = 999;

	if (whoseTurn(&G) == 999)
		printf("whoseTurn(): PASSED for player 999\n");
	else
		printf("whoseTurn(): FAILED for player 999\n");
	G.whoseTurn = -999;

	if (whoseTurn(&G) == -999)
		printf("whoseTurn(): PASSED for player -999\n");
	else
		printf("whoseTurn(): FAILED for player -999\n");

}

int main(int argc, char const *argv[])
{
	testWhoseTurn();
	return 0;
}