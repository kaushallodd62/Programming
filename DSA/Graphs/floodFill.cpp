#include <bits/stdc++.h>
using namespace std;

struct hashFunction {
    size_t operator() (const pair<int, int> &a) const {
        return a.first ^ a.second;
    }
};

bool isSafe (vector<vector<int>>& image, int sr, int sc) {
    return (sr >= 0 && sc >= 0 && sr < image.size() && sc < image[sr].size());
}

void floodFillAux (vector<vector<int>>& image, vector<vector<int>>& dest, int sr, int sc, int newColor, int oldColor, unordered_set<pair<int, int>, hashFunction>& visitedEdges) {
    dest[sr][sc] = newColor;
    visitedEdges.insert ({sr, sc});

    if (isSafe (image, sr-1, sc) && visitedEdges.find ({sr-1, sc}) == visitedEdges.end() && image[sr-1][sc] == oldColor)
        floodFillAux (image, dest, sr-1, sc, newColor, oldColor, visitedEdges);

    if (isSafe (image, sr, sc-1) && visitedEdges.find ({sr, sc-1}) == visitedEdges.end() && image[sr][sc-1] == oldColor)
        floodFillAux (image, dest, sr, sc-1, newColor, oldColor, visitedEdges);

    if (isSafe (image, sr+1, sc) && visitedEdges.find ({sr+1, sc}) == visitedEdges.end() && image[sr+1][sc] == oldColor)
        floodFillAux (image, dest, sr+1, sc, newColor, oldColor, visitedEdges);

    if (isSafe (image, sr, sc+1) && visitedEdges.find ({sr, sc+1}) == visitedEdges.end() && image[sr][sc+1] == oldColor)
        floodFillAux (image, dest, sr, sc+1, newColor, oldColor, visitedEdges);

    return;
}

// DFS solution

vector<vector<int>> floodFill (vector<vector<int>>& image, int sr, int sc, int newColor) {
    vector<vector<int>> dest (image);
    unordered_set<pair<int, int>, hashFunction> visitedEdges;
    if (isSafe (image, sr, sc))
        floodFillAux (image, dest, sr, sc, newColor, image[sr][sc], visitedEdges);
    else return {{}};

    return dest;
}