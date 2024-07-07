#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> graph;

void addedge(int x, int y, int cost) {
    graph[x].push_back(make_pair(cost, y));
    graph[y].push_back(make_pair(cost, x));
}

void bestFirstSearch(int source, int target, int v) {

    vector<bool> vis(v, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push(make_pair(0, source));
    vis[source] = true;

    while (!pq.empty()) {
        int x = pq.top().second;
        cout << x << " ";
        pq.pop();

        if (x == target) break;

        for (const auto& it: graph[x]) {
            int cost = it.first;
            int neighbor = it.second;
            
            if (!vis[neighbor]) {
                vis[neighbor] = true;
                pq.push(make_pair(cost, neighbor));
            }
        }
    }
}

int main() {

    int v = 14;
    graph.resize(v);

    addedge(0, 1, 3);
    addedge(0, 2, 6);
    addedge(0, 3, 5);
    addedge(1, 4, 9);
    addedge(1, 5, 8);
    addedge(2, 6, 12);
    addedge(2, 7, 14);
    addedge(3, 8, 7);
    addedge(8, 9, 5);
    addedge(8, 10, 6);
    addedge(9, 11, 1);
    addedge(9, 12, 10);
    addedge(9, 13, 2);
 
    int source = 0;
    int target = 9;
 
    bestFirstSearch(source, target, v);

    return 0;
}