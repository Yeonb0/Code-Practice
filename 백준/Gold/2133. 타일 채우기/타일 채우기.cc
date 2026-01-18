#include <iostream>
using namespace std;
// DP 테이블
int dp[31];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	if(n % 2 != 0) { // 홀수면 경우 X
		cout << 0; 
		return 0;
	} else { 
		dp[0] = 1;
		dp[2] = 3;
		for(int i = 4; i <= n; i += 2) {
			dp[i] = (dp[i-2] * dp[2]); 
			for(int j = 4; j <= i; j +=2) {
				dp[i] += (dp[i-j] * 2);
			}
		}
		cout << dp[n];
		return 0;
	}
}