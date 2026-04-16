#include "functions.h"
#include <stdio.h>

void masol(Pont utmin[], Pont ut[], int k, int *kmin) {
  *kmin = k;
  for (int i = 0; i <= k; i++) {
    utmin[i] = ut[i];
  }
}

void backtracking_eger(int a[][50], int n, int m,
                       Pont ut[], Pont utmin[], int *kmin,
                       int xs, int ys, int x, int y, int k) {
  ut[k].x = x;
  ut[k].y = y;

  if (x == xs && y == ys) {
    if (k < *kmin) {
      masol(utmin, ut, k, kmin);
    }
    return;
  }

  a[x][y] = 1;

  if (x - 1 >= 0 && a[x - 1][y] == 0) {
    backtracking_eger(a, n, m, ut, utmin, kmin, xs, ys, x - 1, y, k + 1);
  }
  if (y + 1 < m && a[x][y + 1] == 0) {
    backtracking_eger(a, n, m, ut, utmin, kmin, xs, ys, x, y + 1, k + 1);
  }
  if (x + 1 < n && a[x + 1][y] == 0) {
    backtracking_eger(a, n, m, ut, utmin, kmin, xs, ys, x + 1, y, k + 1);
  }
  if (y - 1 >= 0 && a[x][y - 1] == 0) {
    backtracking_eger(a, n, m, ut, utmin, kmin, xs, ys, x, y - 1, k + 1);
  }
  
  a[x][y] = 0;
}

void beolvas_labirintus(int a[][50], int *n, int *m, const char *input) {
  FILE *f = fopen(input, "r");
  if (!f) return;
  
  if (fscanf(f, "%d %d", n, m) != 2) {
    fclose(f);
    return;
  }
  
  for (int i = 0; i < *n; i++) {
    for (int j = 0; j < *m; j++) {
      fscanf(f, "%d", &a[i][j]);
    }
  }
  
  fclose(f);
}

void kiir_labirintus(int a[][50], int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
}

void kiir_utmin(Pont utmin[], int kmin) {
  if (kmin == 9999) {
    printf("Nincs ut!\n");
    return;
  }
  printf("Legrovidebb ut (%d lepes):\n", kmin);
  for (int i = 0; i <= kmin; i++) {
    printf("(%d, %d)\n", utmin[i].x, utmin[i].y);
  }
}
