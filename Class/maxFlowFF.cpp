#include <bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>> &residual, int s, int d, vector<int> &parent){
    int n = residual.size();
    vector<bool> visited(n, 0);
    
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v=0; v<n; v++){
            if(visited[v]==false && residual[u][v]>0){
                if(v==d){
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}

int maxFlowFF(vector<vector<int>> &graph, int source, int destination){
    int u, v;
    int n = graph.size();
    int maxFlow = 0;

    vector<vector<int>> residual(n, vector<int>(n, 0));

    for(u=0; u<n; u++){
        for(v=0; v<n; v++){
            residual[u][v] = graph[u][v];
        }
    }
    vector<int> parent(n,0);
    while(bfs(residual, source, destination, parent)){
        int pathFlow = INT_MAX;
        for(v=destination; v!=source; v=parent[v]){
            u = parent[v];
            pathFlow = min(pathFlow, residual[u][v]);
        }

        for(v=destination; v!=source; v = parent[v]){
            u = parent[v];
            residual[u][v] -= pathFlow;
            residual[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main(){
    vector<vector<int>> adj = {{0, 16, 13, 0, 0, 0},{0, 0, 10, 12, 0, 0},
                                {0, 4, 0, 0, 14, 0}, {0, 0, 9, 0, 0, 20}, 
                                {0, 0, 0, 7, 0, 4}, {0, 0, 0, 0, 0, 0}};
    
    int source = 0;
    int destination = 5;
    int flow = maxFlowFF(adj, source, destination);
    cout << "Max flow: " << flow << endl;

    return 0;
}