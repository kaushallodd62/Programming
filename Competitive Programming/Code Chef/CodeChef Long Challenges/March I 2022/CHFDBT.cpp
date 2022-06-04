#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        int ans = n%2 == 1? n/2 + 1: n/2;
        cout << ans << endl;
    }
    return 0;
}