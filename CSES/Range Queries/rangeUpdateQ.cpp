#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int N = 200001;
lli st[4*N];

lli build(vector<int> &arr, int si, int ss, int se)
{
    if (ss==se){
        return st[si] = arr[ss];
    }

    int mid = (ss+se) >> 1;

    return st[si] = build(arr, 2*si, ss, mid) + build(arr, 2*si+1, mid+1, se);
}

void update(int si, int ss, int se, int idx, lli value)
{
    if (idx >se || idx < ss)
        return;

    if (ss==se && ss==idx)
    {
        st[si] = value;
        return;
    }

    int mid= (ss+se) >> 1;
    update(2*si, ss, mid, idx, value);
    update(2*si+1, mid+1, se, idx, value);
    st[si] = st[2*si] + st[2*si+1];
}

lli query(int si, int ss, int se, int l, int r)
{
    if (l > se || r < ss)
        return 0;

    if (ss >= l && se <= r)
        return st[si];

    int mid = (ss + se) >> 1;
    return query(2 * si, ss, mid, l, r) + query(2 * si + 1, mid + 1, se, l, r);
}

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    vector<int> zero(n,0);

    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    build(zero, 1, 0, n-1);

    while(q--){
        int t, l, r, val;
        cin >> t;
        if(t==1){
            cin >> l >> r >> val;
            lli actual_val_l = query(1, 0, n-1, l-1, l-1);
            lli actual_val_r = query(1, 0, n-1, r, r);
            update(1, 0, n-1, l-1, actual_val_l+val);
            update(1, 0, n-1, r, actual_val_r-val);
        }else{
            cin >> val;
            cout << arr[val-1] + query(1,0, n-1, 0,val-1) << endl;
        }
    }

    return 0;
}