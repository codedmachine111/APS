#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node{
    int value;
    int index;
};

const ll SIZE = 2e5;
Node st[4*SIZE];

void build(vector<ll> &arr, int si, int ss, int se){
    if(ss==se){
        st[si].index = ss+1;
        st[si].value = arr[ss];
        return;
    }

    int mid = (ss+se)/2;
    build(arr, 2*si, ss, mid);
    build(arr, 2*si+1, mid+1, se);

    if(st[2*si].value >= st[2*si+1].value){
        st[si] = st[2*si];
    }else{
        st[si] = st[2*si+1];
    }
}

int query(int si, int ss, int se, ll val){
    if(st[si].value < val){
        return 0;
    }

    if(ss==se){
        st[si].value -= val;
        return st[si].index;
    }

    int mid = (ss + se) / 2;
    int idx;
    if(st[2*si].value >= val){
        idx = query(2*si, ss, mid, val);
    } else {
        idx = query(2*si+1, mid+1, se, val);
    }

    if(st[2*si].value >= st[2*si+1].value){
        st[si] = st[2*si];
    } else {
        st[si] = st[2*si+1];
    }

    return idx;
}


int main(){
    int n, m;
    cin >> n >> m;
    vector<ll> hotels(n);
    vector<ll> rooms(m);

    for(int i=0; i<n; i++){
        cin >> hotels[i];
    }
    for(int i=0; i<m; i++){
        cin >> rooms[i];
    }

    build(hotels, 1, 0, n-1);
    for(int i=0; i<m; i++){
        int ans = query(1, 0, n-1, rooms[i]);
        cout << ans << endl;
    }
}