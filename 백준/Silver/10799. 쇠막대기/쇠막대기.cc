#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int count = 0;
	stack<char> s;
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(' && str[i+1] == ')') {
			count += s.size();
			i++;
		}
		else if (str[i] == '(') s.push('(');
		else if (str[i] == ')' && !s.empty()) {
			s.pop();
			count++;
		}
	}
	cout << count;
	return 0;
}