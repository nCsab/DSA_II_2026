#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

void BTd_bicycle(int x[], int n, int k) {
  for (int i = 0; i <= 9; i++) {
    x[k] = i;
    if (k < n) {
      BTd_bicycle(x, n, k + 1);
    } else {
      for (int pass = 1; pass <= n; pass++) {
        printf("%d ", x[pass]);
      }
      printf("\n");
    }
  }
}

void BTd_cartesian(int x[], int n, int k) {
  for (int i = 1; i <= n; i++) {
    x[k] = i;
    if (k < n) {
      BTd_cartesian(x, n, k + 1);
    } else {
      for (int pass = 1; pass <= n; pass++) {
        printf("%d ", x[pass]);
      }
      printf("\n");
    }
  }
}

int igeretes_perm(int x[], int k) {
  for (int i = 1; i <= k - 1; i++) {
    if (x[i] == x[k]) {
      return 0;
    }
  }
  return 1;
}

void BTp(int x[], int n, int k) {
  for (int i = 1; i <= n; i++) {
    x[k] = i;
    if (igeretes_perm(x, k)) {
      if (k < n) {
        BTp(x, n, k + 1);
      } else {
        for (int pass = 1; pass <= n; pass++) {
          printf("%d ", x[pass]);
        }
        printf("\n");
      }
    }
  }
}

int igeretes_kiralyno(int x[], int k) {
  for (int i = 1; i <= k - 1; i++) {
    if (x[i] == x[k] || (k - i) == abs(x[k] - x[i])) {
      return 0;
    }
  }
  return 1;
}

void BTkiralyno(int x[], int n, int k) {
  for (int i = 1; i <= n; i++) {
    x[k] = i;
    if (igeretes_kiralyno(x, k)) {
      if (k < n) {
        BTkiralyno(x, n, k + 1);
      } else {
        for (int pass = 1; pass <= n; pass++) {
          printf("%d ", x[pass]);
        }
        printf("\n");
      }
    }
  }
}
