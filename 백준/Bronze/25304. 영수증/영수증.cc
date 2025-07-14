#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tot, n;
	cin >> tot >> n;
	int chk = 0;
	while(n--) {
		int a, b;
		cin >> a >> b;
		chk += a * b;
	}
	if(chk == tot) cout << "Yes";
	else cout << "No";
	return 0;
}