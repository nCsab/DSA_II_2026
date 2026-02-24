#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void readElementsRecursive(int *v, int n);
void printElementsRecursive(int *v, int n);
int sumElementsRecursive(int *v, int n);
int minElementRecursive(int *v, int n);
int countPositiveElementsRecursive(int *v, int n);
int prodDigitsNumber(int e);
int minDigitNumber(int e);
void reverseDigitsRecursive(int e);
void readMatrixRecursive(int **matrix, int rows, int cols, int currentRow,
                         int currentCol);
void printMatrixRecursive(int **matrix, int rows, int cols, int currentRow,
                          int currentCol);
int sumMatrixRowsRecursive(int **matrix, int cols, int currentRow,
                           int currentCol);
int sumMatrixColsRecursive(int **matrix, int rows, int currentRow,
                           int currentCol);
int sumMainDiagonalRecursive(int **matrix, int size, int currentIndex);
int sumSecondaryDiagonalRecursive(int **matrix, int size, int currentIndex);
int sumMatrixElementsRecursive(int **matrix, int rows, int cols, int currentRow,
                               int currentCol);
int maxMatrixElementsRecursive(int **matrix, int rows, int cols, int currentRow,
                               int currentCol);
int minMatrixElementsRecursive(int **matrix, int rows, int cols, int currentRow,
                               int currentCol);
int countPositiveMatrixElementsRecursive(int **matrix, int rows, int cols,
                                         int currentRow, int currentCol);

#endif
