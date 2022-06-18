#include<bits/stdc++.h>
using namespace std;

void shortest_distance(vector<vector<int>>& g) {
    int V = g.size();
    int i, j, k;
    for(k=0; k<V; k++) {
        for(i=0; i<V; i++) {
            for(j=0; j<V; j++) {
                if(g[i][k] != -1 && g[j][k] != -1 && (g[i][j] == -1 || g[i][j] > g[i][k] + g[k][j]))
                    g[i][j] = g[i][k] + g[k][j];
            }
        }
    }
}