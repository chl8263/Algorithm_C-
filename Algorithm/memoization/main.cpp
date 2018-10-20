#include<iostream>

using namespace std;

/*
	�Ǻ���ġ Ȥ�� �ٸ� ������ recursion �� �̿��Ͽ� �ذ��Ҷ�
	���������� �ݺ� �ȴ�. �� ���� ������ �ݺ��Ǿ� ������尡 
	���� �Ǿ� ��ȿ������ �ڵ尡 �ȴ�.
	
	memoization �� �ߺ��� �����ϱ� ���� ĳ�� ��� �Ҹ��� �迭�� 
	�ϳ� �����Ͽ� ĳ�ÿ� ���� �ִٸ� �ߺ������� �����ʰ� 
	���� ȣ���ϰ� �ȴ�.
*/

int cache[];

int fib(int n) {
	if (n == 0 || n == 1)
		return 1;
	else if (cache[n] > -1)
		return cache[n];
	else {
		cache[n] = fib(n - 1) + fib(n - 2);
		return cache[n];
	}
}

int main() {
	int number;
	cin >> number;

	for (int i = 0; i < number; i++) {
		cache[i] = -1;
	}

	int a =fib(number);

	cout << a;
	

}