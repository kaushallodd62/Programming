#include<bits/stdc++.h>
using namespace std;

int Solve(vector<int>& arr) {
    unordered_map<int, int> mp;
    int ans = 0, mx = INT_MIN;
    for(auto x : arr) {
        mp[x]++;
    }
    for(auto x : mp) {
        mx = max(mx, x.second);
    }
    switch(mx) {
    case 1:
        ans = 2;
        break;
    case 2:
        ans = 2;
        break;
    case 3:
        ans = 1;
        break;
    case 4:
        ans = 0;
        break;
    default:
        break;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        vector<int> arr;
        for(int i = 0; i < 4; i++) {
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }
        int ans = Solve(arr);
        cout << ans << endl;
    }
    return 0;
}