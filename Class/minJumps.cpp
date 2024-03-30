#include <bits/stdc++.h>
using namespace std;

int getMinJumps(vector<int> arr){
    int n = arr.size();
    long long dp[n];
    dp[0]=0;
    for(int i=1; i<=n; i++){
        dp[i] = INT_MAX;
    }

    for(int i=0; i<n-1; i++){
        for(int j=1; (i+j)<n && j <=arr[i]; j++){
            dp[i+j] = min(dp[i+j], dp[i]+1);
        }
    }

    return dp[n-1];
}

int main(){
    vector<int> arr = {2,3,1,1,4};

    int ans = getMinJumps(arr);
    cout << ans;

    return 0;
}