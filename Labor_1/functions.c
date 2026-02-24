#include "functions.h"
#include <stdio.h>

void readElementsRecursive(int *v, int n) {
  if (n <= 0)
    return;
  scanf("%d", v);
  readElementsRecursive(v + 1, n - 1);
}

void printElementsRecursive(int *v, int n) {
  if (n <= 0) {
    printf("\n");
    return;
  }
  printf("%d ", *v);
  printElementsRecursive(v + 1, n - 1);
}

int sumElementsRecursive(int *v, int n) {
  if (n <= 0)
    return 0;
  return *v + sumElementsRecursive(v + 1, n - 1);
}

int minElementRecursive(int *v, int n) {
  if (n == 1)
    return *v;
  int minRest = minElementRecursive(v + 1, n - 1);
  return (*v < minRest) ? *v : minRest;
}

int countPositiveElementsRecursive(int *v, int n) {
  if (n <= 0)
    return 0;
  return (*v > 0 ? 1 : 0) + countPositiveElementsRecursive(v + 1, n - 1);
}

int prodDigitsNumber(int e) {
  if (e < 0)
    e = -e;
  if (e < 10)
    return e;
  return (e % 10) * prodDigitsNumber(e / 10);
}

int minDigitNumber(int e) {
  if (e < 0)
    e = -e;
  if (e < 10)
    return e;
  int minRest = minDigitNumber(e / 10);
  int current = e % 10;
  return (current < minRest) ? current : minRest;
}

void reverseDigitsRecursive(int e) {
  if (e < 0) {
    printf("-");
    e = -e;
  }
  if (e < 10) {
    printf("%d", e);
    return;
  }
  printf("%d", e % 10);
  reverseDigitsRecursive(e / 10);
}

void readMatrixRecursive(int **matrix, int rows, int cols, int currentRow,
                         int currentCol) {
  if (currentRow >= rows)
    return;
  if (currentCol >= cols) {
    readMatrixRecursive(matrix, rows, cols, currentRow + 1, 0);
    return;
  }
  scanf("%d", &matrix[currentRow][currentCol]);
  readMatrixRecursive(matrix, rows, cols, currentRow, currentCol + 1);
}

void printMatrixRecursive(int **matrix, int rows, int cols, int currentRow,
                          int currentCol) {
  if (currentRow >= rows)
    return;
  if (currentCol >= cols) {
    printf("\n");
    printMatrixRecursive(matrix, rows, cols, currentRow + 1, 0);
    return;
  }
  printf("%d ", matrix[currentRow][currentCol]);
  printMatrixRecursive(matrix, rows, cols, currentRow, currentCol + 1);
}

int sumMatrixRowsRecursive(int **matrix, int cols, int currentRow,
                           int currentCol) {
  if (currentCol >= cols)
    return 0;
  return matrix[currentRow][currentCol] +
         sumMatrixRowsRecursive(matrix, cols, currentRow, currentCol + 1);
}

int sumMatrixColsRecursive(int **matrix, int rows, int currentRow,
                           int currentCol) {
  if (currentRow >= rows)
    return 0;
  return matrix[currentRow][currentCol] +
         sumMatrixColsRecursive(matrix, rows, currentRow + 1, currentCol);
}

int sumMainDiagonalRecursive(int **matrix, int size, int currentIndex) {
  if (currentIndex >= size)
    return 0;
  return matrix[currentIndex][currentIndex] +
         sumMainDiagonalRecursive(matrix, size, currentIndex + 1);
}

int sumSecondaryDiagonalRecursive(int **matrix, int size, int currentIndex) {
  if (currentIndex >= size)
    return 0;
  return matrix[currentIndex][size - 1 - currentIndex] +
         sumSecondaryDiagonalRecursive(matrix, size, currentIndex + 1);
}

int sumMatrixElementsRecursive(int **matrix, int rows, int cols, int currentRow,
                               int currentCol) {
  if (currentRow >= rows)
    return 0;
  if (currentCol >= cols) {
    return sumMatrixElementsRecursive(matrix, rows, cols, currentRow + 1, 0);
  }
  return matrix[currentRow][currentCol] +
         sumMatrixElementsRecursive(matrix, rows, cols, currentRow,
                                    currentCol + 1);
}

int maxMatrixElementsRecursive(int **matrix, int rows, int cols, int currentRow,
                               int currentCol) {
  if (currentRow == rows - 1 && currentCol == cols - 1) {
    return matrix[currentRow][currentCol];
  }
  int maxRest;
  if (currentCol == cols - 1) {
    maxRest = maxMatrixElementsRecursive(matrix, rows, cols, currentRow + 1, 0);
  } else {
    maxRest = maxMatrixElementsRecursive(matrix, rows, cols, currentRow,
                                         currentCol + 1);
  }
  return (matrix[currentRow][currentCol] > maxRest)
             ? matrix[currentRow][currentCol]
             : maxRest;
}

int minMatrixElementsRecursive(int **matrix, int rows, int cols, int currentRow,
                               int currentCol) {
  if (currentRow == rows - 1 && currentCol == cols - 1) {
    return matrix[currentRow][currentCol];
  }
  int minRest;
  if (currentCol == cols - 1) {
    minRest = minMatrixElementsRecursive(matrix, rows, cols, currentRow + 1, 0);
  } else {
    minRest = minMatrixElementsRecursive(matrix, rows, cols, currentRow,
                                         currentCol + 1);
  }
  return (matrix[currentRow][currentCol] < minRest)
             ? matrix[currentRow][currentCol]
             : minRest;
}

int countPositiveMatrixElementsRecursive(int **matrix, int rows, int cols,
                                         int currentRow, int currentCol) {
  if (currentRow >= rows)
    return 0;
  if (currentCol >= cols) {
    return countPositiveMatrixElementsRecursive(matrix, rows, cols,
                                                currentRow + 1, 0);
  }
  int count = (matrix[currentRow][currentCol] > 0) ? 1 : 0;
  return count + countPositiveMatrixElementsRecursive(
                     matrix, rows, cols, currentRow, currentCol + 1);
}
