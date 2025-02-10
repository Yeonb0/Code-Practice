#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; 
	cin >> t;
	int count = 0;
	while (t--) {
		stack<char> s;
		string str;
		cin >> str;
		for (auto c : str) {
			if (s.empty()) s.push(c);
			else if (!s.empty() && s.top() == 'A') {
				if (c == 'A') s.pop();
				else s.push(c); // 'B'를 push
			} else if (!s.empty() && s.top() == 'B') {
				if (c == 'B') s.pop();
				else s.push(c); // 'A'를 push
			}
		}
		if (s.empty()) count++;
	}
	cout << count;
	return 0;
}