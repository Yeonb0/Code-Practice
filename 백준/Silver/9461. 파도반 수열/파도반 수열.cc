#include <iostream>
using namespace std;
// DP 테이블
long long dp[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	dp[1] = 1; dp[2] = 1; dp[3] = 1;
	for(int i = 4; i <= 100; i++) dp[i] = dp[i-2] + dp[i-3];
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		cout << dp[n] << "\n";
	}
	return 0;
}