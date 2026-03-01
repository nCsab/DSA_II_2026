#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));

  Player players[PLAYERS];
  readPlayers(players, PLAYERS);

  printf("Jatekosok:\n");
  printPlayers(players, PLAYERS);

  printf("\nTorna:\n");
  int winner = tournament(players, 0, PLAYERS - 1);

  printf("\nA torna gyoztese: %s\n", players[winner].name);

  return 0;
}
