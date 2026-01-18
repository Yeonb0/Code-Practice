#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	int e = 1, s = 1, m = 1;
	int year = 1;
	while(e != a || s != b || m != c) {
		e++;
		if(e == 16) e = 1;
		s++;
		if(s == 29) s = 1;
		m++;
		if(m == 20) m = 1;
		year++;
	}
	cout << year;
	return 0;
}