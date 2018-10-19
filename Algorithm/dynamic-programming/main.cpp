#include<iostream>
#include<algorithm>
using namespace std;

int grid[4][4] = { 
	{6,7,12,5},
	{5,3,11,18},
	{7,17,3,3},
	{8,10,14,9}
};

int mat(int i, int j) {
	if (i == 0 && j == 0)
		return grid[0][0];
	if (i == 0)
		return mat(0, j - 1)+grid[i][j];
	if (j == 0)
		return mat(i-1,0) + grid[i][j];
	else 
		return min(mat(i-1,j),mat(i,j-1))+grid[i][j];
}

int main() {


	int i, j;

	cin >> i >> j;
	
	cout << mat(i, j);
}