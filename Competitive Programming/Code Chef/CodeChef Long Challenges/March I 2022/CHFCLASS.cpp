#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, ans;
        cin >> n;
        ans = n%7 == 6? n/7 + 1: n/7;
        cout << ans << endl;
    }
    return 0;
}