#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int getMaxSubSum(vector<int> arr){
    int maxi = INT_MIN;
    int n = arr.size();
    int sum =0;

    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum <0){
            sum =0;
        }
        maxi = max(maxi, sum);
    }

    return maxi;
}

int main(){

    vector<int> arr = {-1,-3, 1, 4, -2, -1, 5, 1};

    int maxSum = getMaxSubSum(arr);
    cout << maxSum;

    return 0;
}