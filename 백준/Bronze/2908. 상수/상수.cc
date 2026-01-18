#include <iostream>
#include <string> 
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a, b;
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int ans = max(stoi(a), stoi(b));
	cout << ans;
	return 0;
}