#include "functions.h"
#include <stdio.h>

int main() {
  int a[50][50];
  int n, m;
  
  beolvas_labirintus(a, &n, &m, "labirintus.txt");
  
  if (n == 0 || m == 0) {
    return 1;
  }
  
  Pont ut[2500];
  Pont utmin[2500];
  int kmin = 9999;
  
  int start_x = 0;
  int start_y = 0;
  
  int end_x = n - 1;
  int end_y = m - 1;
  
  backtracking_eger(a, n, m, ut, utmin, &kmin, end_x, end_y, start_x, start_y, 0);
  
  kiir_labirintus(a, n, m);
  printf("\n");
  kiir_utmin(utmin, kmin);
  
  return 0;
}
