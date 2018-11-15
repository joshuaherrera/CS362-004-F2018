/*
	Joshua Herrera
	CS 362
	Assignment 3
	10/28/18
	gcc -o tesComp unittest1.c dominion.c dominion_helpers.h rngs.c -Wall -fpic -coverage -lm -std=c99


    case village:
			if (villageEffect(currentPlayer, state) == 0)
      {
        //discard played card from hand
        discardCard(handPos, currentPlayer, state, 0);
        return 0;
      }
      return -1;

int villageEffect(int currentPlayer, struct gameState* state)
{
      //+1 Card
      drawCard(currentPlayer, state);
      
      //+2 Actions
      state->numActions = state->numActions - 2;
      return 0;
}
*/


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "great hall"

int main() {
    int newCards = 0;
    int discarded = 1;
    int xtraActions = 0;
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

	//randomize game state

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// ----------- Test +1 card +1 actions --------------
	printf("TEST 2: +1 card, +1 actions\n");

	// copy the game state to a test case
	memcpy(&debugG, &G, sizeof(struct gameState));
	choice1 = 1;
	cardEffect(great_hall, choice1, choice2, choice3, &debugG, handpos, &bonus);
	//
	newCards = 1;
	xtraActions = 1;
	printf("hand count = %d, expected = %d\n", debugG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	if (debugG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded)
		printf("Great Hall hand count: PASSED\n");
	else
		printf("Great Hall hand count: FAILED\n");
	printf("action count = %d, expected = %d\n", debugG.numActions, G.numActions + xtraActions);
	if (debugG.numActions == G.numActions + xtraActions)
		printf("Great Hall action count: PASSED\n");
	else
		printf("Great Hall action count: FAILED\n");
	printf("deck count = %d, expected = %d\n", debugG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	if (debugG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards)
		printf("Great Hall deck count: PASSED\n");
	else
		printf("Great Hall deck count: FAILED\n");
	

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


	return 0;
}


