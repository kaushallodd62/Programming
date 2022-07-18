#include<bits/stdc++.h>
using namespace std;

void increment(string& str, int pos) {
    str[pos]++;
    if(str[pos] > '9') {
        str[pos] = '0';
        if(pos > 0)
            increment(str, pos-1);
        else
            str.insert(str.begin(), '1');
    }
}

string Solve(string& str) {
    string str_mod = str;
    for(int i = 0; i < str.size()/2; i++) {
        str_mod[str_mod.size()-i-1] = str_mod[i];
    }
    if(str_mod > str)
        return str_mod;
    str_mod = str;
    increment(str_mod, (str_mod.size()-1)/2);
    for(int i = 0; i < str.size()/2; i++) {
        str_mod[str_mod.size()-i-1] = str_mod[i];
    }
    return str_mod;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        cout << Solve(str) << endl;
    }
    return 0;
}