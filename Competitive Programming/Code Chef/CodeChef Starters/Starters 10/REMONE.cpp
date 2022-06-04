#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll int Solve(vector<ll int>& A, vector<ll int>& B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    ll int i=0, j=0;
    while (i<A.size() && j<B.size()) {
        ll int diff = B[j] - A[i];
        if(A[i] < B[j])
            i++;
        else
            j++;
    }
    
}

int main() {
    unsigned int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<ll int> A, B;
        for(int i=0; i<n; i++) {
            int temp;
            scanf("%lld", &temp);
            A.push_back(temp);
        }
        for(int i=0; i<n-1; i++) {
            int temp;
            scanf("%lld", &temp);
            B.push_back(temp);
        }
        cout << Solve(A, B) << endl;
    }
    return 0;