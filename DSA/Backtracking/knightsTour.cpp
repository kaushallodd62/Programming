#include<bits/stdc++.h>
using namespace std;

bool isInside(int x, int y, int N) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

bool knightsTour(int N) {
    vector<vector<int>> soln(N, vector<int>(N, 0));
    // since the knight starts with (0, 0)
    soln[0][0] = 0;

}