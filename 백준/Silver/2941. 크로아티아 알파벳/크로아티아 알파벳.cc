#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ans = 0;
	string s;
	cin >> s;
	for(int i = 0; i < s.size();) {
		if(i < s.size()-1 &&(s[i+1] == '=' || s[i+1] == '-')) {
			ans++;
			i += 2;
		} else if (i < s.size()-1 && s[i] == 'l' && s[i+1] == 'j') {
			ans++;
			i += 2;
		} else if (i < s.size()-1 && s[i] == 'n' && s[i+1] == 'j') {
			ans++;
			i += 2;
		} else if (i < s.size()-2 && s[i] == 'd' && s[i+1] == 'z' && s[i+2] == '=') {
			ans++;
			i += 3;
		} else {
			ans++;
			i++;
		}
	}
	cout << ans;
	return 0;
}