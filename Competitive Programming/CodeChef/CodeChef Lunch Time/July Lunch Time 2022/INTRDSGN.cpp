#include <bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int amt =(x1+y1) < (x2+y2)? x1+y1: x2+y2;
        cout << amt << endl;
    }
    return 0;
}