#include<iostream>
#include<unordered_map>
#include<string>
#include<utility>
#include<limits.h>
using namespace std;

bool cmp(pair<const char, int>& a, pair<const char, int>& b) {
    return a.second > b.second;
}

string Solve(string s) {
    string ans;
    unordered_map<char, int> mp;
    for(auto c: s) {
        mp[c]++;
    }
    int mx = INT_MIN;
    for(auto x: mp) {
        mx = max(mx, x.second);
    }
    if(mx > s.size()-mx) 
        ans = "IMPOSSIBLE";
    else {
        //sort(mp.begin(), mp.end(), cmp);
        for(int i=0; i<s.size(); i++) {
            for(auto x : mp) {
                if(s[i] != x.first) {
                    ans.push_back(x.first);
                    (x.second)--;
                    break;
                }
            }

        }
    }
    return ans;
}

int main() {
    unsigned int t;
    cin >> t;
    for(int i=1; i<=t; i++) {
        string s;
        cin >> s;
        cout << "Case #" << i << ": " << Solve(s) << endl;
    }
    return 0;
}