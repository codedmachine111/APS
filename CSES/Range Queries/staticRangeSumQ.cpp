#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,q;
    cin >> n >> q;

    vector<long long> arr(n+1);
    vector<unsigned long> prefixSum(n+1);
    
    for(long long i=1; i<=n; i++){
        cin >> arr[i];
        prefixSum[i] = prefixSum[i-1] + arr[i];
    }

    for(long long i=0; i<q; i++){
        long long a,b;
        cin >> a >> b;
        cout << prefixSum[b] - prefixSum[a-1] << endl;
    }

    return 0;
}