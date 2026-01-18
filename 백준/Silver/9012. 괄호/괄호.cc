#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		stack<char> s;
		bool yes = true;
		for (auto c : str) {
			if (c == '(') s.push(c);
			else { // c 가 ')'
				if (s.empty()) {
					yes = false;
					break;
				} else if (!s.empty() && s.top() == '(') s.pop();
			}
		}
		if (!s.empty()) yes = false;
		if (yes) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}