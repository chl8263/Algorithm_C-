#include<iostream>
#include<vector>
using namespace std;

int main() {
	
	int testcase;

	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		int flag =0;
		int total;
		int choice;
		int count=0;
		vector<int>v;
		vector<int>v2;
		cin >> total;
		cin >> choice;
		
		
		for (int j = 0; j < total; j++) {
			v.push_back(j);
			int p;
			cin >> p;
			v2.push_back(p);
		}

		while (flag == 0) {
			for (int k = 1; k < v.size(); k++) {
				if (v.at(0) < v.at(k)) {
					v.push_back(v.at(0));
					v.erase(v.begin());
					v2.push_back(v2.at(0));
					v2.erase(v2.begin());
					break;
				}
				else if(k == v.size()-1) {
					int temp = v.at(0);
					v.erase(v.begin());
					v2.erase(v2.begin());
					count++;

					if (temp == choice) {
						cout << count;
						count = 0;
						flag = 1;
					}
					
				}
			}
		}
		flag = 0;
	}

}