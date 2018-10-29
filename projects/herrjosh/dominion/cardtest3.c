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

#define TESTCARD "smithy"

int main() {
    int newCards = 0;
    int discarded = 1;
    int shuffledCards = 0;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, debugG;
	int k[10] = {adventurer, embargo, great_hall, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// ----------- Test +1 card +1 actions --------------
	printf("TEST 3: +3 cards\n");

	// copy the game state to a test case
	memcpy(&debugG, &G, sizeof(struct gameState));
	choice1 = 1;
	cardEffect(smithy, choice1, choice2, choice3, &debugG, handpos, &bonus);
	newCards = 3;
	printf("hand count = %d, expected = %d\n", debugG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	if (debugG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded)
		printf("smithy hand count: PASSED\n");
	else
		printf("smithy hand count: FAILED\n");
	printf("deck count = %d, expected = %d\n", debugG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	if (debugG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards)
		printf("smithy deck count: PASSED\n");
	else
		printf("smithy deck count: FAILED\n");
	printf("province count = %d, expected = %d\n", debugG.supplyCount[province], G.supplyCount[province]);
	if (debugG.supplyCount[province] == G.supplyCount[province])
		printf("smithy province count: PASSED\n");
	else
		printf("smithy province count: FAILED\n");
	printf("estate count = %d, expected = %d\n", debugG.supplyCount[estate], G.supplyCount[estate]);
	if (debugG.supplyCount[province] == G.supplyCount[province])
		printf("smithy estate count: PASSED\n");
	else
		printf("smithy estate count: FAILED\n");
	printf("duchy count = %d, expected = %d\n", debugG.supplyCount[duchy], G.supplyCount[duchy]);
	if (debugG.supplyCount[province] == G.supplyCount[province])
		printf("smithy duchy count: PASSED\n");
	else
		printf("smithy duchy count: FAILED\n");

	

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


	return 0;
}


