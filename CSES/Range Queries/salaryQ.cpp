#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

const int SIZE = 2e5;
int arr[SIZE+1];

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
oset<array<int, 2>> s;

int query(int x){
    return s.order_of_key({x, 0});
}

int main(){
    int n, q;
    cin >> n >> q;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        s.insert({arr[i], i});
    }

    for(int i=0; i<q; i++){

        char t;
        cin >> t;
        if(t=='!'){
            int k, x;
            cin >> k >> x, --k;
            s.erase({arr[k], k});
            arr[k] = x;
            s.insert({arr[k], k});
        }else{
            int a, b;
            cin >> a >> b;
            cout << query(b+1)- query(a) << endl;
        }
    }

    return 0;
}
