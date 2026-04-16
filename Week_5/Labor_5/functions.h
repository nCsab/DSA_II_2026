#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct {
  int x, y;
} Pont;

void masol(Pont utmin[], Pont ut[], int k, int *kmin);

void backtracking_eger(int a[][50], int n, int m,
                       Pont ut[], Pont utmin[], int *kmin,
                       int xs, int ys, int x, int y, int k);

void beolvas_labirintus(int a[][50], int *n, int *m, const char *input);

void kiir_labirintus(int a[][50], int n, int m);

void kiir_utmin(Pont utmin[], int kmin);

#endif
