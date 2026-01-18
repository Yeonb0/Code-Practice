#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	getline(cin, str);
	int count = 1;

	if (str.length() == 1 && str[0] == ' ') cout << 0;
	else {
		for (int i = 1; i < str.length()-1; i++) {
			if (str[i] == ' ') count++;
		}
		cout << count;
	}
	
	return 0; 
}