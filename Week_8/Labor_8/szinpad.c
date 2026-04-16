#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int start;
    int end;
} Band;

int cmp(const void *a, const void *b) {
    return ((Band*)a)->end - ((Band*)b)->end;
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;
    
    Band *B = (Band*)malloc(N * sizeof(Band));
    for (int i = 0; i < N; i++) {
        int h1, m1, h2, m2;
        if (scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2) != 4) continue;
        B[i].id = i + 1;
        B[i].start = h1 * 60 + m1;
        B[i].end = h2 * 60 + m2;
    }

    qsort(B, N, sizeof(Band), cmp);

    int count = 0;
    int *selected = (int*)malloc(N * sizeof(int));
    int last_end = -1;

    for (int i = 0; i < N; i++) {
        if (B[i].start >= last_end) {
            selected[count++] = B[i].id;
            last_end = B[i].end;
        }
    }

    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d ", selected[i]);
    }
    printf("\n");

    free(B);
    free(selected);
    return 0;
}
