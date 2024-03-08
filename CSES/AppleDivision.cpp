#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    long long sum =0;
    long long mini = LLONG_MAX;

    vector<long long> arr;
    for(int i=0; i<n; i++){
        long long val;
        cin >> val;
        sum += val;
        arr.push_back(val);
    }
    for(int i=0; i<(1<<n); i++){
        long long g1 = 0;
        for(int j=0; j<n; j++){
            if(i & (1<<j)){
                g1 += arr[j];
            }
        }
        long long g2 = sum -g1;
        long long diff = abs(g2-g1);
        mini = min(mini, diff);
    }

    cout << mini << endl;
    return 0;
}