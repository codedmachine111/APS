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

int query(int si, int ss, int se, int k)
{
    if (ss==se)
        return ss;

    int mid =(ss + se) >> 1;

    if (st[2 * si] >= k){
        return query(2*si, ss, mid, k);
    }
    else{
        return query(2*si+1, mid+1, se, k-st[2 * si]);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> present(n, 1);

    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    build(present, 1, 0, n-1);

    for (int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        int idx = query(1, 0, n-1, x);

        present[idx] = 0;
        update(1, 0, n-1, idx, 0);
        cout << arr[idx] << " ";
    }

    return 0;
}
