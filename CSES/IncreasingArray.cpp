#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long countMoves(vector<long long> &arr){
    long long ct =0;
    long long n = arr.size();
    for(long long i=1; i<n; i++){
        if(arr[i] >= arr[i-1]) continue;
        else{
            while(arr[i] < arr[i-1]){
                ct++;
                arr[i]++;
            }
        }
    }

    return ct;
}

int main(){
    long long n;
    cin >> n;

    vector<long long> arr;
    for(long long i=0; i<n; i++){
        long long val;
        cin >> val;
        arr.push_back(val);
    }

    long long ans = countMoves(arr);
    cout << ans;

    return 0;
}