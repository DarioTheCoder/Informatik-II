


int max(int x, int y){
    if (x > y){
        return x;
    }
    return y;
}

int ed(char X[], int n, char Y[], int m){
    
    int dp[n+1][m+1];
    for (int i=1; i<=n+1;i++){            
        dp[i][0] = 0;
    }
    for (int j=0; j<=m+1;j++){
        dp[0][j] = 0;
    }
        
    
    for (int i=1; i<=n+1;i++){            
        for (int j=1; j<=m+1;j++){
            if (X[i] == Y[j]){  
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    int res =  dp[n+1][m+1];
    int maxlength = max(n,m);
    return maxlength - res;
}