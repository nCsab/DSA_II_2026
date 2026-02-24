#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  printf("Add meg a tomb meretet: ");
  if (scanf("%d", &n) != 1 || n <= 0)
    return 1;

  int *v = (int *)malloc(n * sizeof(int));
  printf("Add meg a tomb elemeit: \n");
  readElementsRecursive(v, n);

  printf("Tomb elemei: ");
  printElementsRecursive(v, n);

  printf("Elemek osszege: %d\n", sumElementsRecursive(v, n));
  printf("Legkisebb elem: %d\n", minElementRecursive(v, n));
  printf("Pozitiv elemek szama: %d\n", countPositiveElementsRecursive(v, n));

  int e;
  printf("\nAdd meg egy szamot: ");
  if (scanf("%d", &e) == 1) {
    printf("Szamjegyek szorzata: %d\n", prodDigitsNumber(e));
    printf("Legkisebb szamjegy: %d\n", minDigitNumber(e));
    printf("Szamjegyek forditva: ");
    reverseDigitsRecursive(e);
    printf("\n");
  }

  int rows, cols;
  printf("\nAdd meg a matrix sorainak es oszlopainak szamat: ");
  if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0) {
    free(v);
    return 1;
  }

  int **matrix = (int **)malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    matrix[i] = (int *)malloc(cols * sizeof(int));
  }

  printf("Add meg a matrix elemeit: \n");
  readMatrixRecursive(matrix, rows, cols, 0, 0);

  printf("Matrix elemei: \n");
  printMatrixRecursive(matrix, rows, cols, 0, 0);

  for (int i = 0; i < rows; i++) {
    printf("%d. sor osszege: %d\n", i + 1,
           sumMatrixRowsRecursive(matrix, cols, i, 0));
  }

  for (int j = 0; j < cols; j++) {
    printf("%d. oszlop osszege: %d\n", j + 1,
           sumMatrixColsRecursive(matrix, rows, 0, j));
  }

  int size = (rows < cols) ? rows : cols;
  printf("Foatlo osszege: %d\n", sumMainDiagonalRecursive(matrix, size, 0));
  printf("Mellekatlo osszege: %d\n",
         sumSecondaryDiagonalRecursive(matrix, size, 0));

  printf("Matrix elemeinek osszege: %d\n",
         sumMatrixElementsRecursive(matrix, rows, cols, 0, 0));
  printf("Matrix legnagyobb eleme: %d\n",
         maxMatrixElementsRecursive(matrix, rows, cols, 0, 0));
  printf("Matrix legkisebb eleme: %d\n",
         minMatrixElementsRecursive(matrix, rows, cols, 0, 0));
  printf("Matrix pozitiv elemeinek szama: %d\n",
         countPositiveMatrixElementsRecursive(matrix, rows, cols, 0, 0));

  free(v);
  for (int i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  free(matrix);

  return 0;
}
