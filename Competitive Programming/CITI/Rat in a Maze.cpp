#include<bits/stdc++.h>
using namespace std;

bool isAllowed(vector<vector<int> > maze, int x_pos, int y_pos) {
	if(x_pos >= 0 && x_pos < maze.size() && y_pos >= 0 && y_pos < maze[x_pos].size() && maze[x_pos][y_pos] == 1)
		return true;
	return false;
}

int solveRec(vector<vector<int> > maze, int x_pos, int y_pos, vector<vector<int> > soln){
	if(maze[x_pos][y_pos] == 9) {
		soln[x_pos][y_pos] = 1;
		return 1;
	}
	if(isAllowed(maze, x_pos, y_pos) == true) {
		if(soln[x_pos][y_pos] == 1)
			return 0;
		if(solveRec(maze, x_pos+1, y_pos, soln) == true)
			return 1;
		if(solveRec(maze, x_pos, y_pos+1, soln) == true)
			return 1;
		if(solveRec(maze, x_pos-1, y_pos, soln) == true)
			return 1;
		if(solveRec(maze, x_pos, y_pos-1, soln) == true)
			return 1;
		soln[x_pos][y_pos] = 0;
		return false;
	}
	return false;
}

int main() {
	int n, m, x_dest, y_dest;
	cin >> n >> m;
	vector<vector<int> > maze;
	for(int i = 0; i < n; i++) {
		vector<int> temp_vector;
		for(int j = 0; j < m; j++) {
			int temp;
			cin >> temp;
			temp_vector.push_back(temp);
		}
		maze.push_back(temp_vector);
	}
	
	vector<vector<int> > soln;
	for(int i = 0; i < n; i++) {
		vector<int> temp_vector;
		for(int j = 0; j < m; j++) {
			temp_vector.push_back(0);
		}
		soln.push_back(temp_vector);
	}
	
	int ans = solveRec(maze, 0, 0, soln);
	cout << ans;
	return 0;
}