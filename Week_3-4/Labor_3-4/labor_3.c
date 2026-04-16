#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;

  printf("Kerekpar-zar (Btd) - Add meg a szamjegyek szamat (n): ");
  if (scanf("%d", &n) != 1 || n <= 0) return 1;
  int *x1 = (int *)malloc((n + 1) * sizeof(int));
  BTd_bicycle(x1, n, 1);
  free(x1);

  printf("\nDescartes szorzat - Add meg a halmaz meretet es n-szeres szorzat (n): ");
  if (scanf("%d", &n) != 1 || n <= 0) return 1;
  int *x2 = (int *)malloc((n + 1) * sizeof(int));
  BTd_cartesian(x2, n, 1);
  free(x2);

  printf("\nPermutaciok (BTp) - Add meg n erteket: ");
  if (scanf("%d", &n) != 1 || n <= 0) return 1;
  int *x3 = (int *)malloc((n + 1) * sizeof(int));
  BTp(x3, n, 1);
  free(x3);

  printf("\nN-kiralyno - Add meg n erteket: ");
  if (scanf("%d", &n) != 1 || n <= 0) return 1;
  int *x4 = (int *)malloc((n + 1) * sizeof(int));
  BTkiralyno(x4, n, 1);
  free(x4);

  return 0;
}
