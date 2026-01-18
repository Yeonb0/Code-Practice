#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int money;
		cin >> money;
		int q = 0, d = 0, n = 0, p = 0;
		while(money >= 25) {
			q++;
			money -= 25;
		}
		while(money >= 10) {
			d++;
			money -= 10;
		}
		while(money >= 5) {
			n++;
			money -= 5;
		}
		while(money > 0) {
			p++;
			money -= 1;
		}
		cout << q << " " << d << " " << n << " " << p << "\n"; 
	}
	return 0;
}