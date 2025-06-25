#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	getline(cin, str);
	for(char& c : str) {
		if (isupper(c)) {
			c = ((c - 'A' + 13) % 26 + 'A');
		} else if (islower(c)) {
			c = ((c - 'a' + 13) % 26 + 'a');
		}
	}
	cout << str;
	return 0;
}