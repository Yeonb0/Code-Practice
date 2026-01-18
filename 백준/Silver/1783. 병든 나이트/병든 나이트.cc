#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int ans;
	if(n == 1) ans = 1;
	else if(n == 2) ans = min(4, (m+1)/2);
	else if(m < 7) ans = min(4, m);
	else ans = m-2;
	cout << ans;
}