#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		int h, w, n;
		cin >> h >> w >> n;
		int a = n % h;
		if (a == 0) a = h;
		int b = (n + h - 1) / h;
		if (b <= 9) cout << a << "0" << b << "\n";
		else cout << a << b << "\n";
	}
	return 0;	
}