#include<bits/stdc++.h>
using namespace std;

long long int Solve(vector<long long int>& v, map<long long int, long long int>& mp) {
    long long int ans = 1;
    sort(v.begin(), v.end());
    for(long long int i=0; i<v.size()-1; i++) {
        if(mp.find(v[i]*v[i+1]) == mp.end()) {
            ans=0;
            break;
        }
    }
    if(ans == 1) {
        long long int product=1;
        for(long long int i=0; i<v.size(); i++) {
            product *= v[i];
        }
        if(mp.find(product) == mp.end())
            ans = 0;
    }
    return ans;
}

int main() {
    unsigned int t;
    cin >> t;
    while(t--) {
        long long int n;
        cin >> n;
        vector<long long int> v;
        map<long long int, long long int> mp;
        for(long long int i=0; i<n; i++) {
            long long int temp;
            cin >> temp;
            v.push_back(temp);
            mp[temp]=1;
        }
        cout << Solve(v, mp) << endl;
    }
    return 0;
}