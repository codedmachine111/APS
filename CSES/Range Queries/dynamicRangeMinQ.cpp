#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll SIZE = 2e5;
const ll TSIZE = 4e5;

ll arr[SIZE];
ll st[TSIZE];

void build(ll si, ll ss, ll se){
    if(ss==se){
        st[si] = arr[ss];
        return;
    }

    ll mid = (ss+se)/2;
    build(2*si, ss, mid);
    build(2*si+1, mid+1, se);

    st[si] = min(st[2*si], st[2*si +1]);
}

ll query(ll si, ll ss, ll se, ll qs, ll qe){
    // outside
    if(qs>se || qe<ss){
        return INT_MAX;
    }

    // inside
    if(ss>= qs && se<=qe){
        return st[si];
    }

    ll mid = (ss+se)/2;
    ll left = query(2*si, ss, mid, qs, qe);
    ll right = query(2*si +1, mid+1, se, qs, qe);

    return min(left, right);
}

void update(ll si, ll ss, ll se, ll qi, ll val){
    if(ss==se){
        st[si] = val;
        return;
    }

    ll mid = (ss+se)/2;
    if(qi<=mid){
        // go left
        update(2*si, ss, mid, qi, val);
    }else{
        // go right
        update(2*si+1, mid+1, se, qi, val);
    }

    st[si] = min(st[2*si], st[2*si +1]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, q, t, l, r;
    cin >> n >> q;
    for(ll i=1; i<=n; i++){
        cin >> arr[i];
    }
    
    build(1,1,n);
    while(q>0){
        cin >> t >> l >> r;
        if(t==1){
            // update
            update(1,1,n, l, r);
        }else{
            // min query
            ll ans = query(1, 1, n, l, r);
            cout << ans << endl;
        }
        q--;
    }

    return 0;
}