#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[50];
} Student;

void generateCombinations(int k, int start, int n, int v, Student *students, int *indices, const char *excludedName);
void printCombination(int v, Student *students, int *indices);

#endif
