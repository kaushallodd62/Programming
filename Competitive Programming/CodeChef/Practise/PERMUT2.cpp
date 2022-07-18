#include<bits/stdc++.h>
using namespace std;



bool isAmbiguous(const vector<int>& v, const unordered_map<int, int> mp) {
    vector<int> inv_v;
    int n = v.size();
    for(int i = 0; i < n; i++) {
        inv_v.push_back(mp.find(i+1)->second + 1);
    }
    return v == inv_v;
}

int main() {
    int n;
    cin >> n;
    while(n) {
        vector<int> v;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            v.push_back(temp);
            mp.insert({temp, i});
        }
        if(isAmbiguous(v, mp))
            cout << "ambiguous" << endl;
        else
            cout << "not ambiguous" << endl;
        cin >> n;
    }
    return 0;
}