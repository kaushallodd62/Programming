#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    return a.first > b.first;
}

/*void findSum(pair<pair<int, int>, int>& pr, int n) {
    int x = pr.first.first;
    int y = pr.first.second;
    pr.second = x*((n/y)*(y-1) + (n%y));
    return;
}*/

void arrFill(vector<int>& arr, pair<int, int>& pr) {
    for(int i = 1; i <= arr.size(); i++) {
        if(arr[i-1] == 0 && i%(pr.second) != 0)
            arr[i-1] = pr.first;
    }
    return;
}

int main() {
    unsigned int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> arr(n, 0);
        vector<pair<int, int> >mp;
        for(int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            mp.push_back(make_pair(x, y));
        }

        cout << "Map before Modification: \n";
        for(auto x : mp) {
            cout << x.first << " " << x.second << endl;
        }


        sort(mp.begin(), mp.end(), cmp);


        cout << "Map after Modification: \n";
        for(auto x : mp) {
            cout << x.first << " " << x.second << endl;
        }

        cout << "Vector before Modification: \n{";
        for(auto x : arr) {
            cout << x << " ";
        }
        cout << "}" << endl;


        for(int i = 0; i < m; i++) {
            arrFill(arr, mp[i]);
        }

        cout << "Vector after Modification: \n{";
        for(auto x : arr) {
            cout << x << " ";
        }
        cout << "}" << endl;


        cout << accumulate(arr.begin(), arr.end(), 0) << endl;
    }
    return 0;
}