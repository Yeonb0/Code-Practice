#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	vector<string> v;
	getline(cin, str);
	for(int i = 0; i < str.size(); i++) {
		v.push_back(str.substr(i, str.size()-i+1));
	}
	sort(v.begin(), v.end());
	for(string s : v) cout << s << "\n";
	return 0;
}