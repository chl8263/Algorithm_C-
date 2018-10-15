#include<iostream>

using namespace std;

int search(int data[], int n, int target) {
	for (int i = 0; i < n; i++) {
		if (data[i] == target) {
			return i;
		}
	}
	return -1;
}

int search_recursion(int data[], int begin, int end, int target) {

	if (begin > end) return -1;

	else if (target == data[begin])
		return begin;

	else return search_recursion(data, begin + 1, end, target);



}

int main() {
	int data[] = { 1,2,3,4,5 };

	//cout << search(data, 5, 3);
	cout << search_recursion(data, 0, 4, 3);

}
q
