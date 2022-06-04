#include<iostream>
using namespace std;

int main() {
    long int n, k;
    cin >> n >> k;
    long int ans = 0;
    for (long int i = 0; i < n; i++)
    {
        long int x;
        cin >> x;
        if(x%k == 0)
            ans++;
    }
    cout << ans << endl;
    return 0;
}