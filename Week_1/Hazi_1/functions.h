#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void readMatrixRecursive(int **matrix, int rows, int cols, int currentRow,
                         int currentCol);
void printMatrixRecursive(int **matrix, int rows, int cols, int currentRow,
                          int currentCol);
int isThreeDigitMirror(int x);
void printThreeDigitMirrorsByRowRecursive(int **matrix, int rows, int cols,
                                          int currentRow, int currentCol);

#endif
