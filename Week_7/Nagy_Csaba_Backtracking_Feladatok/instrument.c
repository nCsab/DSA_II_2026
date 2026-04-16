#include <stdio.h>
#include <stdlib.h>

// Egy adott hangsor összes lehetséges zenei dallamát kilistázza szigorúan
// meghatározott szabályrendszer alapján.

const char *notes[] = {"C", "D", "E", "F", "G", "A", "B"};
int n, m, cnt = 0, melody[100];

void solve(int p) {
  if (p == n) {
    printf("%d. dallam: ", ++cnt);
    for (int i = 0; i < n; i++) {
      if (i > 0 && i % m == 0)
        printf("| ");
      printf("%s ", notes[melody[i]]);
    }
    printf("\n");
    return;
  }

  for (int i = 0; i <= 6; i++) {
    if (i == melody[p - 1] || abs(i - melody[p - 1]) > 2)
      continue;
    if (p == n - 1 && i != 0)
      continue;

    melody[p] = i;
    solve(p + 1);
  }
}

int main() {
  int u;
  printf("Hany utem legyen? ");
  if (scanf("%d", &u) != 1 || u < 1)
    return 1;
  printf("Hangok/utem? ");
  if (scanf("%d", &m) != 1 || m < 1)
    return 1;
  n = u * m;

  melody[0] = 0;
  solve(1);

  printf("Osszesen %d ervenyes dallam.\n", cnt);
  return 0;
}
