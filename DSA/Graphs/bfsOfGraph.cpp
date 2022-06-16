#include<bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    // Code here
    vector<int> ans;
    unordered_set<int> s;   // for storing traversed nodes
    queue<int> q;
    q.push(0);  // assuming 0 is root node (starting node)
    int curr;
    while(!q.empty()) {
        curr = q.front();
        q.pop();
        ans.push_back(curr);
        for(int j=0; j<adj[curr].size(); j++) {
            if(s.find(adj[curr][j]) == s.end()) {
                s.insert(adj[curr][j]);
                q.push(adj[curr][j]);
            }
        }
    }
    return ans;
}