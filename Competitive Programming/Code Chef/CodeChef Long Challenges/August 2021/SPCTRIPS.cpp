#include<bits/stdc++.h>
using namespace std;

unsigned int Solve(unsigned int n) {
    unsigned int ans = 0;
    for(int c = 1; c <= n; c++) {
        int b = 2*c;
        while(b <= n) {
            int a = c;
            while(a%b == c && a <= n) {
                ans++;
                a += b;
            }
            b += c;
        }
    }
    return ans;
}

int main() {
    unsigned int t;
    cin >> t;
    while(t--) {
        unsigned int n;
        cin >> n;
        cout << Solve(n) << endl;
    }
    return 0;
}
// a,b,c s.t a%b = c, and b%c = 0