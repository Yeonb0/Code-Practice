#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		cout << (s[0]-'0')+(s[2]-'0') << "\n";
	}
	return 0;
}