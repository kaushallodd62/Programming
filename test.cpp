#include<bits/stdc++.h>
using namespace std;

struct compare {
    bool operator () (const pair<int, int>& a, const pair<int, int>& b) {

    }
};

int arrayValue (int n, int k, int a[], int b[]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; i++) {
        pq.push({a[i], i});
    }

    int count = 0, sum = 0;
    int mn;
    while (count < k) {
        pair<int, int> ele = pq.top();
        pq.pop();

        if (count == 0) {
            mn = ele.first;
        }
        sum += b[ele.second];
        count++;
    }

    return mn * mn * sum;
}

int main () {

}   