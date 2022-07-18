#include<bits/stdc++.h>
using namespace std;

int Solve(map<int, int>& mp, int n) {
    if(n<=2)
        return 0;
    int mx = INT_MIN;
    int ans;
    for(auto x: mp)
        mx = max(mx, x.second);
    if(mx == 1)
        ans = n-2;
    else
        ans = n-mx;
    return ans;
}

int main() {
    unsigned int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        map<int, int> mp;
        for(int i=0; i<n; i++) {
            int temp;
            cin >> temp;
            mp[temp]++;
        }
        cout << Solve(mp, n) << endl;
    }
    return 0;
}