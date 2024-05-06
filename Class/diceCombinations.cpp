#include <bits/stdc++.h>
using namespace std;

int getTotalCombinations(vector<int> coins, int x){
    int dp[x+1];
    dp[0]=1;
    for(int i=1; i<=x; i++){
        dp[i]=0;
    }
    for(auto c: coins){
        for(int j=0; j<= x-c; j++){
            dp[j+c] += dp[j];
        }
    }

    return dp[x];
}

int main(){ 
    int n_coins = 3;
    int sum = 15;
    vector<int> coins = {1,4,5};

    int ans = getTotalCombinations(coins, sum);
    cout << ans;

    return 0;
}