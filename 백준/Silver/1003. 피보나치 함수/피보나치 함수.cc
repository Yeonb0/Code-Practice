#include <iostream>
#include <utility>
using namespace std;
pair<int, int> dp[41];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    dp[0] = {1, 0};
    dp[1] = {0, 1};
	for(int i = 2; i < 41; i++) {
		dp[i].first = dp[i-1].first + dp[i-2].first;
		dp[i].second = dp[i-1].second + dp[i-2].second;
	}
	int t;
	cin >> t;
	while(t--) {
		int a;
		cin >> a;
		cout << dp[a].first << " " << dp[a].second << "\n";
	}
	return 0;
}