#include<iostream>
using namespace std;

int Solve(int n) {
    if(n%10 == 0)
        return 0;
    else if(n%5 == 0) {
        return 1;
    }
    else 
        return -1;
}

int main() {
    unsigned int t;
    cin >> t;
    while(t--) {
        int x;
        cin >> x;
        cout << Solve(x) << endl;
    }
    return 0;
}