#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(string a, string b){
    int l1 = a.length();
    int l2 = b.length();

    // Initialize 2D DP array
    vector<vector<int>> dp(l1+1, vector<int> (l2+1));
    for(int i=0; i<l1+1; i++){
        dp[i][0] = 0;
        for(int j=0; j<l2+1; j++){
            dp[0][j] = 0;
        }
    }

    for(int i=1; i<=l1; i++){
        for(int j=1; j<=l2; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[l1][l2];
}

int main(){
    string a = "abcda";
    string b = "bdabac";

    int ans = solve(a,b);
    cout << ans;

    return 0;
}