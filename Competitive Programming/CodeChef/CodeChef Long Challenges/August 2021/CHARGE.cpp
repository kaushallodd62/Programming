#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int, pair<int, int> >& a, pair<int, pair<int, int> >& b) {
    return a.second.second < b.second.second;
}

void Solve(vector<pair<int, pair<int, int> > >& vp) {
    vector<pair<int, pair<int, int> > > ans;
    sort(vp.begin(), vp.end(), cmp);
    int l=0, r=0; int time=0;
    for(auto itr = vp.begin(); itr != vp.end(); itr++) {
        int a = (itr->second).first, t = (itr->second).second;
        if(a <= t && time+a <= t) {
            l = r;
            r = l+a;
            time = r;
            ans.push_back({itr->first, {l, r}});
        }
    }
    cout << ans.size() << endl;
    for(auto x : ans) {
        cout << x.first << " " << x.second.first << " " << x.second.second << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> A, T;
        vector<pair<int, pair<int, int> > > vp;
        for(int i=0; i<n; i++) {
            int a;
            cin >> a;
            A.push_back(a);
        }
        for(int i=0; i<n; i++) {
            int t;
            cin >> t;
            T.push_back(t);
        }
        for(int i=0; i<n; i++) {
            vp.push_back({i+1, {A[i], T[i]}});
        }
        Solve(vp);
    }
    return 0;
}
