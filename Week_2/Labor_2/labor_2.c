#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  printf("Add meg a tomb meretet: ");
  if (scanf("%d", &n) != 1 || n <= 0)
    return 1;

  int *a = (int *)malloc(n * sizeof(int));

  printf("Add meg a tomb elemeit:\n");
  read_array(a, n);

  printf("Tomb elemei: ");
  print_array(a, n);

  int target;
  printf("Keresett elem: ");
  scanf("%d", &target);
  int pos = linearSearch(a, n, target);
  printf("Linearis kereses: %d\n", pos);

  int *sorted = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    sorted[i] = a[i];
  bubble_sort(sorted, n);
  printf("Rendezett tomb: ");
  print_array(sorted, n);

  pos = binarySearch(sorted, n, target);
  printf("Binaris kereses: %d\n", pos);

  int x, y;
  printf("\nAdd meg ket szamot (LNKO/LKKT): ");
  scanf("%d %d", &x, &y);
  printf("LNKO(%d,%d) = %d\n", x, y, lnko(x, y));
  printf("LKKT(%d,%d) = %d\n", x, y, lkkt(x, y));

  int b, e;
  printf("Alap es kitevo (hatvanyozas): ");
  scanf("%d %d", &b, &e);
  printf("%d^%d = %d\n", b, e, power(b, e));

  int *a1 = (int *)malloc(n * sizeof(int));
  int *a2 = (int *)malloc(n * sizeof(int));
  int *a3 = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    a1[i] = a[i];
    a2[i] = a[i];
    a3[i] = a[i];
  }

  selection_sort(a1, n);
  printf("\nSelection sort: ");
  print_array(a1, n);

  minimselection_sort(a2, n);
  printf("Minimselection sort: ");
  print_array(a2, n);

  bubble_sort(a3, n);
  printf("Bubble sort: ");
  print_array(a3, n);

  printf("\nRekurziv fuggvenyek:\n");
  printf("LNKO rekurziv(%d,%d) = %d\n", x, y, lnkoRec(x, y));
  printf("LKKT rekurziv(%d,%d) = %d\n", x, y, lkktRec(x, y, x, y));
  printf("%d^%d rekurziv = %d\n", b, e, powerRec(b, e));

  printf("Tomb kiiras rekurziv: ");
  printArrayRec(a, n);

  printf("Tomb osszeg rekurziv: %d\n", sumArrayRec(a, n));
  printf("Tomb max rekurziv: %d\n", maxArrayRec(a, n, a[0]));
  printf("Tomb LNKO rekurziv: %d\n", lnkoArrayRec(a, n));

  int num;
  printf("\nAdd meg egy szamot (szamjegyek/inverz): ");
  scanf("%d", &num);
  printf("Szamjegyei: ");
  digitsNumberRec(num);
  printf("\n");
  printf("Inverze: %d\n", inverseNumberRec(num, 0));

  printf("\nDivide et Impera:\n");
  printf("Tomb max (div et imp): %d\n", maxArrayDivEtImp(a, 0, n - 1));

  int k;
  printf("\nHanoi tornyai - korongok szama: ");
  scanf("%d", &k);
  Hanoi(k, 1, 3, 2);

  int *ms = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    ms[i] = a[i];
  mergeSort(ms, 0, n - 1);
  printf("\nMerge sort: ");
  print_array(ms, n);

  int *qs = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    qs[i] = a[i];
  quickSort(qs, 0, n - 1);
  printf("Quick sort: ");
  print_array(qs, n);

  pos = binarySearchRecursive(sorted, 0, n - 1, target);
  printf("Binaris kereses rekurziv: %d\n", pos);

  free(a);
  free(sorted);
  free(a1);
  free(a2);
  free(a3);
  free(ms);
  free(qs);

  return 0;
}
