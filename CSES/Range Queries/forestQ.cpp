#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

const int N = 1000;
lli arr[N][N];

lli solve(int x1, int y1, int x2, int y2){
    return arr[x2][y2] - arr[x2][y1-1] - arr[x1-1][y2] + arr[x1-1][y1-1];
}

int main(){
    int n,q;
    int x1, y1, x2, y2;
    char ch;

    cin >> n >> q;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> ch;
            if(ch=='*') arr[i][j]=1;
            else arr[i][j] = 0;

            // prefix sum L-R
            arr[i][j] += arr[i][j-1];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            // prefix sum T-D
            arr[i][j] += arr[i-1][j];
        }
    }

    while(q>0){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << solve(x1, y1, x2, y2) << endl;
        q--;
    }
    return 0;
}