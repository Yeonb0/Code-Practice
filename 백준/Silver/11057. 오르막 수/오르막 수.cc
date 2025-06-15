#include <iostream>
using namespace std;

// DP 테이블
int DP[1001][10];
const int MOD = 10007;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int i = 0; i <= 9; i++) DP[1][i] = 1;
	
	int n;
	cin >> n;
	for(int i = 2; i <= n; i++) {
		for(int j = 0; j <= 9; j++) {
			if(j == 0) DP[i][j] = DP[i-1][j];
			else DP[i][j] = (DP[i-1][j] + DP[i][j-1]) % MOD;
		}
	}
	
	int sum = 0;
	for(int i = 0; i <= 9; i++) sum = (sum + DP[n][i]) % MOD;
	cout << sum;
	
	return 0;
}