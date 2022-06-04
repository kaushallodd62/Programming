#include<bits/stdc++.h>
using namespace std;

string Solve(vector<string>& v) {
    string ans;
    for(int i=0; i<v.size(); i++) {
        char c = v[i][i];
        if(c == '1')
            c = '0';
        else
            c = '1';
        ans.push_back(c);
    }
    return ans;
}

int main() {
    unsigned int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<string> v;
        for(int i=0; i<n; i++) {
            string s;
            cin >> s;
            v.push_back(s);
        }
        cout << Solve(v) << endl;
    }
    return 0;
}