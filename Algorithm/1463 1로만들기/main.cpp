#include<iostream>
#include<algorithm>
using namespace std;

int m[10000000];


int dp(int n) {
	if (n == 1) return 0;
	if (m[n] != -1)
		return m[n];
	m[n] = dp(n-1);
	if (n % 2 == 0)
		m[n] = min(dp(n/2),m[n]);
	if (n % 3 == 0)
		m[n] = min(dp(n / 3), m[n]);
	return ++m[n];
}

int main() {

	for (int i = 0; i < 10000000; i++) {
		m[i] = -1;
	}

	int input;

	cin >> input;

	m[1] = 0;

	cout << dp(input);
}