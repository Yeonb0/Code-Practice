#include <iostream>
#include <algorithm>
using namespace std;
// DP 테이블
int DP[2][100001];
int s[2][100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n, num;
	cin >> t;
	while(t--) {
		cin >> n;
		// 스티커 판 입력 받기
		for(int i = 1; i <= n; i++) {
			cin >> num;
			s[0][i] = num;
		}
		for(int i = 1; i <= n; i++) {
			cin >> num;
			s[1][i] = num;
		}
		DP[0][0], DP[1][0] = 0;
		DP[0][1] = s[0][1]; DP[1][1] = s[1][1];
		for(int i = 2; i <= n; i++) {
			DP[0][i] = max(DP[1][i-1], DP[1][i-2]) + s[0][i];
			DP[1][i] = max(DP[0][i-1], DP[0][i-2]) + s[1][i];
		}
		cout << max(DP[0][n], DP[1][n]) << "\n";
	}
	return 0;
}