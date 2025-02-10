#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (true) {
		string str;
		getline(cin, str);
		if(str == ".") break;
		stack<char> stack;
		bool yes = true;
		for (auto c : str) {
			if (c == '[' || c == '(') stack.push(c);
			else if (c == ']') {
				if (!stack.empty() && stack.top() == '[') stack.pop();
				else if (stack.empty() || stack.top() == '(') {
					yes = false;
					break;
				}
			} else if (c == ')') {
				if (stack.empty() || stack.top() == '[') {
					yes = false;
					break;
				} else if (!stack.empty() && stack.top() == '(') stack.pop();
			}
		}
		if (!stack.empty()) yes = false;
		if (yes) cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}