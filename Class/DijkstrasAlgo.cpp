#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int,int>> adj[], int u, int v, int wt){
    adj[u].push_back(make_pair(v,wt));
    adj[v].push_back(make_pair(u,wt));
}

vector<int> getShortestPath(vector<pair<int,int>> adj[], int N, int source){
    vector<int> dist(N, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0,source});
    dist[source] = 0;

    while(!pq.empty()){
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it: adj[node]){
            int n = it.first;
            int edgeWeight = it.second;

            if(edgeWeight+distance < dist[n]){
                dist[n] = edgeWeight+distance;
                pq.push({edgeWeight+distance, n});
            }
        }
    }
    return dist;
}

int main(){
    int N = 6;
    vector<pair<int,int>> adj[N];
    int source = 0;

    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 2, 4);
    addEdge(adj, 1, 2, 2);
    addEdge(adj, 2, 3, 3);
    addEdge(adj, 2, 4, 1);
    addEdge(adj, 2, 5, 6);
    addEdge(adj, 3, 5, 2);
    addEdge(adj, 4, 5, 3);

    vector<int> path = getShortestPath(adj, N, source);
    for(auto it: path){
        cout << it << " " << endl;
    }

    return 0;
}