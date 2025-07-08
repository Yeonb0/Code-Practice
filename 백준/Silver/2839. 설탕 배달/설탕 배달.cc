#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int ans = -1;
	for(int five = n/5; five >= 0; --five) {
		int remain = n - five*5;
		if(remain % 3 == 0) {
			int three = remain / 3;
			ans = five + three;
			break;
		}
	}
	cout << ans;
	return 0;	
}