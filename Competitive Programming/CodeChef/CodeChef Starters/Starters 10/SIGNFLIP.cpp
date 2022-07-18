#include<bits/stdc++.h>
using namespace std;

bool cmp (int& a, int& b) {
    return abs(a) > abs(b);
}

int Solve(vector<int>& v, int k) {
    sort(v.begin(), v.end(), cmp);
    int count=0, sum=0;
    for(int i=0; i<v.size(); i++) {
        if(v[i] < 0) {
            if(count<k) {
                sum += abs(v[i]);
                count++;
            }
        }
        else {
            sum += v[i];
        }
    }
    return sum;
}

int main() {
    unsigned int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> v;
        for(int i=0; i<n; i++) {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }
        cout << Solve(v, k) << endl;
    }
    return 0;
}