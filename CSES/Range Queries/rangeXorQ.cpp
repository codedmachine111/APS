#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,q;
    cin >> n >> q;
    vector<long long> prefixXor(n+1);
    for(long long i=1; i<=n; i++){
        long long val;
        cin >> val;
        prefixXor[i] = prefixXor[i-1] ^ val;
    }

    while(q>0){ 
        long long a,b;
        cin >> a >> b;
        long long ans = prefixXor[b] ^ prefixXor[a-1];
        cout << ans << endl;
        q--;
    }

    return 0;
}