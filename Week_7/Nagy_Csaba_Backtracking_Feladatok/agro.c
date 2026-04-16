/* Egy agrármérnök egy 5x5-ös mezőgazdasági parcellahálózaton dolgozik.
A (0,0) pozícióból indul és feladatokat kell elvégeznie a parcellák
bejárása során. A mátrixban 0 jelöli a szabad mezőt, -1 az akadályt,
az 1, 2, 3 számok pedig feladatokat jelölnek, amelyeket szigorú
sorrendben kell teljesíteni (az 1-es feladatot előbb, mint a 2-est,
a 2-est előbb, mint a 3-ast). Az agrármérnök célja, hogy a legrövidebb
úton bejárja az összes feladatot sorrendben, majd megkapja a kiutat. A
program a 3-as feladat elvégzése után tekinti. */

#include <stdio.h>
#include <string.h>

#define N 5
#define TASKS 3
#define INF 999999

int P[N][N] = {{0, 0, 0, -1, 0},
               {0, -1, 1, 0, 0},
               {0, -1, 0, -1, 2},
               {0, 0, 0, -1, 0},
               {-1, -1, 0, 0, 3}};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int bestLen;
int bestPath[N * N * (TASKS + 1)][2];
int bestPathLen;

int path[N * N * (TASKS + 1)][2];
int visited[N][N];

void solve(int x, int y, int nextTask, int len) {
  if (nextTask > TASKS) {
    if (len < bestLen) {
      bestLen = len;
      bestPathLen = len;
      for (int i = 0; i < len; i++) {
        bestPath[i][0] = path[i][0];
        bestPath[i][1] = path[i][1];
      }
    }
    return;
  }

  if (len >= bestLen)
    return;

  for (int d = 0; d < 4; d++) {
    int nx = x + dx[d];
    int ny = y + dy[d];

    if (nx < 0 || ny < 0 || nx >= N || ny >= N)
      continue;
    if (P[nx][ny] == -1)
      continue;
    if (visited[nx][ny])
      continue;

    if (P[nx][ny] > 0 && P[nx][ny] != nextTask)
      if (P[nx][ny] > nextTask)
        continue;

    int newTask = nextTask;
    if (P[nx][ny] == nextTask)
      newTask = nextTask + 1;

    visited[nx][ny] = 1;
    path[len][0] = nx;
    path[len][1] = ny;

    solve(nx, ny, newTask, len + 1);

    visited[nx][ny] = 0;
  }
}

int main() {
  printf("Legrovidebb ut keresese a feladatok sorrendjeben:\n\n");

  memset(visited, 0, sizeof(visited));
  bestLen = INF;
  bestPathLen = 0;

  visited[0][0] = 1;
  path[0][0] = 0;
  path[0][1] = 0;

  int startTask = 1;
  if (P[0][0] == 1)
    startTask = 2;

  solve(0, 0, startTask, 1);

  if (bestLen == INF) {
    printf("Nincs megoldas!\n");
  } else {
    printf("Legrovidebb ut hossza: %d lepes\n", bestPathLen - 1);
    printf("Utvonal:\n");
    for (int i = 0; i < bestPathLen; i++) {
      int x = bestPath[i][0];
      int y = bestPath[i][1];
      if (P[x][y] > 0 && P[x][y] <= TASKS)
        printf("  (%d,%d) <- Feladat %d\n", x, y, P[x][y]);
      else
        printf("  (%d,%d)\n", x, y);
    }
  }

  printf("\n");
  return 0;
}
