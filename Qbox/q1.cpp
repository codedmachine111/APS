// You are given an array of ‘N’ integers. Your task is to find the length of 
// longest subsequence of alternating bits when the numbers are represented in binary. 

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int getLongestAltBits(int num){
    string binary = bitset<32>(num).to_string();
    if(num==0) return 1;

    int pos = binary.find('1');
    binary = binary.substr(pos);

    int maxi = 1;
    int curr = 1;

    for(int i=1; i<binary.size(); i++){
        if(binary[i] != binary[i-1]){
            curr++;
            maxi = max(maxi, curr);
        }else{
            curr =1;
        }
    }
    return maxi;
}

int main(){

    int N;
    cin >> N;
    vector<int> nums(N);

    for(int i=0; i<N; i++){
        cin >> nums[i];
    }

    int ans =0;
    for(int i=0; i<N; i++){
        ans = max(ans, getLongestAltBits(nums[i]));
    }
    cout << ans;

    return 0;
}
