#include <bits/stdc++.h>

using namespace std;

int longestCommonSubs(string s1, string s2){
    int l1 = s1.size();
    int l2 = s2.size();

    int dp[l1+1][l2+1];
    int maxi =0;

    for(int i=0; i<=l1; i++){
        for(int j=0; j<=l2; j++){
            if(i==0 || j==0){
                dp[i][j]=0;
                continue;
            }

            if(s1[i-1] == s2[j-1]){
                // match
                dp[i][j] = 1 + dp[i-1][j-1];
                maxi = max(maxi, dp[i][j]);
            }else{
                dp[i][j]=0;
            }
        }
    }
    return maxi;
}

int main(){

    string s1 = "aaalala";
    string s2 = "kaaala";

    int ans = longestCommonSubs(s1,s2);
    cout << ans;

    return 0;
}