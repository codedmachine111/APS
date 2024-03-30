#include <bits/stdc++.h>
using namespace std;

int getMaxValueOfGifts(vector<vector<int>> arr){
    int n = arr.size();
    int m = arr[0].size();

    int dp[n+1][m+1];
    for(int i=0; i<=n; i++){
        dp[i][0] = 0;
    }
    for(int j=0; j<=m; j++){
        dp[0][j] = 0;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + arr[i-1][j-1];
        }
    }
    return dp[n][m];
}

int main(){
    vector<vector<int>> arr = {{1, 10, 3, 8},{12, 2, 9, 6},{5, 7, 4, 11},{3, 7, 16, 5}};

    int ans = getMaxValueOfGifts(arr);
    cout << ans;

    return 0;
}