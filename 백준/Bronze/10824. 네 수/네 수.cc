#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	a = a + b;
	c = c + d;
	cout << stoll(a) + stoll(c);
	return 0;
}