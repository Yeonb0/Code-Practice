#include <iostream>
using namespace std;

// DP 테이블
long DP[91][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    DP[1][0] = 0;
	DP[1][1] = 1;
	
	int n;
	cin >> n;
	
	for(int i = 2; i <= n; i++) {
		DP[i][0] = DP[i-1][0] + DP[i-1][1];
		DP[i][1] = DP[i-1][0];
	}
	
	cout << DP[n][0] + DP[n][1];
	return 0;
}