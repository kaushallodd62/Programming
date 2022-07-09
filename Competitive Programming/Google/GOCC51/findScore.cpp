#include<bits/stdc++.h>
using namespace std;

// return the count of strings str is a prefix to
long long int isPrefix(string str, vector<string> s, int n, int k) {
    long long int ans = 0;

    for(int i = 0; i < n; i++) {
        if(s[i].find(str) == 0)
            ans++;
    }

    return ans;
}

vector<long long int> solve(vector<string> s, int n, int k) {

    vector<long long int> res;
    long long int count;

    for(int i = 0; i < n; i++) {
        count = 0;
        for(int j = 0; j < k; j++) {
            count += isPrefix(s[i].substr(0, j+1), s, n, k);
        }
        res.push_back(count);
    }

    return res;
}

int main() {
    int t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<string> s(n);

        for(int i=0; i<n; i++) {
            cin >> s[i];
        }

        vector<long long int> res = solve(s, n, k);
        for(auto it = res.begin(); it < res.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }
    return 0;
}