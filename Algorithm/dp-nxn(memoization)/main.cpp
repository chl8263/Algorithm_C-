#include<iostream>
#include<algorithm>

using namespace std;

int grid[4][4] = {
	{ 6,7,12,5 },
	{ 5,3,11,18 },
	{ 7,17,3,3 },
	{ 8,10,14,9 }
};

int memo[4][4] = {
	{ -1,-1,-1,-1 },
	{ -1,-1,-1,-1 },
	{ -1,-1,-1,-1 },
	{ -1,-1,-1,-1 }
};

int mat(int i, int j) {
	if (memo[i][j] != -1) return memo[i][j];
	if (i == 0 && j == 0)
		memo[i][j] = grid[i][j];
	else if (i == 0)
		memo[i][j] = mat(0, j - 1) + grid[i][j];
	else if (j == 0)
		memo[i][j] = mat(i - 1, 0) + grid[i][j];
	else
		memo[i][j] = min(mat(i-1, j),mat(i,j-1))+grid[i][j];
	
	return memo[i][j];

}

int main() {

	int i, j;

	cin >> i >> j;

	cout << mat(i, j);
}