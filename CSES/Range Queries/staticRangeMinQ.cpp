#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long arr[100001];
long long stree[400004];

void buildTree(long long sidx, long long left, long long right){
    if(left==right){
        stree[sidx] = arr[left];
        return;
    }

    long long mid = left + (right-left)/2;

    buildTree(2*sidx, left, mid);
    buildTree(2*sidx+1, mid+1, right);

    stree[sidx] = min(stree[2*sidx], stree[2*sidx + 1]);
}

long long query(long long sidx, long long left, long long right, long long ql, long long qr){
    if(left > qr || right < ql){
        return INT_MAX;
    }
    if(left >= ql && right <= qr){
        return stree[sidx];
    }

    long long mid = left + (right-left)/2;
    long long lcall = query(2*sidx, left, mid, ql, qr);
    long long rcall = query(2*sidx + 1, mid+1, right, ql, qr);

    return min(lcall,rcall);
}

int main(){

    long long n, q, a, b;
    cin >> n >> q;
    for(long long i=1; i<=n; i++){
        cin >> arr[i];
    }

    buildTree(1,1,n);

    while(q>0){
        cin >> a >> b;
        long long mini = query(1, 1, n, a, b);
        cout << mini << endl;
        q--;
    }

    return 0;
}