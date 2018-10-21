#include<iostream>
#include<algorithm>
using namespace std;

int a[501][501];
int m[50][501];

int main() {


	int input;

	cin >> input;

	for (int i = 1; i <= input; i++) {
		for (int j = 1; j <= i; j++) {
			int t;
			cin >> t;
			a[i][j] = t;
		}
	}

	for (int i = 1; i <= input; i++) {
		for (int j = 1; j <= i; j++) {
			if (i == 1)
				m[1][1] = a[1][1];
			else if (i == j)
				m[i][j] = m[i - 1][j - 1] + a[i][j];
			else if (j == 1)
				m[i][j] = m[i - 1][j] + a[i][j];
			else
				m[i][j] = max(m[i - 1][j - 1], m[i - 1][j]) + a[i][j];
		}
	}
	int k = 0;

	for (int i = 1; i <= input; i++) {
		if (m[input][i] > k)
			k = m[input][i];
	}

	cout << k;
	/*for (int i = input; i >= 1; i--) {
	for (int j = 1; j <= i; j++) {
	m[i][j] = max(m[i + 1][j],m[i+1][j+1])+ a[i][j];
	}
	}

	cout << m[1][1];

	*/
}