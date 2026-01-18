#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	cin >> str;
	vector<int> v(str.size(), 0);
	for(int i = 0; i < str.size(); i++) {
		v[i] = str[i] - '0';
	}
	sort(v.begin(), v.end(), greater<int>());
	for(int i = 0; i < str.size(); i++) {
		cout << v[i];
	}	
	return 0;
}