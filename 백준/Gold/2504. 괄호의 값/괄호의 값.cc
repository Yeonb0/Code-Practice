#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<char> s;
	string str;
	bool right = true;
	int temp = 1, result = 0;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			s.push('(');
			temp *= 2;
		} else if (str[i] == '[') {
			s.push('[');
			temp *= 3;
		} else if (str[i] == ')') {
			if (s.empty() || s.top() != '(') {
				right = false;
				break;
			}	else if (!s.empty() && str[i-1] == '(') {
				result += temp;
			}
			temp /= 2;
			s.pop();
		} else { // ']' 경우
			if (s.empty() || s.top() != '[') {
				right = false;
				break;
			}
			else if (!s.empty() && str[i-1] == '[') {
				result += temp;
			}
			temp /= 3;
			s.pop();
		}
	}
	if (!s.empty()) right = false;
	if (right) cout << result;
	else cout << "0";
	return 0;
}