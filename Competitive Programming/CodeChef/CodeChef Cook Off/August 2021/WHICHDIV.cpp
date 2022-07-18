#include<bits/stdc++.h>
using namespace std;

int main() {
    unsigned int t;
    cin >> t;
    while(t--) {
        int rating;
        cin >> rating;
        int ans;
        if(rating >= 2000)
            ans = 1;
        else if(rating >= 1600 && rating < 2000)
            ans = 2;
        else
            ans = 3;
        cout << ans << endl;
    }
    return 0;
}