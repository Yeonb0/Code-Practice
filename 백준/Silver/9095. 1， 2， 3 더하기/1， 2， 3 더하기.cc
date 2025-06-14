#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// DP 테이블
	int DP[11];
	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 4;
	for(int i = 4; i <= 10; i++) {
		DP[i] = DP[i-1] + DP[i-2] + DP[i-3];
	}
	
	int n, k;
	cin >> n;
	while(n--) {
		cin >> k;
		cout << DP[k] << "\n";
	}
	
	return 0;
}