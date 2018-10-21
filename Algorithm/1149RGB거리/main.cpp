#include<iostream>
#include<algorithm>
using namespace std;

int a[10001][4];
int m[10001][4];

int main() {

	int input;
	cin >> input;

	for (int i = 1; i <= input; i++) {
		for (int j = 1; j <= 3; j++) {
			int b;
			cin >> b;
			a[i][j] = b;
		}
	}

	for (int i = 0; i <= input; i++) {
		m[i][1] = min(m[i - 1][2], m[i - 1][3]) + a[i][1];
		m[i][2] = min(m[i - 1][1], m[i - 1][3]) + a[i][2];
		m[i][3] = min(m[i - 1][2], m[i - 1][1]) + a[i][3];
	}

	cout << min(min(m[input][3],m[input][1]),m[input][2]);
}