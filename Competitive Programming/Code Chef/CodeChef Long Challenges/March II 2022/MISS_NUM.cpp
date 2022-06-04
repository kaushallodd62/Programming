#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b, c, d;
        bool found = false;
        cin >> a >> b >> c >> d;
        vector<int> arr;
        arr.push_back(a);
        arr.push_back(b);
        arr.push_back(c);
        arr.push_back(d);
        if(a < 0 || b < 0 || c < 0 || d < 0) {
            int diff_index, div_index;
            for(int i=0; i<arr.size(); i++) {
                if(arr[i] < 0)
                    diff_index = i;
                else if(arr[i] == 0)
                    div_index = i;
            }
            vector<int> arr2; 
            for(int i=0; i<4; i++) {
                if(i == diff_index || i == div_index)
                    continue;
                arr2.push_back(arr[i]);
            }
            //Assuming arr2[0] is sum
            int A = (arr2[0] + arr[diff_index])/2;
            int B = A - arr[diff_index];
            if(A*B == arr2[1]) {
                cout << A << " " << B << endl;
                found = true;
            } 
            //Assuming arr2[1] is sum
            A = (arr2[1] + arr[diff_index])/2;
            B = A - arr[diff_index];
            if(A*B == arr2[0]) {
                cout << A << " " << B << endl;
                found = true;
            }
        }
        else {
            for(int i=0; i<4; i++) {
                for(int j=0; j<4; j++) {
                    if(i==j)    
                        continue;
                    //Assuming arr[i] is sum and arr[j] is diff
                    int A = (arr[i] + arr[j])/2;
                    int B = A - arr[j];
                    vector<int> arr2;
                    for(int k=0; k<4; k++) {
                        if(k == i || k == j)
                            continue;
                        arr2.push_back(arr[i]);
                    }
                    if((A*B == arr2[0] && B != 0 && A/B == arr2[1]) || (A*B == arr2[1] && A != 0 && A/B == arr2[0])) {
                        cout << A << " " << B << endl;
                        found = true;
                    }
                }
            }
        }
        if(!found)
            cout << "-1 -1" << endl;
    }
    return 0;
}