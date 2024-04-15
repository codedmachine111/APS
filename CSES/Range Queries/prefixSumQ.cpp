#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node{
    ll prefix;
    ll sum;
};

const ll SIZE = 2e5;
ll arr[SIZE+1];
Node st[4*SIZE];

void mergeResult(int si){
	st[si].sum = st[2*si].sum + st[2*si+1].sum;
	st[si].prefix = max(st[2*si].prefix , st[2*si].sum + st[2*si+1].prefix);
}

void build(int si, int ss, int se){
    if(ss==se){
        st[si].prefix = arr[ss];
        st[si].sum = arr[ss];
        return;
    }

    int mid = (ss+se)/2;
    build(2*si, ss, mid);
    build(2*si+1, mid+1, se);

    mergeResult(si);
}

void update(int si, int ss, int se, int qi, int val){
    if(qi<ss || qi > se){
        return;
    }

    if(ss == se && ss==qi){
        st[si].sum = val;
        st[si].prefix = val;
        arr[ss] = val;
        return;
    }

    int mid = (ss + se)/2;
    update(2*si, ss, mid, qi, val);
    update(2*si+1, mid+1, se, qi, val);

    mergeResult(si);
}

Node maxProfit(int si , int ss , int se , int L ,int R){
	if(ss > R || se < L){
		Node temp;
		temp.prefix = temp.sum = 0;
		return temp;
	}
	
	if(ss >= L && se <= R) return st[si];
	
	int mid = (ss + se) / 2;
	Node l = maxProfit(2*si , ss , mid , L , R);
	Node r = maxProfit(2*si + 1 , mid + 1 , se , L , R);
	Node res;
	res.sum = l.sum + r.sum;
	res.prefix = max(l.prefix , l.sum + r.prefix);
	return res;
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
            Node ans = maxProfit(1, 1, n, l, r);
            cout << max(0LL, ans.prefix) << endl;
        }
        q--;
    }

    return 0;
}