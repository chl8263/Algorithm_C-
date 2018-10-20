#include<iostream>

using namespace std;

/*
	피보나치 혹은 다른 문제를 recursion 을 이용하여 해결할때
	같은연산이 반복 된다. 즉 같은 연산이 반복되어 오버헤드가 
	증가 되어 비효율적인 코드가 된다.
	
	memoization 은 중복을 제거하기 위해 캐시 라고 불리는 배열을 
	하나 선언하여 캐시에 값이 있다면 중복연산을 하지않고 
	값을 호출하게 된다.
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