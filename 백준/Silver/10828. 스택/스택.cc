#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string cmd;
	int num, x;
	stack<int> stack;
	
	cin >> num;
	for (int i = 0; i < num; i++) {
			cin >> cmd;
			if (cmd == "push") {
					cin >> x;
					stack.push(x);
			} else if (cmd == "pop") {
					if (stack.empty()) cout << -1 << "\n";
					else {
							cout << stack.top() << "\n";
							stack.pop();
					}
			} else if (cmd == "size") {
					int size = stack.size();
					cout << size << "\n";
			} else if (cmd == "empty") {
					if (stack.empty()) cout << 1 << "\n";
					else cout << 0 << "\n";
			} else {
					if (stack.empty()) cout << -1 << "\n";
					else {
						cout << stack.top() << "\n";
					}
			}
	}
	return 0;
}