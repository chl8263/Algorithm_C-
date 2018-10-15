#include<iostream>

using namespace std;

const int PATH = 0;	// ���� �ִ� ���
const int WALL = 1;	//��
const int VISITEDBLOCK = 2;	// visited , �ⱸ�� �� �� ���°��
const int VISITEDPATH = 3;		// visited , �ⱸ�� �� �� �ִ°��

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
	if (x < 0 || y < 0 || x >= N || y >= N)	// �̷��� ���� ������ Ȯ��
		return false;

	else if (maze[x][y] != PATH)	//�����ִ� ��찡 �ƴϸ� false
		return false;
	else if (x == N	- 1 && y == N - 1) {	//�ⱸ�� ���
		maze[x][y] = VISITEDPATH;
		return true;
	}
	else {
		printMaze();

		maze[x][y] = VISITEDPATH;	//�� ��ġ�� ������ �ƴ��� �𸣱⶧���� �켱3
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
