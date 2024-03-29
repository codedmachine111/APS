#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int N = 200001;
lli arr[N];
lli st[4 * N];

lli build(int si, int ss, int se)
{
    if (ss == se)
        return st[si] = arr[ss];

    int mid = (ss + se) >> 1;

    return st[si] = build(2 * si, ss, mid) + build(2 * si + 1, mid + 1, se);
}

void update(int si, int ss, int se, int idx, lli value)
{
    if (idx > se || idx < ss)
        return;

    if (ss == se && ss == idx)
    {
        st[si] += value;
        return;
    }

    int mid = (ss + se) >> 1;
    update(2 * si, ss, mid, idx, value);
    update(2 * si + 1, mid + 1, se, idx, value);
    st[si] = st[2 * si] + st[2 * si + 1];
}

lli getSum(int si, int ss, int se, int l, int r)
{
    if (l > se || r < ss)
        return 0;

    if (ss >= l && se <= r)
        return st[si];

    int mid = (ss + se) >> 1;
    return getSum(2 * si, ss, mid, l, r) + getSum(2 * si + 1, mid + 1, se, l, r);
}

int main()
{
    int n , q , a , b;
	cin>>n>>q;
	
	for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
	
	build(1 , 1 , n);
	while(q--)
	{
		int code;
		cin>>code>>a>>b;
		if(code == 1) update(1 , 1 , n , a , b - arr[a]) , arr[a] = b;
		else		  cout<<getSum(1 , 1 , n , a , b)<<endl;
    }
}