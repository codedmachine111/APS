#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

void printGrayCodes(int n){
    if(n<=0){
        return;
    } 
    
    vector<string> ans;
    
    // start with 0,1
    ans.push_back("0");
    ans.push_back("1");
    
    // outer loop to generate codes
    for(int i=2; i<(1<<n); i=i<<1){
        
        // append existing in reverse order
        for(int j=i-1; j>=0; j--){
            ans.push_back(ans[j]);
        }
        // 0,1,1,0
        
        // prefix 0s to first half
        for(int j=0; j<i; j++){
            ans[j] = "0" + ans[j];
        }
        // 00,01,1,0
        
        // prefix 1s to second half
        for(int j=i; j<2*i; j++){
            ans[j] = "1" + ans[j]; 
        }
        // 00,01,11,10
        // REPEAT
    }
    
    for(auto it: ans){
        cout << it << endl;
    }
}

int main() {
    int n;
    cin >> n;
    
    printGrayCodes(n);

    return 0;
}