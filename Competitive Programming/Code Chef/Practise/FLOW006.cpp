#include<bits/stdc++.h>
using namespace std;

int Solve(long int n) {
    int sum = 0;
    while(n > 0) {
        int rem = n%10;
        sum += rem;
        n /= 10;
    }
    return sum;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int x;
        cin >> x;
        cout << Solve(x) << endl;
    }
    return 0;
}