#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define ff first
#define ss second
#define ii pair<int,int>
#define vii vector<ii>
#define INF 1000000000
#define mod 1000000007
#define ll long long
#define ull unsigned long long
#define ld long double
const double PI = 3.141592653589793238460;
#define cz(x) 63 - __builtin_clzll(x)
using namespace std;
using namespace __gnu_pbds;
template<class T> using oset =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void INPUT() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

// Solution
int foo (int n, int remaining, vi arr) {
    if (n == 0)
        return 1;

    if (arr[n-1] > remaining)
        return foo (n-1, remaining, arr);
    else 
        return foo (n-1, remaining - arr[n-1], arr) + foo (n-1, remaining, arr);
}

int main() {
	FIO
	INPUT();

	int t = 1;
	cin >> t;
	while (t--) {
		int n;
        vi arr;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << foo (n, n-1, arr) << endl;
	}
	return 0;
}