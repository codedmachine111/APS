#include <bits/stdc++.h>
#include <iostream>

using namespace std;

enum node{
    a, b, c, d, s, g
};

void Union(vector<int> &arr, int a, int b){
    int l = arr[a];
    int r = arr[b];
    int n = arr.size();
    for(int i=0; i<n; i++){
        if(arr[i]==l){
            arr[i]=r;
        }
    }
}

int find(vector<int> arr, int a, int b){
    return arr[a]==arr[b];
}

int main(){
    int n;
    cin >> n;
    int u, v, cost;
    vector<pair<int, pair<int, int>>> edges;
    vector<int> union_array(n+1);

    for(int i=0; i<=n; i++){
        cin >> u >> v >> cost;
        edges.push_back({cost, {u, v}});
    }
    sort(edges.begin(), edges.end());

    for(int i=0; i<=n; i++){
        union_array[i]=i;
    }

    vector<pair<int, int>> mst_edges;
    int ct=n-1;
    int i=0;
    while(ct>0){
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int cost = edges[i].first;

        Union(union_array, u, v);
        if(find(union_array, u, v)){
            // accept
            mst_edges.push_back({u,v});
        }
        ct--;
        i++;
    }

    cout << "Minimum Spanning Tree Edges:" << endl;
    for(auto edge: mst_edges) {
        cout << edge.first << " - " << edge.second << endl;
    }

    return 0;
}