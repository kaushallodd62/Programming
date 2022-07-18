#include<bits/stdc++.h>
#define mod (int)1e9 + 7
using namespace std;

bool isDecomposed(vector<long long int>& amounts, map<int, vector<pair<long long int, int>>>& eqns) {
    for(auto& x: eqns) {
        if(amounts[x.first] != 0)
            return false;
    }
    return true;
}

void Solve(vector<long long int>& amounts, map<int, vector<pair<long long int, int>>>& eqns) {
    while(!isDecomposed(amounts, eqns)) {
        for(auto& x: eqns) {
            for(auto& y: x.second) {
                amounts[y.second] += (amounts[x.first]*(y.first));
            }
            amounts[x.first] = 0;
        }
    }
    for(auto& x: amounts) {
        int amount = x % mod;
        cout << amount << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long int> amount;
    for(auto i=0; i<n; i++) {
        long long int temp;
        cin >> temp;
        amount.push_back(temp);
    }
    map<int, vector<pair<long long int, int>>> eqns;
    for(auto i=0; i < m; i++) {
        int c, x;
        cin >> c >> x;
        for(auto j=0; j<x; j++) {
            long long int weight;
            int comp;
            cin >> weight >> comp;
            eqns[c-1].push_back({weight, comp-1});
        }
    }
    Solve(amount, eqns);
    return 0;
}