#include <bits/stdc++.h>
using namespace std;

unsigned long catalan(unsigned int n){
    if(n<=1){
        return 1;
    }
    unsigned long int res = 0;
    unsigned long int dp[n+1];
    dp[0]=1;
    dp[1]=1;

    for(int i=2; i<=n; i++){
        dp[i]=0;
        for(int j=0; j<i; j++){
            dp[i] += dp[j]*dp[i-j-1];
        }
    }
    return dp[n];
}

int main(){
    int n = 10000;
    
    int ans = catalan(5);
    cout << ans << endl;

    return 0;
}


// Limitations
// 1. Recursive overhead
// 2. Integer Overflow for larger values of n
// 3. Takes too much time for larger values of n
// 4. Garbage values for large values of n
// 5. Calculates same values which can be optimized using DP.