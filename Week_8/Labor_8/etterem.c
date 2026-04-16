#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int time;
} Order;

int cmp(const void *a, const void *b) {
    return ((Order*)a)->time - ((Order*)b)->time;
}

int main() {
    FILE *fin = fopen("lap.in", "r");
    if (!fin) return 0;
    
    int N;
    if (fscanf(fin, "%d", &N) != 1) {
        fclose(fin);
        return 0;
    }
    
    Order *O = (Order*)malloc(N * sizeof(Order));
    for (int i = 0; i < N; i++) {
        fscanf(fin, "%d", &O[i].time);
        O[i].id = i + 1;
    }
    fclose(fin);
    
    qsort(O, N, sizeof(Order), cmp);
    
    long long total = 0;
    long long curr = 0;
    for (int i = 0; i < N; i++) {
        curr += O[i].time;
        total += curr;
    }
    
    FILE *fout = fopen("lap.out", "w");
    if (fout) {
        fprintf(fout, "%.2f\n", (double)total / N);
        for (int i = 0; i < N; i++) {
            fprintf(fout, "%d ", O[i].id);
        }
        fprintf(fout, "\n");
        fclose(fout);
    }
    
    free(O);
    return 0;
}
