#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while (true) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a + b + c == 0) break;
		else if (a * b * c == 0) cout << "wrong\n";
		else {
			int mx = max({a, b, c});
			if (a*a + b*b + c*c == (mx*mx) * 2) cout << "right\n";
			else cout << "wrong\n";
		}
	}
	return 0;
}