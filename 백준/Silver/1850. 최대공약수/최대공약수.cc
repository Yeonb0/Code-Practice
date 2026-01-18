#include <iostream>
#include <string>
using namespace std;

long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long a, b;
	cin >> a >> b;
	long long res = GCD(a, b);
	while(res > 0) {
		cout << 1;
		res--;
	}
	return 0;
}