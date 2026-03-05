#include <iostream>
using namespace std;
int DP[31][31];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for(int i = 0; i < 31; i++) {
		DP[i][0] = 1;
		DP[i][1] = i;
		DP[i][i] = 1;
	}
	for(int i = 2; i < 31; i++) { // DP 테이블 만들기
		for(int j = 1; j < i; j++) {
			DP[i][j] = DP[i-1][j] + DP[i-1][j-1];
		}
	}
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		cout << DP[m][n] << "\n";
	}
	return 0;
}