#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if(a == 0)
        return b;
    return gcd(b%a, a);
}

vector<int> Solve(const vector<int>& v) {
    int result = v[0];
    vector<int> ans;
    for(auto& i : v) {
        result = gcd(result, i);
    }
    for(auto& i : v) {
        ans.push_back(i/result);
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }
        vector<int> ans = Solve(v);
        for(auto i = ans.begin(); i != ans.end(); i++) {
            cout << *i << " ";
        }
        cout << endl;
    }
    return 0;
}