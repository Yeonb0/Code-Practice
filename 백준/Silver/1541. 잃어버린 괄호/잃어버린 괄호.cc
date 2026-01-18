#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split(string input, char ch) {
	vector<string> result;
	stringstream mystream(input);
	string splitdata;
	
	while(getline(mystream, splitdata, ch)) {
		result.push_back(splitdata);
	}
	return result;
}

int sumString(string a){
	int sum = 0;
	vector<string> nums = split(a, '+');
	for(string s : nums) {
		sum += stoi(s);
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string st;
	cin >> st;
	int ans = 0;
	vector<string> list = split(st, '-');
	for(int i = 0; i < list.size(); i++) {
		int temp = sumString(list[i]);
		if(i == 0) ans += temp;
		else ans -= temp;
	}
	cout << ans;
	return 0;
}