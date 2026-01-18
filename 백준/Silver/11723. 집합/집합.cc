#include <iostream>
#include <set>
#include <string>
using namespace std;

set<int> S;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m, x;
	string con;
	cin >> m;
	while (m--) {
		cin >> con;
		if (con == "add") {
			cin >> x;
			S.insert(x);
		} else if (con == "remove") {
			cin >> x;
			S.erase(x);
		} else if (con == "check") {
			cin >> x;
			cout << S.count(x) << "\n";
		} else if (con == "toggle") {
			cin >> x;
			if(S.count(x) == 0) S.insert(x);
			else S.erase(x);
		} else if (con == "all") {
			for (int i = 1; i <= 20; i++) S.insert(i);
		} else if (con == "empty") {
			S.erase(S.begin(), S.end());
		}
	}
	return 0;
}