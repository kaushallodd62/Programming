#include<bits/stdc++.h>
using namespace std;

unordered_set<int> s;   // check whether the node has already been traversed or not
map<int, int> mp;   // stores the frequency of each value along the path
void dfs(int n, vector<int> c, vector<int> adj[], int src, int length, int& ans) {
    s.insert(src);
    mp[c[src]]++;

    if(mp[c[src]] >= ceil((float)length/2))
        ans++;
    
    for(int i=0; i<adj[src].size(); i++) {
        int dest = adj[src][i];
        if(s.find(dest) == s.end()) {
            dfs(n, c, adj, dest, length+1, ans);
        }
    }
    mp[c[src]]--;
}


int solve(int n, vector<int> C, vector<vector<int>> edges) {
    s.clear();
    mp.clear();
    int ans = 0;
    vector<int> adj[n];

    // initializing the map
    for(int i=0; i<=n; i++) {
        mp[i] = 0;
    }

    // convert edges into adjacency list
    for(int i=0; i<n-1; i++) {
        adj[edges[i][0]-1].push_back(edges[i][1]-1);
        adj[edges[i][1]-1].push_back(edges[i][0]-1);
    }

    dfs(n, C, adj, 0, 1, ans);
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        // number of nodes
        int n;
        cin >> n;
        
        // value of each node
        vector<int> C(n);
        for(int i=0; i<n; i++) {
            cin >> C[i];
        }

        // edges
        vector<vector<int>> edges(n-1, vector<int>(2));
        for(int i=0; i<n-1; i++) {
            for(int j=0; j<2; j++) {
                cin >> edges[i][j];
            }
        }

        // output the answer
        cout << solve(n, C, edges) << endl;
    }
}
