#include<iostream>
#include<vector>
using namespace std;


vector<int> v;
vector<int> v2;

int main() {
	
	
	while (1) {
		int input;
		cin >> input;
		if (input == 0)
			break;
		v.push_back(input);
	}
	
	
	
	for (int i = 0; i < v.size(); i++) {
		int a = v.at(i);
		int count = 0;
		for (int j = a+1; j <= a*2; j++) {
			for (int k = 1; k < j; k++) {
				if (j%k == 0)
					if(k != 1)
						break;
				if (k == j-1)
					count++;
			}
			
		}
		v2.push_back(count);
		count = 0;
	}

	for (int i = 0; i < v2.size(); i++) {
		cout << v2.at(i) <<"\n";
	}

}