/*
	Joshua Herrera
	CS 362
	Assignment 3
	10/28/18
	gcc -o test2 unittest1.c dominion.c dominion_helpers.h rngs.c -Wall -fpic -coverage -lm -std=c99

int isGameOver(struct gameState *state) {
  int i;
  int j;
	
  //if stack of Province cards is empty, the game ends
  if (state->supplyCount[province] == 0)
    {
      return 1;
    }

  //if three supply pile are at 0, the game ends
  j = 0;
  for (i = 0; i < 25; i++)
    {
      if (state->supplyCount[i] == 0)
	{
	  j++;
	}
    }
  if ( j >= 3)
    {
      return 1;
    }

  return 0;
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

void testIsGameOver()
{
	struct gameState G;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	int numPlayers = 2;
	int seed = 1000;
	initializeGame(numPlayers, k, seed, &G);

	G.supplyCount[province] = 0;
	if (isGameOver(&G) == 1)
		printf("isGameOver(): PASSED for province cards == 0\n");
	else
		printf("isGameOver(): failed for province cards == 0\n");
	G.supplyCount[province] = 12;
	G.supplyCount[0] = 0;
	G.supplyCount[1] = 0;
	G.supplyCount[2] = 0;
	if (isGameOver(&G) == 1)
		printf("isGameOver(): PASSED for 3 supply piles at 0\n");
	else
		printf("isGameOver(): FAILED for 3 supply piles at 0\n");
	G.supplyCount[3] = 0;
	if (isGameOver(&G) == 1)
		printf("isGameOver(): PASSED for 4 supply piles at 0\n");
	else
		printf("isGameOver(): FAILED for 4 supply piles at 0\n");

}

int main(int argc, char const *argv[])
{
	testIsGameOver();
	return 0;
}