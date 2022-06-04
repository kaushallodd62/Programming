#include<bits/stdc++.h>
using namespace std;

int Solve(vector<int>& arr) {
    int ans=0;
    int mx = INT_MIN, mn = INT_MAX;
    int pos1 = 0, pos2 = 0;
    for(auto i = 0; i < arr.size(); i++) {
        if(i%2 == 1 && arr[i] > mx) {
            mx = arr[i];
            pos1 = i;
        }
        else if(i%2 == 0 && arr[i] < mn) {
            mn = arr[i];
            pos2 = i;
        }
    }
    if(mx > mn) {
        swap(arr[pos1], arr[pos2]);
    }
    for(auto i = 0; i < arr.size(); i++) {
        if(i%2 == 0) {
            ans += arr[i];
        }
        else {
            ans -= arr[i];
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr;
        while(n--) {
            int tmp;
            cin >> tmp;
            arr.push_back(abs(tmp));
        }
        cout << Solve(arr) << endl;
    }
    return 0;
}