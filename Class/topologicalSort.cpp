#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<vector<int>> &adj, vector<bool> &vis, stack<int> &st){
    vis[i] = true;

    for(auto it: adj[i]){
        if(!vis[it]){
            dfs(it, adj, vis, st);
        }
    }

    st.push(i);
}

void topoSort(vector<vector<int>> &adj, int V){
    stack<int> st;
    vector<bool> vis(V, false);

    for(int i=0; i<V; i++){
        if(!vis[i]){
            dfs(i, adj, vis, st);
        }
    }

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}

int main(){
    int vertices = 4;

    vector<vector<int>> edges = {{0,1}, {1,2}, {3,1}, {3,2}};
    vector<vector<int>> adj(vertices);

    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
    }

    cout << "Topologically sorted graph: " << endl;
    topoSort(adj, vertices);

    return 0;
}