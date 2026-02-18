#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  printf("Add meg a tomb meretet (n): ");
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Ervenytelen meret.\n");
    return 1;
  }

  int *v = (int *)malloc(n * sizeof(int));
  if (v == NULL) {
    printf("Memoriafoglalasi hiba.\n");
    return 1;
  }

  printf("Elemek beolvasasa: \n");
  readElementsRecursive(v, n);

  printf("Elemek kiiratasa: \n");
  printElementsRecursive(v, n);

  int sum = sumElementsRecursive(v, n);
  printf("Elemek osszege: \n");
  printf("Osszeg: %d\n", sum);

  free(v);
  return 0;
}
