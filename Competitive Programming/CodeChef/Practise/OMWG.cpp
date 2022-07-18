#include<bits/stdc++.h>
using namespace std;

int Solve(int n, int m) {
    int ans = 0;
    ans += 2*4; // Every corner block has only 2 neighbours
    ans += 3*(2*(m+n-4)); // 2(m-2) and 2(n-2) blocks have 3 neighbours
    ans += 4*(n-2)*(m-2); // center blocks have 4 neighbours
    ans /= 2;
    return ans;
}

int main() {
    unsigned int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        cout << Solve(n, m) << endl;

    }
}