#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	bool pel = true;
	cin >> s;
	for(int i = 0; i < s.size()/2; i++) {
		if(s[i] != s[s.size()-1-i]) pel = false;
	}
	if(pel) cout << 1;
	else cout << 0;
	return 0;
}