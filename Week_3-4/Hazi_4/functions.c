#include "functions.h"

void generateCombinations(int k, int start, int n, int v, Student *students, int *indices, const char *excludedName) {
    if (k == v) {
        printCombination(v, students, indices);
        return;
    }

    for (int i = start; i < n; i++) {
        if (strcmp(students[i].name, excludedName) == 0) {
            continue;
        }

        indices[k] = i;
        generateCombinations(k + 1, i + 1, n, v, students, indices, excludedName);
    }
}

void printCombination(int v, Student *students, int *indices) {
    printf("{");
    for (int i = 0; i < v; i++) {
        printf("%s%s", students[indices[i]].name, (i < v - 1) ? ", " : "");
    }
    printf("}\n");
}
