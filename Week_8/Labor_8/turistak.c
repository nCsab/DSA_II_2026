#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a) - (*(int*)b);
}

int main() {
    FILE *fin = fopen("turista.in", "r");
    if (!fin) return 0;
    
    int K, N, M, P;
    if (fscanf(fin, "%d %d %d %d", &K, &N, &M, &P) != 4) {
        fclose(fin);
        return 0;
    }
    
    int *req = (int*)malloc(P * sizeof(int));
    for (int i = 0; i < P; i++) {
        fscanf(fin, "%d", &req[i]);
    }
    fclose(fin);
    
    qsort(req, P, sizeof(int), cmp);
    
    int *guides = (int*)calloc(N, sizeof(int));
    int count = 0;
    
    for (int i = 0; i < P; i++) {
        int assigned = -1;
        for (int j = 0; j < N; j++) {
            if (guides[j] <= req[i]) {
                if (assigned == -1 || guides[j] > guides[assigned]) {
                    assigned = j;
                }
            }
        }
        if (assigned != -1) {
            guides[assigned] = req[i] + M;
            count++;
        }
    }
    
    FILE *fout = fopen("turista.out", "w");
    if (fout) {
        fprintf(fout, "%d\n", count);
        fclose(fout);
    }
    
    free(req);
    free(guides);
    return 0;
}
