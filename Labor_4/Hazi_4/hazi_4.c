#include "functions.h"

int main() {
    int n, v;
    char excludedName[50];

    printf("Adja meg a diakok osszes szamat (n): ");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Ervenytelen bemenet.\n");
        return 1;
    }

    printf("Adja meg a kivalasztando diakok szamat (v): ");
    if (scanf("%d", &v) != 1 || v < 0 || v > n) {
        printf("Ervenytelen bemenet.\n");
        return 1;
    }

    Student *students = (Student *)malloc(n * sizeof(Student));
    if (!students) {
        printf("Memoriafoglalasi hiba.\n");
        return 1;
    }

    printf("Adja meg a diakok neveit:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. diak neve: ", i + 1);
        scanf("%s", students[i].name);
    }

    printf("Adja meg a diakot, aki sosem szerepelhet (tiltott nev): ");
    scanf("%s", excludedName);

    int eligibleCount = 0;
    for(int i = 0; i < n; i++) {
        if(strcmp(students[i].name, excludedName) != 0) {
            eligibleCount++;
        }
    }

    if (eligibleCount < v) {
        printf("\nNincs elegendo diak (%d eligible) a v=%d darabos csapat osszeallitasahoz a tiltas mellett.\n", eligibleCount, v);
    } else {
        int *indices = (int *)malloc(v * sizeof(int));
        if (!indices) {
            free(students);
            return 1;
        }

        printf("\nLehetseges %d darabos kombinaciok (kizárva: %s):\n", v, excludedName);
        generateCombinations(0, 0, n, v, students, indices, excludedName);
        
        free(indices);
    }

    free(students);
    return 0;
}
