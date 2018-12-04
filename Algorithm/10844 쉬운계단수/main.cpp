#include<iostream>
#include<vector>

using namespace std;

int na = 1000000000;
int memo[11][100];
int total = 0;

int dp(int num , int len) {
	
	if (len == 0) {
		total++;
		return 1;
	}
	if (num == 0) {
		memo[num][len] = dp(num + 1, len - 1);
	}
	else if (num == 9) {
		memo[num][len]=dp(num - 1, len - 1);
	}
	else{
		memo[num][len] = dp(num - 1, len - 1) + dp(num + 1, len - 1);
	}
	
}

int main() {
	int input;

	cin >> input;

	for(int i=1 ; i <=9 ; i++)
		dp(i, input);

	//cout << memo[9][input]%na << "\n";
	
	cout << total%na;
}