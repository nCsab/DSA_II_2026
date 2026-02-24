#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int rows, cols;

  printf("Add meg a matrix sorainak es oszlopainak szamat: ");
  if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0) {
    return 1;
  }

  int **matrix = (int **)malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    matrix[i] = (int *)malloc(cols * sizeof(int));
  }

  printf("Add meg a matrix elemeit:\n");
  readMatrixRecursive(matrix, rows, cols, 0, 0);

  printf("Matrix elemei:\n");
  printMatrixRecursive(matrix, rows, cols, 0, 0);

  printf("Haromszamjegyu tukorszamok soronkent:\n");
  printThreeDigitMirrorsByRowRecursive(matrix, rows, cols, 0, 0);

  for (int i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  free(matrix);

  return 0;
}
