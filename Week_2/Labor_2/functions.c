#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

void read_array(int *a, int n) {
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
}

void print_array(int *a, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

int linearSearch(int *array, int size, int target) {
  for (int i = 0; i < size; i++) {
    if (array[i] == target)
      return i;
  }
  return -1;
}

int binarySearch(const int *array, int size, int target) {
  int left = 0, right = size - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (array[mid] == target)
      return mid;
    if (array[mid] < target)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return -1;
}

int lnko(int a, int b) {
  while (b != 0) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int lkkt(int a, int b) { return a / lnko(a, b) * b; }

int power(int b, int e) {
  int result = 1;
  for (int i = 0; i < e; i++) {
    result *= b;
  }
  return result;
}

void selection_sort(int *a, int n) {
  for (int i = 0; i < n - 1; i++) {
    int maxIdx = 0;
    for (int j = 1; j < n - i; j++) {
      if (a[j] > a[maxIdx])
        maxIdx = j;
    }
    int tmp = a[maxIdx];
    a[maxIdx] = a[n - 1 - i];
    a[n - 1 - i] = tmp;
  }
}

void minimselection_sort(int *a, int n) {
  for (int i = 0; i < n - 1; i++) {
    int minIdx = i;
    for (int j = i + 1; j < n; j++) {
      if (a[j] < a[minIdx])
        minIdx = j;
    }
    int tmp = a[i];
    a[i] = a[minIdx];
    a[minIdx] = tmp;
  }
}

void bubble_sort(int *a, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1 - i; j++) {
      if (a[j] > a[j + 1]) {
        int tmp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = tmp;
      }
    }
  }
}

int lnkoRec(int a, int b) {
  if (b == 0)
    return a;
  return lnkoRec(b, a % b);
}

int lkktRec(int a, int b, int a1, int b1) { return a1 / lnkoRec(a, b) * b1; }

int powerRec(int b, int e) {
  if (e == 0)
    return 1;
  return b * powerRec(b, e - 1);
}

void readArrayRec(int *a, int n, FILE *f) {
  if (n <= 0)
    return;
  fscanf(f, "%d", a);
  readArrayRec(a + 1, n - 1, f);
}

void printArrayRec(int *a, int n) {
  if (n <= 0) {
    printf("\n");
    return;
  }
  printf("%d ", *a);
  printArrayRec(a + 1, n - 1);
}

int sumArrayRec(int *a, int n) {
  if (n <= 0)
    return 0;
  return *a + sumArrayRec(a + 1, n - 1);
}

int maxArrayRec(int *a, int n, int max) {
  if (n <= 0)
    return max;
  if (*a > max)
    max = *a;
  return maxArrayRec(a + 1, n - 1, max);
}

int lnkoArrayRec(int *a, int n) {
  if (n == 1)
    return a[0];
  return lnkoRec(a[0], lnkoArrayRec(a + 1, n - 1));
}

void digitsNumberRec(int n) {
  if (n < 0)
    n = -n;
  if (n < 10) {
    printf("%d ", n);
    return;
  }
  digitsNumberRec(n / 10);
  printf("%d ", n % 10);
}

int inverseNumberRec(int n, int fn) {
  if (n == 0)
    return fn;
  return inverseNumberRec(n / 10, fn * 10 + n % 10);
}

int maxArrayDivEtImp(int *a, int i, int j) {
  if (i == j)
    return a[i];
  int mid = (i + j) / 2;
  int maxLeft = maxArrayDivEtImp(a, i, mid);
  int maxRight = maxArrayDivEtImp(a, mid + 1, j);
  return (maxLeft > maxRight) ? maxLeft : maxRight;
}

void Hanoi(int k, int s, int d, int h) {
  if (k == 1) {
    printf("%d -> %d\n", s, d);
    return;
  }
  Hanoi(k - 1, s, h, d);
  printf("%d -> %d\n", s, d);
  Hanoi(k - 1, h, d, s);
}

static void merge(int *a, int i, int mid, int j) {
  int n1 = mid - i + 1;
  int n2 = j - mid;
  int *L = (int *)malloc(n1 * sizeof(int));
  int *R = (int *)malloc(n2 * sizeof(int));
  for (int k = 0; k < n1; k++)
    L[k] = a[i + k];
  for (int k = 0; k < n2; k++)
    R[k] = a[mid + 1 + k];
  int p = 0, q = 0, k = i;
  while (p < n1 && q < n2) {
    if (L[p] <= R[q])
      a[k++] = L[p++];
    else
      a[k++] = R[q++];
  }
  while (p < n1)
    a[k++] = L[p++];
  while (q < n2)
    a[k++] = R[q++];
  free(L);
  free(R);
}

void mergeSort(int *a, int i, int j) {
  if (i >= j)
    return;
  int mid = (i + j) / 2;
  mergeSort(a, i, mid);
  mergeSort(a, mid + 1, j);
  merge(a, i, mid, j);
}

void quickSort(int *a, int i, int j) {
  if (i >= j)
    return;
  int pivot = a[j];
  int left = i, right = j - 1;
  while (left <= right) {
    while (left <= right && a[left] <= pivot)
      left++;
    while (left <= right && a[right] >= pivot)
      right--;
    if (left < right) {
      int tmp = a[left];
      a[left] = a[right];
      a[right] = tmp;
    }
  }
  int tmp = a[left];
  a[left] = a[j];
  a[j] = tmp;
  quickSort(a, i, left - 1);
  quickSort(a, left + 1, j);
}

int binarySearchRecursive(const int *array, int left, int right, int target) {
  if (left > right)
    return -1;
  int mid = left + (right - left) / 2;
  if (array[mid] == target)
    return mid;
  if (array[mid] < target)
    return binarySearchRecursive(array, mid + 1, right, target);
  return binarySearchRecursive(array, left, mid - 1, target);
}
