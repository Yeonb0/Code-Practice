#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dp[501][501]; // dp[i][j] 는 i ~ j 합칠 때의 비용

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	while(T--) {
		int k;
		cin >> k;
		
		vector<int> num(k+1);
		vector<int> sum(k+1); 
		memset(dp, 0x3f, sizeof(dp)); // dp 초기화
		
		sum[0] = 0;
		
		for (int i = 1; i <= k; i++) {
			cin >> num[i];
			sum[i] = sum[i-1] + num[i];
		}
		
		for (int i = 1; i <= k; i++) {
			dp[i][i] = 0;
		}
		
		for (int len = 1; len < k; len++) {       // 구간 길이
			for (int i = 1; i + len <= k; i++) {   // 시작점
				int j = i + len; // 끝점
				for (int mid = i; mid < j; mid++) { 
					dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid+1][j]);
				}
				dp[i][j] += sum[j] - sum[i-1]; // 최솟값에 구간 합 더하기
			}
		}
		cout << dp[1][k] << '\n';
	}
	return 0;
}