#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x, y;
} Point;

double dist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    FILE *fin = fopen("halozat.in", "r");
    if (!fin) return 0;
    
    int N;
    if (fscanf(fin, "%d", &N) != 1) {
        fclose(fin);
        return 0;
    }
    
    Point *pts = (Point*)malloc(N * sizeof(Point));
    for (int i = 0; i < N; i++) {
        fscanf(fin, "%lf %lf", &pts[i].x, &pts[i].y);
    }
    fclose(fin);
    
    int *visited = (int*)calloc(N, sizeof(int));
    double *min_e = (double*)malloc(N * sizeof(double));
    for (int i = 0; i < N; i++) {
        min_e[i] = 1e9;
    }
    
    double total = 0;
    min_e[0] = 0;
    
    for (int i = 0; i < N; i++) {
        int v = -1;
        for (int j = 0; j < N; j++) {
            if (!visited[j] && (v == -1 || min_e[j] < min_e[v])) {
                v = j;
            }
        }
        
        if (min_e[v] == 1e9) break;
        
        visited[v] = 1;
        total += min_e[v];
        
        for (int j = 0; j < N; j++) {
            if (!visited[j]) {
                double d = dist(pts[v], pts[j]);
                if (d < min_e[j]) {
                    min_e[j] = d;
                }
            }
        }
    }
    
    FILE *fout = fopen("halozat.out", "w");
    if (fout) {
        fprintf(fout, "%.2f\n", total);
        fclose(fout);
    }
    
    free(pts);
    free(visited);
    free(min_e);
    return 0;
}
