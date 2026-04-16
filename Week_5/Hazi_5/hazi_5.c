#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(char *)a - *(char *)b;
}

void solve(int k, int n, char *word, char *result, int *used) {
    if (k == n) {
        result[n] = '\0';
        printf("%s\n", result);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        if (i > 0 && word[i] == word[i - 1] && !used[i - 1]) continue;

        used[i] = 1;
        result[k] = word[i];
        solve(k + 1, n, word, result, used);
        used[i] = 0;
    }
}

int main() {
    char word[100];
    if (scanf("%s", word) != 1) return 0;

    int n = strlen(word);
    qsort(word, n, sizeof(char), compare);

    char *result = malloc((n + 1) * sizeof(char));
    int *used = calloc(n, sizeof(int));

    if (result && used) {
        solve(0, n, word, result, used);
    }

    free(result);
    free(used);

    return 0;
}
