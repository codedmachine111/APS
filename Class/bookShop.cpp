#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int solve(int c, vector<int> cost, vector<int> pages){
    int n = cost.size();
    vector<int> dp(c+1);
    dp[0]=0;
    fill(dp.begin()+1, dp.end(), -1);

    for(int i=0; i<n; i++){
        for(int j=(c-cost[i]); j>=0; j--){
            if(dp[j]!=-1){
                int idx = j + cost[i];
                dp[idx] = max(dp[idx], dp[j]+pages[i]);
            }
        }
    }

    for(int i=1; i<=c; i++){
        dp[i] = max(dp[i], dp[i-1]);
    }

    return dp[c];
}

int main(){
    int n, c;
    cin >> n >> c;
    vector<int> cost(n);
    vector<int> pages(n);
    for(int i=0; i<n; i++){
        cin >> cost[i];
    }
    for(int i=0; i<n; i++){
        cin >> pages[i];
    }

    int ans = solve(c, cost, pages);
    cout << ans;
    return 0;
}