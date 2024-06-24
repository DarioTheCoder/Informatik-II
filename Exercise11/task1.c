#include <stdio.h>


int max(int x, int y){
    if (x > y){
        return x;
    }
    return y;
}

int longest_seq(int n, int array[]){
    int dp[n+1];

    for (int i=1; i<=n; i++){
        int max_subproblem = 0;
        for (int j=1; j<i;j++){
            if (array[j] <= array[i]){
                max_subproblem = max(max_subproblem, dp[j]);
            }
        }

        if (max_subproblem == 0){
            dp[i] = 1;
        } else {
            dp[i] = max_subproblem + 1;
        }

        
    }
    int res = 0;
    for (int i=1; i<=n;i++){
        res = max(res, dp[i]);
    }
    return res;
}





int main() {
    int a[9] = {0, 5, 10, 7, 4, 8, 9, 2, 10};
    printf("%d\n", longest_seq(8, a));
    int b[9] = {0, 7, 10, 4, 9, 7, 10, 8, 12};
    printf("%d\n", longest_seq(8, b));
    return 0;
}