#include<iostream>
#include<cmath>
using namespace std;

unsigned int Solve(unsigned int n, unsigned int p, unsigned int k) {
    unsigned int max_rem = p%k;
    unsigned int rem = 0;
    unsigned int days = 0;
    if(rem < max_rem) {
        if(n%k < max_rem)
            days = (n%k)*ceil((double)n/k) + (max_rem - n%k)*(n/k);
        else
            days = (max_rem)*ceil((double)n/k);
    }
    unsigned int i = max_rem;
    while(i < n && i != p) {
        days++;
        i = i+k;
    }
    days++;
    return days;
}

int main() {
    unsigned int t;
    cin >> t;
    while(t--) {
        unsigned int n, p, k;
        cin >> n >> p >> k;
        cout << Solve(n, p, k) << endl;
    }
    return 0;
}