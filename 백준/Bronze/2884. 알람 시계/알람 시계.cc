#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int h, m;
	cin >> h >> m;
	if (m >= 45) {
		m -= 45;
	} else {
		m += 15;
		if (h == 0) {
			h = 23;
		} else h--;
	}
	cout << h << " " << m;
	return 0;
}