#include <iostream>
#include <algorithm>
using namespace std;
int n, m, k;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	int team = min(n/2, m);
	k -= (n - team*2);
	k -= (m - team);
	while(k > 0) {
		team--;
		k -= 3;
	}
	cout << team;
	return 0;
}