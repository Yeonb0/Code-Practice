#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num;
	while(1) {
		cin >> num;
		if (num == 0) break;
		string s = to_string(num);
		bool flag = true;
		for(int i = 0; i < (s.length()/2); i++) {
			if(s[i] != s[s.length()-1-i]) {
				flag = false; 
				break;
			}
		}
		if(flag == true) cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}