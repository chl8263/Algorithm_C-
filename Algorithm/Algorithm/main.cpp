#include<iostream>

using namespace std;

void func(int n) {
	if (n <= 0)
		return;
	else {
		cout << "hello  " << n << "\n";
		func(n - 1);
	}
}

int func2(int n) {
	if (n == 0) {
		return 0;
	}
	else {
		return n + func2(n - 1);
	}
}

int main() {

	//func(4);
	cout << func2(4);
}


/*
#include<iostream>

using namespace std;

int main() {

}

*/