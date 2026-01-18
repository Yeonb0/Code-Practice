#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
	if (a.length() != b.length()) 
		return a.length() < b.length();
	else return a < b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	vector<string> v;
	string str;
	cin >> n;
	while(n--) {
		cin >> str;
		v.push_back(str);
	}
	sort(v.begin(), v.end(), compare);
	v.erase(unique(v.begin(), v.end()), v.end());
	for(string s : v) cout << s << "\n";
	return 0;
}