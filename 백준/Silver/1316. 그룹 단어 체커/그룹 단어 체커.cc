#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; 
	int ans = 0;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		bool chk[26] = {false, };
		bool group = true;
		char tmp;
		for(int i = 0; i < s.size(); i++) {
			if(!chk[s[i]-'a']) {
				tmp = s[i];
				chk[tmp-'a'] = true;
			} else {
				if(tmp == s[i]) continue;
				else if (tmp != s[i] && chk[s[i]-'a']) group = false;
			}
		}
		if (group) ans++;
	}
	cout << ans;
	return 0;
}