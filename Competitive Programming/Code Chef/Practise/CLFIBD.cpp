#include<bits/stdc++.h>
using namespace std;

bool Solve(string str) {
    bool ans;
    unordered_map<char, int> mp;
    
}

int main() {
    long int t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        bool isDynamic = Solve(str);
        cout << (isDynamic == true?"Dynamic":"Not") << endl;
    }
    return 0;
}