#include <iostream>
#include <algorithm>
using namespace std;
// DP 테이블
int c[1001];
int dp[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> c[i];
	dp[0] = 0; dp[1] = c[1];
	for(int i = 2; i <= n; i++) {
		dp[i] = c[i];
		for(int j = 1; j <= i/2; j++) 
			dp[i] = max(dp[i], dp[i-j]+dp[j]);
	}
	cout << dp[n];
	return 0;
}