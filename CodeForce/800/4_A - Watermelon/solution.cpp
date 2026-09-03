#include <iostream>
using namespace std;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int kilo;
	cin >> kilo;
	
	if (kilo == 2) {
		cout << "NO";
	} else {
		if ((kilo % 2) == 0) cout << "YES";
		else cout << "NO";
	}
	return 0;
}