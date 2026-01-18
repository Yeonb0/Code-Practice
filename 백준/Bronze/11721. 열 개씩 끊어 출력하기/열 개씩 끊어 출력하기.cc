#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	for(int i = 0; i <= s.length()/10; i++) {
		cout << s.substr(i*10, 10) << "\n";
	}
	return 0;
}