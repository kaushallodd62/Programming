#include<iostream>
#include<vector>
using namespace std;

void subArray(const vector<int> &arr, int begin, int end, vector<vector<int> > &ans) {
    if(end == arr.size())
        return;
    else if(begin > end){
        subArray(arr, 0, end+1, ans);
    }
    else{
        vector<int> subarr;
        for(int i = begin; i <= end; i++) {
            subarr.push_back(arr[i]);
        }
        ans.push_back(subarr);
        subArray(arr, begin+1, end, ans);
    }
    return;
}

vector<int> Solve(vector<int> &A, vector<vector<int> > &B) {
    vector<int> ans;
    for(int i = 0; i < B.size(); i++){
        if(B[i][0] == 1) {
            for(int k = 0; k < A.size(); k++) {
                if(A[k] == B[i][1])
                    A[k] = B[i][2];
            }
        }
        else {
            int mx = INT_MIN;
            vector<int> subarr;
            vector<vector<int> > possible_subarr;
            for(int k = B[i][1] - 1; k < B[i][2]; k++)
                subarr.push_back(A[k]);
            subArray(subarr, 0, 0, possible_subarr);
            for(auto m = possible_subarr.begin(); m != possible_subarr.end(); m++){
                int sum = 0; bool neg = false;
                for(auto n = m->begin(); n != m->end(); n++){
                    if(neg == false) {
                        sum += *n;
                        neg = true;
                    }
                    else{
                        sum += (-1)*(*n);
                        neg = false;
                    }
                }
                mx = max(mx, sum);
            }
            ans.push_back(mx);
        }
    }
    return ans;
}

int main() {
    vector<int> A;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        A.push_back(x);
    }
    vector<vector<int> > B;
    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<int> arr;
        for(int j = 0; j < 3; j++) {
            int x;
            cin >> x;
            arr.push_back(x);
        }
        B.push_back(arr);
    }
    vector<int> ans = Solve(A, B);
    for(auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";
    cout << endl;
}


