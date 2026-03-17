#include "functions.h"

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n < 1) {
        return 1;
    }

    int *a = (int *)malloc(n * sizeof(int));
    if (!a) {
        return 1;
    }

    readArray(a, n);
    quickSort(a, 0, n - 1);
    printArray(a, n);

    free(a);
    return 0;
}
