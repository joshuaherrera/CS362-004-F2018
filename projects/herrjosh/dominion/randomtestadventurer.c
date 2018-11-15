/*
	Joshua Herrera
	CS 362
	Assignment 4
	11/14/18
}
*/


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"

int main() {
    int newCards = 0;
    int discarded = 1;
    int shuffledCards = 0;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    int i = -999;
	struct gameState G, debugG;
	int k[10] = {adventurer, embargo, great_hall, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	for (i = 0; i < 200; i++)
	{
		//randomize state
	    printf("----------------- Randomizing State ----------------\n");
	    thisPlayer = floor(Random() * 2);
	    G.deckCount[thisPlayer] = floor((Random() * MAX_DECK) ); //- (Random() * MAX_HAND)
	    G.discardCount[thisPlayer] = floor(Random() * MAX_DECK);
	    G.handCount[thisPlayer] = floor(Random() * MAX_HAND);

		printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

		// ----------- Test +1 card +1 actions --------------
		printf("TEST 1: +2 treasure cards, discard rest\n");

		// copy the game state to a test case
		memcpy(&debugG, &G, sizeof(struct gameState));
		choice1 = 1;
		cardEffect(adventurer, choice1, choice2, choice3, &debugG, handpos, &bonus);
		newCards = 2;
		printf("hand count = %d, expected = %d\n", debugG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
		if (debugG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded)
			printf("adventurer hand count: PASSED\n");
		else
			printf("adventurer hand count: FAILED\n");
		printf("deck count = %d, expected = %d\n", debugG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
		if (debugG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards)
			printf("adventurer deck count: PASSED\n");
		else
			printf("adventurer deck count: FAILED\n");
		printf("province count = %d, expected = %d\n", debugG.supplyCount[province], G.supplyCount[province]);
		if (debugG.supplyCount[province] == G.supplyCount[province])
			printf("adventurer province count: PASSED\n");
		else
			printf("adventurer province count: FAILED\n");
		printf("estate count = %d, expected = %d\n", debugG.supplyCount[estate], G.supplyCount[estate]);
		if (debugG.supplyCount[province] == G.supplyCount[province])
			printf("adventurer estate count: PASSED\n");
		else
			printf("adventurer estate count: FAILED\n");
		printf("duchy count = %d, expected = %d\n", debugG.supplyCount[duchy], G.supplyCount[duchy]);
		if (debugG.supplyCount[province] == G.supplyCount[province])
			printf("adventurer duchy count: PASSED\n");
		else
			printf("adventurer duchy count: FAILED\n");

		

		printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
	}

	return 0;
}


