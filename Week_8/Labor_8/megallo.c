#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fin = fopen("megallo.in", "r");
    if (!fin) return 0;
    
    int N;
    long long X;
    if (fscanf(fin, "%d %lld", &N, &X) != 2) {
        fclose(fin);
        return 0;
    }
    
    long long *d = (long long*)malloc(N * sizeof(long long));
    for (int i = 0; i < N; i++) {
        fscanf(fin, "%lld", &d[i]);
    }
    fclose(fin);
    
    int *stops = (int*)malloc((N + 1) * sizeof(int));
    int count = 0;
    
    stops[count++] = 1;
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += d[i];
        if (sum >= X) {
            stops[count++] = i + 2;
            sum = 0;
        }
    }
    
    FILE *fout = fopen("megallo.out", "w");
    if (fout) {
        fprintf(fout, "%d\n", count);
        for (int i = 0; i < count; i++) {
            fprintf(fout, "%d ", stops[i]);
        }
        fprintf(fout, "\n");
        fclose(fout);
    }
    
    free(d);
    free(stops);
    return 0;
}
