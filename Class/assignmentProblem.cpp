#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n){
    int ct =0;
    while(n){
        ct += n & 1;
        n = n >> 1;
    }
    return ct;
}

bool isBitSetInMask(int mask, int j){
    if((mask & (1<<j))==0){
        return false;
    }
    return true;
}

int getMaxResource(vector<vector<int>> &arr, int n){
    int p = pow(2,n);
    vector<unsigned int> dp(p);

    // populate the mask
    for(int i=0; i<p; i++){
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    
    // iterate
    for(int mask=0; mask<p; mask++){
        int x = countSetBits(mask);
        for(int j=0; j<n; j++){
            if(!isBitSetInMask(mask,j)){
                dp[mask|(1<<j)] = min(dp[mask|(1<<j)], (dp[mask]+arr[x][j]));
            }
        }
    }
    return dp[p-1];
}

int main() {
    vector<vector<int>> arr = {{3,2,70},{5,19,3},{20,7,2}};
    int n  = 3;
    int ans = getMaxResource(arr,n);
    cout << ans << endl;
    
    return 0;
}