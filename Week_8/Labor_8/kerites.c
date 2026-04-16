#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K;
    if (scanf("%d %d", &N, &K) != 2) return 0;
    
    int *d = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &d[i]);
    }

    int *kept = (int*)calloc(N, sizeof(int));
    kept[0] = 1;
    int last_kept = 0;
    
    for (int i = 1; i < N;) {
        int best = -1;
        for (int j = last_kept + 1; j < N && d[j] - d[last_kept] <= K; j++) {
            best = j;
        }
        if (best == -1) break;
        kept[best] = 1;
        last_kept = best;
        i = best + 1;
    }

    int removed_count = 0;
    for (int i = 0; i < N; i++) {
        if (!kept[i]) {
            removed_count++;
        }
    }

    printf("%d\n", removed_count);
    for (int i = 0; i < N; i++) {
        if (!kept[i]) {
            printf("%d ", i + 1);
        }
    }
    printf("\n");

    free(d);
    free(kept);
    return 0;
}
