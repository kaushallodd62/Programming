#include<bits/stdc++>
using namespace std;

string Solve(vector<string>& products) {
    map<string, int> hashmap;
    vector<string> mystr;
    int mx = 0;
    for(auto name : products) {
        hashmap[name] = 0;
    }
    for(auto name : products) {
        hashmap[name]++;
        mx = max(hashmap[name], mx);
    }
    for(auto name : products) {
        if(mx == hashmap[name])
            mystr.push_back(name);
    }
    sort(mystr.begin(), mystr.end());
    string ans = mystr.back();
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<string> products;
    for (int i = 0; i < n; i++) {
        string product_name;
        cin >> product_name;
        products.push_back(product_name);
    }
    string ans = Solve(products);
    cout << ans;
    return 0;
}