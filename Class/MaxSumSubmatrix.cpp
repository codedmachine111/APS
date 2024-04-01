#include <bits/stdc++.h>
using namespace std;

int kanades(vector<int> arr){
    int n = arr.size();
    int maxi = INT_MIN;
    int sum =0;
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum<0) sum =0;

        maxi = max(maxi, sum);
    }
    return maxi;
}

int maxSum(vector<vector<int>> arr){
    int R = arr.size();
    int C = arr[0].size();

    int maxSum = INT_MIN;
    for(int cStart=0; cStart<C; cStart++){
        vector<int> sum(R,0);
        for(int cEnd=cStart; cEnd<C; cEnd++){
            for(int row=0; row<R; row++){
                sum[row] += arr[row][cEnd];
            }
            int kanade = kanades(sum);
            maxSum = max(maxSum, kanade);
        }
    }
    return maxSum;
}

int main()
{
    vector<vector<int>> arr = { {-8, -3, 4, -2},
                                {3, 8, 9, 1},
                                {-4, -1, 1, 7},
                                {-2, -3, 8, 1} };
    
    int ans = maxSum(arr);
    cout << ans << endl;

    return 0;
}