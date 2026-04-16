#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define PLAYERS 8
#define KO 0
#define PAPIR 1
#define OLLO 2

typedef struct {
  char name[20];
  int choice;
} Player;

void readPlayers(Player *players, int n);
void printPlayers(Player *players, int n);
const char *choiceName(int choice);
int match(Player *a, Player *b);
int tournament(Player *players, int left, int right);

#endif
