#include <iostream>
using namespace std;

int GCD(int a, int b) {
	int r;
	r = a % b;
	if(r == 0) return b;
	else return GCD(b, r);
}

int LCD(int a, int b) {
	int gcd = GCD(a, b);
	int lcd = (a*b) / gcd;
	return lcd;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, a, b;
	cin >> t;
	while(t--) {
		cin >> a >> b;
		cout << LCD(a, b) << "\n";
	}	
	return 0;
}