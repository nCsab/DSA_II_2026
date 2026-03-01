#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void readPlayers(Player *players, int n) {
  for (int i = 0; i < n; i++) {
    sprintf(players[i].name, "D%d", i);
    players[i].choice = rand() % 3;
  }
}

void printPlayers(Player *players, int n) {
  for (int i = 0; i < n; i++) {
    printf("  %s: %s\n", players[i].name, choiceName(players[i].choice));
  }
}

const char *choiceName(int choice) {
  if (choice == KO)
    return "Ko";
  if (choice == PAPIR)
    return "Papir";
  return "Ollo";
}

int match(Player *a, Player *b) {
  if (a->choice == b->choice) {
    a->choice = rand() % 3;
    b->choice = rand() % 3;
    return match(a, b);
  }
  if ((a->choice == KO && b->choice == OLLO) ||
      (a->choice == OLLO && b->choice == PAPIR) ||
      (a->choice == PAPIR && b->choice == KO)) {
    return 0;
  }
  return 1;
}

int tournament(Player *players, int left, int right) {
  if (left == right)
    return left;

  int mid = (left + right) / 2;
  int winner1 = tournament(players, left, mid);
  int winner2 = tournament(players, mid + 1, right);

  players[winner1].choice = rand() % 3;
  players[winner2].choice = rand() % 3;

  printf("%s (%s) vs %s (%s)", players[winner1].name,
         choiceName(players[winner1].choice), players[winner2].name,
         choiceName(players[winner2].choice));

  int result = match(&players[winner1], &players[winner2]);
  int winner = (result == 0) ? winner1 : winner2;
  printf(" -> Gyoztes: %s\n", players[winner].name);

  return winner;
}
