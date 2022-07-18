#include<iostream>
using namespace std;

bool isPalindrome(long int num) {
    long int rev = 0;
    long int n = num;
    while (n > 0) {
        int rem = n%10;
        rev = rev*10 + rem;
        n /= 10;
    }
    if(rev == num)
        return true;
    return false;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        long int x;
        cin >> x;
        if(isPalindrome(x))
            cout << "wins" << endl;
        else 
            cout << "loses" << endl;
    }
    return 0;
}