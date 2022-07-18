#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int sum1 = 0, sum2 = 0;
        for(int i = 0; i < 3; i++) {
            int temp;
            cin >> temp;
            sum1 += temp;
        }
        for(int i = 0; i < 3; i++) {
            int temp;
            cin >> temp;
            sum2 += temp;
        }
        if(sum1 > sum2)
            cout << "1\n";
        else 
            cout << "2\n";
    }
    return 0;
}