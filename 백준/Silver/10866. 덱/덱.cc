#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	deque<int> d;
	int num;
	while (t--) {
		string cmd;
		cin >> cmd;
		if (cmd == "push_front") {
			cin >> num;
			d.push_front(num);
		} else if (cmd == "push_back") {
			cin >> num;
			d.push_back(num);
		} else if (cmd == "pop_front") {
			if (d.empty()) cout << "-1\n";
			else {
				cout << d.front() << "\n";
				d.pop_front();
			}
		} else if (cmd == "pop_back") {
			if (d.empty()) cout << "-1\n";
			else {
				cout << d.back() << "\n";
				d.pop_back();
			}
		} else if (cmd == "size") {
			cout << d.size() << "\n";
		} else if (cmd == "empty") {
			if (d.empty()) cout << "1\n";
			else cout << "0\n";
		} else if (cmd == "front") {
			if (d.empty()) cout << "-1\n";
			else {
				cout << d.front() << "\n";
			}
		} else {
			if (d.empty()) cout << "-1\n";
			else {
				cout << d.back() << "\n";
			}
		}
	}
	return 0;
}