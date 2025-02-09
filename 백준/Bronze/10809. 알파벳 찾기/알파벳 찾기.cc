#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	cin >> str;		
	for (char cr = 'a'; cr <= 'z'; cr++) {
		cout << (int)str.find(cr) << " ";
	}
	return 0;
}