#include <iostream>
using namespace std;
// DP 테이블
int a[1001];
int dp[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// 입력
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	dp[n] = 1;
	int ans = 1;
	for(int i = n-1; i >= 1; i--) {
		dp[i] = 1; // 최솟값 설정
			for(int j = n; j > i; j--) {
				if(a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);
			}
		ans = max(ans, dp[i]);
	}
	cout << ans;
	return 0;
}