#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Size of Array: ");
    if(scanf("%d", &n) != 1 || n <= 0) return 1;

    int *v = (int *)malloc(n * sizeof(int));
    printf("Enter the elements the array: ");
    readElementsRecursive(v, n);
    



    return 0; 
}