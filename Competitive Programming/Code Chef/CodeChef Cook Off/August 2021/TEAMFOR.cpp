#include<bits/stdc++.h>
using namespace std;

int Solve(int n, string s, string t) {
    int ans;
    int sum_s=0, sum_t=0;
    for(int i=0; i<s.length(); i++) {
        if(s[i] == '1')
            sum_s++;
        if(t[i] == '1')
            sum_t++;
    }
    ans = min(sum_s, sum_t);
    if(ans > n/2)
        ans=n/2;
    return ans;
}

int main() {
    unsigned int t;
    cin >> t;
    while(t--) {
        int n;
        string s, t;
        cin >> n;
        cin >> s >> t;
        cout << Solve(n, s, t) << endl;
    }
    return 0;
}