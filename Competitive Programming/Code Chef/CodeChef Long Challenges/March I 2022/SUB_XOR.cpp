#include<bits/stdc++.h>
#define mod 998244353
using namespace std;

long long int binToDec(string& s) {
    long long int dec_value = 0;
    long long int base = 1;
    for(int i = s.size()-1; i >= 0; i--) {
        if(s[i] == '1')
            dec_value += base;
        base *= 2;
    }
    return dec_value;
}

void subarray(string& str, int start, int end, long long int& ans) {
    if(end == str.size())
        return;
    else if(start > end) {
        subarray(str, 0, end+1, ans);
    }
    else {
        string s = str.substr(start, end-start+1);
        ans ^= binToDec(s);
        subarray(str, start+1, end, ans);
    }
}

int main() {
    // ofstream fout("output.txt");
    // ifstream fin("input.txt");
    int t;
    cin >> t;
    while(t--) {
        int n;
        long long int ans=0; string str;
        cin >> n >> str;
        subarray(str, 0, 0, ans);
        cout << ans % mod << endl;
    }
    return 0;
}