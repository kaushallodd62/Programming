#include<bits/stdc++.h>
using namespace std;

int Solve(vector<int>& arr, int& x) {
    for(auto i = arr.size()-1; i >= 0; i--) {
        if(arr[i] < x)
            return i+1;
    }
    return 0;

}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr;
        for(auto i=0; i<n; i++) {
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }
        cout << Solve(arr, x) << endl;
    }
    return 0;
}