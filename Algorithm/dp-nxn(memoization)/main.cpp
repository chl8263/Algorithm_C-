#include<iostream>
#include<algorithm>

using namespace std;

int grid[4][4] = {
	{ 6,7,12,5 },
	{ 5,3,11,18 },
	{ 7,17,3,3 },
	{ 8,10,14,9 }
};

int memo[5][5] = {
	{ -1,-1,-1,-1 },
	{ -1,-1,-1,-1 },
	{ -1,-1,-1,-1 },
	{ -1,-1,-1,-1 }
};

int mat_topdown(int i, int j) {
	if (memo[i][j] != -1) return memo[i][j];
	if (i == 0 && j == 0)
		memo[i][j] = grid[i][j];
	else if (i == 0)
		memo[i][j] = mat_topdown(0, j - 1) + grid[i][j];
	else if (j == 0)
		memo[i][j] = mat_topdown(i - 1, 0) + grid[i][j];
	else
		memo[i][j] = min(mat_topdown(i-1, j), mat_topdown(i,j-1))+grid[i][j];
	
	return memo[i][j];
}

int mat_bottomup(int a, int b) {
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (i == 0 && j == 0)
				memo[i][j] = grid[0][0];
			else if (i == 0)
				memo[i][j] = grid[0][j] + memo[0][j - 1];
			else if (j == 0)
				memo[i][j] = grid[i][0] + memo[i - 1][0];
			else
				memo[i][j] = grid[i][j] + min(memo[i - 1][j], memo[i][j - 1]);
		}
	}
	return memo[a-1][b-1];
}

int main() {

	int i, j;

	cin >> i >> j;

	//cout << mat_topdown(i, j);
	cout << mat_bottomup(i, j);
}