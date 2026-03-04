#include <iostream>
using namespace std;
int DP[1001][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k; 
	cin >> n >> k;
	for(int i = 0; i <= n; i++) { // DP table 초기화
		DP[i][0] = 1;
		DP[i][i] = 1;
		DP[i][1] = i;
	}
	for(int i = 2; i <= n; i++) {
		for(int j = 1; j < i; j++) {
			DP[i][j] = DP[i-1][j] + DP[i-1][j-1];
			DP[i][j] %= 10007;
		}
	}
	cout << DP[n][k];
}