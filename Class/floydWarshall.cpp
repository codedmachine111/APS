#include <bits/stdc++.h>
using namespace std;

#define INF 99999
#define v 4

void display(int adj[][v]){
    cout << "Shortest distances between every pair of vertices" << endl;

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (adj[i][j] == INF)
                cout << "INF"
                     << " ";
            else
                cout << adj[i][j] << "   ";
        }
        cout << endl;
    }
}

void floydWarshall(int adj[][v]){
    int i, j,k;

    for(k=0; k<v; k++){
        for(i=0; i<v; i++){
            for(j=0; j<v; j++){

                if(adj[i][j] > (adj[i][k] + adj[k][j]) && (adj[k][j]!=INF && adj[i][k] != INF)){
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    display(adj);
}

int main(){

    int adj[v][v] = {{0, 5, INF, 10},{INF, 0, 3, INF},{INF, INF, 0, 1},{INF, INF, INF, 0}};

    floydWarshall(adj);
    return 0;
}