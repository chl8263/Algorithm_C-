#include<iostream>

using namespace std;

/*
	서로 연결된 image pixel 들의 집합을 blob 이라고 부름

	상하좌우 및 대각방향으로도 연결된 것으로 간주
*/


const int BACKGROUND_COLOR = 0;
const int IMAGE_COLOR = 1;
const int ALREADY_COLOR = 2;
const int N = 8;

int grid [N][N] = {
	{ 1, 0, 0, 0, 0, 0, 0, 1 },
	{ 0, 1, 1, 0, 0, 1, 0, 0 },
	{ 1, 1, 0, 0, 1, 0, 1, 0 },
	{ 0, 0, 0, 0, 0, 1, 0, 0 },
	{ 0, 1, 0, 1, 0, 1, 0, 0 },
	{ 0, 1, 0, 1, 0, 1, 0, 0 },
	{ 1, 0, 0, 0, 1, 0, 0, 1 },
	{ 0, 1, 1, 0, 0, 1, 1, 1 },
};

void printGird() {
	for (int i = 0; i < N; i++) {
		cout << "{";
		for (int j = 0; j < N; j++) {
			cout << grid[i][j] << " ,";
		}
		cout << "}\n";
	}
	cout << "\n";
}

int countCells(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= N)
		return 0;

	else if (grid[x][y] != IMAGE_COLOR)
		return 0;
	
	else {
		grid[x][y] = ALREADY_COLOR;

		return 1 + countCells(x - 1, y + 1) + countCells(x, y + 1)
			+ countCells(x + 1, y + 1) + countCells(x - 1, y)
			+ countCells(x + 1, y) + countCells(x - 1, y - 1)
			+ countCells(x, y - 1) + countCells(x + 1, y - 1);
	}
}

int main() {
	printGird();
	cout << countCells(3,5) << "\n\n";
	printGird();
}