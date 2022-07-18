#include<bits/stdc++.h>
using namespace std;

char pre, suff;

int Solve(const string& s, int first) {
    if(first < s.size()-1) {
        int i = first;
        while(i < s.size()-1 && s[i] != pre && s[i] != suff) {
            i++;
        }
        return max(i-first, Solve(s, i+1));
    }
   return 0;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        pre = s[0]; suff = s[s.size()-1];
        int ans = Solve(s, 1);
        if(ans == 0)
            cout << "-1" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
