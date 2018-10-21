#include<iostream>
#include<algorithm>
using namespace std;

int a[301];
int m[301];
int main() {

	int cy;
	cin >> cy;
	for (int i = 1; i <= cy; i++) {
		int tmp;
		cin >> tmp;
		a[i] = tmp;
	}

	for (int i = 1; i <= cy; i++) {
		if (i == 1)
			m[1] = a[1];
		else if (i == 2)
			m[2] = a[2] + m[1];
		else {
			m[i] = max(m[i - 2], a[i - 1] + m[i - 3]) + a[i];
		}
	}
	cout << m[cy];

}