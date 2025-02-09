#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int sum = 0;
		int up = 1;
		string str;
		cin >> str;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == 'O') sum += up++;
			else up = 1;
		}
		cout << sum << "\n";
	}
	return 0;
}