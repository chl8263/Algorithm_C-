#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

int main() {
	
	int number; 
	string input;
	vector<string> v;
	int count = 0;

	cin >> number;

	for (int i = 0; i < number; i++) {
		cin >> input;
		v.push_back(input);
		input = "";
	}

	for (int i = 0; i < number; i++) {
		stack<char> s;
		string a = v.at(i);
		for (int j = 0; j < a.size(); j++) {
			s.push(a.at(j));
		}
		for (int k = 0; k < a.size(); k++) {
			//cout << s.top();
			if (s.top() == '(' )
				count++;
			else if(s.top() == ')')
				count--;
			else if (count < 0) {
				cout << "NO\n";
				break;
			}
			s.pop();
		}
		if (count == 0) cout << "YES\n";
		else cout << "NO\n";
		count = 0;
		
	}
}