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

void testKingdomCards()
{
//	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
//			sea_hag, tribute, smithy, council_room};
	int* testCards;
	testCards = kingdomCards(adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room);
	if (testCards[0] == adventurer)
		printf("kingdomCards(): passed for pos 0\n");
	else
		printf("kingdomCards(): failed for pos 0\n");
	if (testCards[1] == embargo)
		printf("kingdomCards(): passed for pos 1\n");
	else
		printf("kingdomCards(): failed for pos 1\n");
	if (testCards[2] == village)
		printf("kingdomCards(): passed for pos 2\n");
	else
		printf("kingdomCards(): failed for pos 2\n");
	if (testCards[3] == minion)
		printf("kingdomCards(): passed for pos 3\n");
	else
		printf("kingdomCards(): failed for pos 3\n");
	if (testCards[4] == mine)
		printf("kingdomCards(): passed for pos 4\n");
	else
		printf("kingdomCards(): failed for pos 4\n");
	if (testCards[5] == cutpurse)
		printf("kingdomCards(): passed for pos 5\n");
	else
		printf("kingdomCards(): failed for pos 5\n");
	if (testCards[6] == sea_hag)
		printf("kingdomCards(): passed for pos 6\n");
	else
		printf("kingdomCards(): failed for pos 6\n");
	if (testCards[7] == tribute)
		printf("kingdomCards(): passed for pos 7\n");
	else
		printf("kingdomCards(): failed for pos 7\n");
	if (testCards[8] == smithy)
		printf("kingdomCards(): passed for pos 8\n");
	else
		printf("kingdomCards(): failed for pos 8\n");
	if (testCards[9] == council_room)
		printf("kingdomCards(): passed for pos 9\n");
	else
		printf("kingdomCards(): failed for pos 9\n");


}

int main(int argc, char const *argv[])
{
	testKingdomCards();
	return 0;
}