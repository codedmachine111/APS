#include <bits/stdc++.h>
using namespace std;

struct compare{
    bool operator()(int a, int b){
        return a > b;
    }
};

int main(){
    vector<int> data = {10,2,1,13,9,8,31,11};
    priority_queue<int, vector<int>, compare> pq;

    cout << "Data to be stored: \n";
    for(auto it: data){
        cout << it << " ";
        pq.push(it);
    }
    cout << endl;

    cout << "Data stored in min heap: \n";
    while(!pq.empty()){
        int top = pq.top();
        cout << top << " ";
        pq.pop();
    }

    return 0;
}