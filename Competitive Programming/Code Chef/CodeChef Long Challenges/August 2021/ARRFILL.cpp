#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool cmp(pair<ll int, ll int>& a, pair<ll int, ll int>& b) {
    return a.first > b.first;
}

ll int gcd(ll int a, ll int b) {
    if(b == 0)
        return a;
    return gcd(b, a%b);

}

ll int findSum(vector<pair<ll int, ll int> >& mp, ll n) {
    ll sum = 0, lcm = 1, rem = n;
    for(ll int i = 0; i < mp.size(); i++) {
        ll int x = mp[i].first, y = mp[i].second;
        lcm = (lcm*y) / gcd(lcm, y);
        sum += x*(rem - (n/lcm));
        rem = n/lcm;
    }
    return sum;
}

int main() {
    unsigned int t;
    cin >> t;
    while(t--) {
        ll int n, m;
        cin >> n >> m;
        vector<pair<ll int, ll int> >mp;
        for(ll int i = 0; i < m; i++) {
            ll int x, y;
            cin >> x >> y;
            mp.push_back(make_pair(x, y));
        }
        sort(mp.begin(), mp.end(), cmp);
        cout << findSum(mp, n) << endl;
    }
    return 0;
}