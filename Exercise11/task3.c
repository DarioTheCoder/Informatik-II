
#include <stdio.h>

const int INF = 1000000;

int max(int x, int y) {
    if (x > y)
        return x;
    return y;
}

int max_value(int n, int w[], int v[], int W) {
    // w[1...n], v[1...n]
    int dp[n+1][W+1];

    for (int i=0; i<=n; i++){
        for (int j=0; j<=W; j++){
            dp[i][j] = -INF;
        }
    }
    dp[0][0] = 0;
    for (int i=1; i<=n; i++){
        for (int j=0; j<=W; j++){
            if (j < w[i]){
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], v[i]+dp[i-1][j-w[i]]);
            }               
        }
    }
    int final_answer = 0;
    for (int i = 0; i<=W; i++){
        final_answer = max(final_answer, dp[n][i]);
    }
    return final_answer;
}

int main() {
    int n = 5, w[] = {0, 2, 4, 5, 3, 9}, v[] = {0, 3, 5, 8, 4, 10}, W = 20;
    printf("%d", max_value(n, w, v, W));
    return 0;
}