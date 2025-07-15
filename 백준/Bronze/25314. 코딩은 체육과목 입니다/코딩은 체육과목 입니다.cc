#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while(n >= 4) {
		cout << "long ";
		n -= 4;
	}
	cout << "int";
	return 0;
}