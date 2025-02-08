#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	cin >> str;
	int n;
	cin >> n;
	cout << str[n-1];
	
	return 0;
}