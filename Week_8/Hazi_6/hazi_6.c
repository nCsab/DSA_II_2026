#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int time;
} Auto;

int cmp(const void *a, const void *b) {
    return ((Auto*)a)->time - ((Auto*)b)->time;
}

int main() {
    FILE *fin = fopen("auto.in", "r");
    if (!fin) return 0;

    int n, T;
    if (fscanf(fin, "%d %d", &n, &T) != 2) {
        fclose(fin);
        return 0;
    }

    Auto *a = (Auto*)malloc(n * sizeof(Auto));
    for (int i = 0; i < n; i++) {
        fscanf(fin, "%d", &a[i].time);
        a[i].id = i + 1;
    }
    fclose(fin);

    qsort(a, n, sizeof(Auto), cmp);

    int count = 0;
    int *selected = (int*)malloc(n * sizeof(int));
    int total_time = 0;

    for (int i = 0; i < n; i++) {
        if (total_time + a[i].time <= T) {
            total_time += a[i].time;
            selected[count++] = a[i].id;
        } else {
            break;
        }
    }

    FILE *fout = fopen("auto.out", "w");
    if (fout) {
        fprintf(fout, "%d\n", count);
        for (int i = 0; i < count; i++) {
            fprintf(fout, "%d ", selected[i]);
        }
        fprintf(fout, "\n");
        fclose(fout);
    }

    free(a);
    free(selected);
    return 0;
}
