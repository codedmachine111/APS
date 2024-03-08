#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void check(long long left, long long right){
    if(left < right){
        swap(left,right);
    }

    if(left > 2*right || (left+right)%3 != 0){
        cout << "NO" << endl;
        return;
    }else{
        cout << "YES" << endl;
        return;
    }
}

int main(){
    long long t;
    cin >> t;
    for(long long i=0; i<t; i++){
        long long l,r;
        cin >> l >> r;
        check(l,r);
    }

    return 0;
}