#include <iostream>
using namespace std;
// DP 테이블
int s[301];
int dp[301];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> s[i];
	dp[1] = s[1]; dp[2] = s[1] + s[2];
	for(int i = 3; i <= n; i++) {
		dp[i] = max(dp[i-2], dp[i-3] + s[i-1]) + s[i];
	}
	cout << dp[n];
	return 0;
}