#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;

const  int SIZE = 2e5;
const  int TSIZE = 4e5;

ll arr[SIZE];
ll st[TSIZE];

void build(ll si, ll ss, ll se){
    if(ss==se){
        st[si] = arr[ss];
        return;
    }

    ll mid = (ss + se)/2;
    build(2*si, ss, mid);
    build(2*si +1, mid+1, se);

    st[si] = min(st[2*si], st[2*si + 1]);
}

ll query(ll si, ll ss, ll se, ll qs, ll qe){
    if(qs>se || qe<ss){
        // outside
        return INT_MAX;
    }
    if(ss>=qs && se<=qe){
        // inside
        return st[si];
    }

    ll mid = (ss+se)/2;
    ll left = query(2*si, ss, mid, qs, qe);
    ll right = query(2*si+1, mid+1, se, qs, qe);

    return min(left,right);
}

int main(){
    ll n, q, l, r;
    cin >> n >> q;
    
    for(ll i=1; i<=n; i++){
        cin >> arr[i];
    }

    build(1, 1, n);
    while(q>0){
        cin >> l >> r;
        ll ans = query(1, 1, n, l, r);
        cout << ans << endl;
        q--;
    }

    return 0;
}