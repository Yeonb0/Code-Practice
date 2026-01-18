#include <iostream>
using namespace std;

int GCD(int a, int b) {
	int r;
	r = a % b;
	if(r == 0) return b;
	else return GCD(b, r);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int a, b;
	cin >> a >> b;
	int g;
	if (a > b) g = GCD(a, b);
	else g = GCD(b, a);
	int l = (a * b) / g;
	cout << g << "\n" << l;
	
	return 0;
}