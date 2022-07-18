#include<bits/stdc++.h>
using namespace std;

int Solve(string& s, int& n) {
    int ans=0;
    int i, j;
    i = 0;
    while(i < n) {
        j = i+1;
        while(j < n && s[j] == s[i]) {
            j++;
        }
        if(j-i > 1)
            ans += ceil((float)(j-i)/2);
        else
            ans++;
        i = j;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string str;
        cin >> str;
        cout << Solve(str, n) << endl;
    }
    return 0;
}