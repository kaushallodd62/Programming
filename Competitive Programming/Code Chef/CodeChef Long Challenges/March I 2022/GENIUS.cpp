#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        int a, b, c;
        cin >> n >> x;
        if(x%3 == 0) {
            a = x/3; b = 0; c = n - a;
            cout << "YES" << endl << a << " " << b << " " << c << endl;
        }
        else if(x%3 == 1) {
            a = (x+2)/3;
            if(n-a < 2)
                cout << "NO" << endl;
            else {
                b = 2; c = n - a - b;
                cout << "YES" << endl << a << " " << b << " " << c << endl;
            }
        }
        else {
            a = (x+1)/3;
            if(n-a < 1)
                cout << "NO" << endl;
            else {
                b = 1; c = n - a - b;
                cout << "YES" << endl << a << " " << b << " " << c << endl;
            }
        }
    }
    return 0;
}