#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findTotalPaths(vector<vector<int>> arr){
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1));
    if(arr[0][0]==0 || arr[n-1][n-1]==0){
        return 0;
    }
    dp[1][1] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(arr[i-1][j-1] == 1){
                dp[i][j] += dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    return dp[n][n];
}

int main(){
    int n = 4;
    char ch;
    vector<vector<int>> arr(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> ch;
            if(ch == '.'){
                arr[i][j]=1;
            }else{
                arr[i][j]=0;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    int ans = findTotalPaths(arr);
    cout << "Total Paths: " << ans;

    return 0;
}