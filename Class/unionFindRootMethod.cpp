#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int root(vector<int> arr, int i){
    if(i==arr[i]){
        return i;
    }
    return root(arr, arr[i]);
}

void Union(vector<int> &arr, int u, int v){
    int l = root(arr, u);
    int r = root(arr, v);
    arr[l] = r;
}

int find(vector<int> &arr, int u, int v){
    return (root(arr,u)==root(arr,v));
}

int main(){
    int n=5;
    vector<int> arr(n+1);
    
    for(int i=0; i<=n; i++){
        arr[i] = i;
    }
    
    Union(arr, 1,0);
    Union(arr, 0,2);
    Union(arr, 1,4);
    Union(arr, 3,4);
    Union(arr, 3,5);

    for(auto it: arr){
        cout << it << " ";
    }
    return 0;
}