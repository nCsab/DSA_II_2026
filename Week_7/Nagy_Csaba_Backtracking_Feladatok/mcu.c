#include <stdio.h>

// Egy mikrovezérlő 5 specifikus funkcióját (TX, RX, SDA, SCL, ADC) kell
// kiosztani 6 fizikai lábra (P0-P5) úgy, hogy minden funkció olyan lábra
// kerüljön, ami hardveresen támogatja azt, és egy lábat csak egy funkció
// használjon.

const char *fnames[] = {"TX", "RX", "SDA", "SCL", "ADC"};

int caps[6][5] = {{1, 0, 1, 0, 0}, {0, 1, 0, 1, 0}, {0, 0, 1, 0, 1},
                  {1, 0, 0, 1, 0}, {0, 1, 0, 0, 1}, {0, 0, 0, 0, 1}};

int assign[5];
int used[6] = {0};
int solutions = 0;

void solve(int f_idx) {
  if (f_idx == 5) {
    printf("Konfiguráció %d:\n", ++solutions);
    for (int i = 0; i < 5; i++) {
      printf("%-4s -> P%d\n", fnames[i], assign[i]);
    }
    printf("\n");
    return;
  }

  for (int p = 0; p < 6; p++) {
    if (!used[p] && caps[p][f_idx]) {
      used[p] = 1;
      assign[f_idx] = p;

      solve(f_idx + 1);

      used[p] = 0;
    }
  }
}

int main() {
  solve(0);
  if (solutions == 0) {
    printf("Nincs megoldas.\n");
  }
  return 0;
}