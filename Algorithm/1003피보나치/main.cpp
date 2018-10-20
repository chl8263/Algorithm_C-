#include<iostream>
#include<vector>
using namespace std;

int m[2] = { 0,0 };
int cache[1000];
int cache0[1000];
int cache1[1000];
int fibo(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else if (cache[n] > -1) {
		cache[n];
		return cache[n];
	}
	else {
		cache[n] = fibo(n - 1) + fibo(n - 2);
		cache0[n] = cache0[n - 1] + cache0[n - 2];
		cache1[n] = cache1[n - 1] + cache1[n - 2];
		return cache[n];
	}

}

int main() {
	int t;
	int t2;
	vector<int> v;

	cache0[0] = 1;
	cache1[1] = 1;

	for (int i = 0; i < 1000; i++) {
		cache[i] = -1;
	}

	cin >> t;
	t2 = t;
	while (t2--) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	for (int i = 0; i < t; i++) {
		fibo(v.at(i));
		cout << cache0[v.at(i)] << " " << cache1[v.at(i)] << "\n";
		m[0] = 0;
		m[1] = 0;
	}
}