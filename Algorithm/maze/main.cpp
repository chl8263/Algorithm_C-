#include<iostream>

using namespace std;

const int PATH = 0;	// 갈수 있는 경로
const int WALL = 1;	//벽
const int VISITEDBLOCK = 2;	// visited , 출구로 갈 수 없는경우
const int VISITEDPATH = 3;		// visited , 출구로 갈 수 있는경우

const int N = 8;
void printMaze();
int maze [N][N] = {
	{ 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 0, 1, 1, 0, 1, 1, 0, 1 },
	{ 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 0, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 1, 1, 1, 0, 0, 1, 1 },
	{ 0, 1, 0, 0, 0, 1, 0, 1 },
	{ 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 0, 1, 1, 1, 0, 1, 0, 0 }
};


bool findMazePath(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= N)	// 미로의 범위 밖인지 확인
		return false;

	else if (maze[x][y] != PATH)	//갈수있는 경우가 아니면 false
		return false;
	else if (x == N	- 1 && y == N - 1) {	//출구인 경우
		maze[x][y] = VISITEDPATH;
		return true;
	}
	else {
		printMaze();

		maze[x][y] = VISITEDPATH;	//이 위치가 꽝인지 아닌지 모르기때문에 우선3
		if (findMazePath(x - 1, y) || findMazePath(x, y + 1)
			|| findMazePath(x + 1, y) || findMazePath(x, y - 1)) {
			return true;
		}

		maze[x][y] = VISITEDBLOCK;

		return false;

	}
	
	
}

void printMaze() {
	for (int i = 0; i < N; i++) {
		cout << "{";
		for (int j = 0; j < N; j++) {
			cout << maze[i][j] << " ,";
		}
		cout << "}\n";
	}
	cout << "\n";
}

int main() {

	printMaze();
	findMazePath(0, 0);
	printMaze();
}
