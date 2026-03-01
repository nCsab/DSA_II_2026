#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>

void read_array(int *a, int n);
void print_array(int *a, int n);
int linearSearch(int *array, int size, int target);
int binarySearch(const int *array, int size, int target);
int lnko(int a, int b);
int lkkt(int a, int b);
int power(int b, int e);
void selection_sort(int *a, int n);
void minimselection_sort(int *a, int n);
void bubble_sort(int *a, int n);

int lnkoRec(int a, int b);
int lkktRec(int a, int b, int a1, int b1);
int powerRec(int b, int e);
void readArrayRec(int *a, int n, FILE *f);
void printArrayRec(int *a, int n);
int sumArrayRec(int *a, int n);
int maxArrayRec(int *a, int n, int max);
int lnkoArrayRec(int *a, int n);
void digitsNumberRec(int n);
int inverseNumberRec(int n, int fn);

int maxArrayDivEtImp(int *a, int i, int j);
void Hanoi(int k, int s, int d, int h);
void mergeSort(int *a, int i, int j);
void quickSort(int *a, int i, int j);
int binarySearchRecursive(const int *array, int left, int right, int target);

#endif
