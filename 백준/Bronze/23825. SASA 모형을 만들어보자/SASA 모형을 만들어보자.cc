#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long a, b;
	cin >> a >> b;
	long long ans = min(a/2, b/2);
	cout << ans;
	return 0;
}