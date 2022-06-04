#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    bool isPrime = true;
    for(int i = 2; i <= sqrt(n); i++)
        if(n%i == 0) {
            isPrime = false;
            break;
        }
    return isPrime;
}

int firstPrimeAfter(int n) {
    if(n%2 == 0)
        n++;
    else
        n += 2;
    while(!isPrime(n))
        n += 2;
    return n;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        int sum = a+b;
        int c = firstPrimeAfter(sum) - sum;
        cout << c;
    }
}