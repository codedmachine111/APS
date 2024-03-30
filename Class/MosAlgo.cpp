#include <bits/stdc++.h>
using namespace std;

long long curr_ans;
long long cnt[100];
long long ans[100500];
int BLOCK_SIZE;
vector<int> arr;

pair<pair<int,int>, int> q[100500];

bool mo_cmp(const pair< pair<int, int>, int> &x,
        const pair< pair<int, int>, int> &y)
{
    int block_x = x.first.first / BLOCK_SIZE;
    int block_y = y.first.first / BLOCK_SIZE;
    if(block_x != block_y)
        return block_x < block_y;
    return x.first.second < y.first.second;
}

void add(int x){
    curr_ans -= cnt[x] * cnt[x] * x;
    cnt[x]++;
    curr_ans += cnt[x] * cnt[x] * x;
}

void remove(int x){
    curr_ans -= cnt[x] * cnt[x] * x;
    cnt[x]--;
    curr_ans += cnt[x] * cnt[x] * x;
}

int main(){
    arr = {0,1,1,0,2,3,4,1,3,5,1,5,3,5,4,0,2,2};
    int nq;
    cin >> nq;
    for(int i = 0; i < nq; i++) {
        cin >> q[i].first.first >> q[i].first.second;
        q[i].second = i;
    }
    BLOCK_SIZE = sqrt(nq); 
    sort(q, q + nq, mo_cmp);

    int mo_left = 0;
    int mo_right = -1;

    for(int i=0; i<nq; i++){
        int left = q[i].first.first;
        int right = q[i].first.second;

        while(mo_right < right){
            mo_right++;
            add(arr[mo_right]);
        }
        while(mo_left < left){
            remove(arr[mo_left]);
            mo_left++;
        }
        while(mo_right > right){
            remove(arr[mo_right]);
            mo_right--;
        }
        while (mo_left > left)
        {
            mo_left--;
            add(arr[mo_left]);
        }
        ans[q[i].second] = curr_ans;
    }

    for(int i = 0; i < nq; i++){
        cout << ans[i] << endl; 
    }
        
    return 0;
}
