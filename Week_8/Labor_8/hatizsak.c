#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K;
    if (scanf("%d %d", &N, &K) != 2) return 0;
    
    int *V = (int*)malloc(N * sizeof(int));
    int *W = (int*)malloc(N * sizeof(int));
    
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &V[i], &W[i]);
    }
    
    int *dp = (int*)calloc(K + 1, sizeof(int));
    
    for (int i = 0; i < N; i++) {
        for (int j = K; j >= V[i]; j--) {
            if (dp[j - V[i]] + W[i] > dp[j]) {
                dp[j] = dp[j - V[i]] + W[i];
            }
        }
    }
    
    printf("%d\n", dp[K]);
    
    free(V);
    free(W);
    free(dp);
    return 0;
}
