/* 
** Joshua Herrera
** CS362
** Assignment 4
** 11/14/2018
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
    int i = -999;
  struct gameState G, debugG;
  int k[10] = {adventurer, embargo, great_hall, minion, mine, cutpurse,
      sea_hag, tribute, smithy, council_room};

  // initialize a game state and player cards
  initializeGame(numPlayers, k, seed, &G);


  //run tests 2000 times
  for (i = 0; i < 2000; i++)
  {
  //randomize game state
    printf("----------------- Randomizing State ----------------\n");
    thisPlayer = floor(Random() * 2);
    G.deckCount[thisPlayer] = floor((Random() * MAX_DECK) ); //- (Random() * MAX_HAND)
    G.discardCount[thisPlayer] = floor(Random() * MAX_DECK);
    G.handCount[thisPlayer] = floor(Random() * MAX_HAND);
    printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

    // ----------- Test +1 card +1 actions --------------
    printf("TEST 1: +1 card, +1 actions\n");

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
  }
  

  printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


  return 0;
}


