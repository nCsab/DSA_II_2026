#include <stdio.h>

const char *name[] = {"FIDESZ-KDNP", "TISZA", "DK", "MHM", "MKKP"};
int mand[] = {85, 45, 30, 20, 19};
int veto[5][5] = {{0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0},
                  {1, 1, 0, 1, 0},
                  {0, 1, 1, 0, 1},
                  {1, 0, 0, 1, 0}};

int coal[5], found = 0;

void solve(int p) {
  if (p == 5) {
    int current_seats = 0;
    for (int i = 0; i < 5; i++) {
      if (coal[i]) {
        current_seats += mand[i];
      }
    }

    if (current_seats >= 100) {
      printf("%d. Koalicio (%d mandatum): ", ++found, current_seats);
      for (int i = 0; i < 5; i++)
        if (coal[i])
          printf("%s ", name[i]);
      printf("\n");
    }
    return;
  }

  solve(p + 1);

  int ok = 1;
  for (int i = 0; i < p; i++)
    if (coal[i] && veto[i][p])
      ok = 0;

  if (ok) {
    coal[p] = 1;
    solve(p + 1);
    coal[p] = 0;
  }
}

int main() {
  solve(0);

  if (!found) {
    printf("Nem alakithato tobbsegi kormany.\n");
  } else {
    printf("\nOsszesen: %d db eletkepes koalicio.\n", found);
  }

  return 0;
}