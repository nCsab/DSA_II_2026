#include "functions.h"
#include <stdio.h>

int readElementsRecursive(int *v, int n) {
  if (n == 0) {
    return 0;
  }
  printf("Adj meg egy elemet: ");
  if (scanf("%d", v) != 1) {
    return -1;
  }
  return readElementsRecursive(v + 1, n - 1);
}

int printElementsRecursive(int *v, int n) {
  if (n == 0) {
    printf("\n");
    return 0;
  }
  printf("%d ", *v);
  return printElementsRecursive(v + 1, n - 1);
}

int sumElementsRecursive(int *v, int n) {
  if (n == 0) {
    return 0;
  }
  return *v + sumElementsRecursive(v + 1, n - 1);
}
