#include <iostream>
#include <vector>
using namespace std;

int query(vector<int> BIT, int x) {
    int sum = 0;

    for (; x>0; x -= x & -x) {
        sum += BIT[x];
    }

    return sum;
}

void update(vector<int>& BIT, int x, int val) {
    int n = BIT.size()-1;
    for (; x <= n; x += x & -x) {
        BIT[x] += val;
    }
}

int main() {
    vector<int> arr = {2,1,3,4,2,3,1,6,1,2,3,4};
    int n = arr.size();

    vector<int> BIT(n+1);

    for (int i = 1; i <= n; i++) {
        update(BIT, i, arr[i - 1]);
    }

    int x;
    cin >> x;

    int ans = query(BIT, x);
    cout << ans;

    return 0;
}
