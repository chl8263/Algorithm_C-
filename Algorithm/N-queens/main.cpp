#include<iostream>
#include<math.h>
using namespace std;


const int N = 16;
int backtracking = 0;
int cols[N+1];

void printqueens() {
	int grid[N+1][N+1];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			grid[i][j] = 0;
		}
		grid[i][cols[i]] = 1;
		for (int k = 1; k <= N; k++) {
			cout << grid[i][k] << " ";
		}
		cout << "\n";
	}
}

bool rool(int level) {
	for (int i = 1; i < level; i++) {
		if (cols[i] == cols[level])
			return false;
		else if ((level - i) == abs(cols[level] - cols[i]))
			return false;
	}
	return true;
}

bool queens(int level) {
	if (!rool(level)) {
		return false;
	}
	else if (level == N) {
		printqueens();
		return true;
	}
	for (int i = 1; i <= N; i++) {
		cols[level + 1] = i;
		if (queens(level + 1))
			return true;
		else if (i == N) {
			printqueens();
			cout << "-------backtracking " << ++backtracking << "\n";
		}
	}
	return false;
}

int main() {
	queens(0);
}