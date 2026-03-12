#include <iostream>
#include <algorithm>
using namespace std;

int DP[17];
int T[16];
int P[16];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++) { // 1-index
		cin >> T[i] >> P[i];
	}
	
	// DP
	for(int i = n; i > 0; i--) {
		if(i + T[i] > n + 1) { // 퇴사일 초과
			DP[i] = DP[i + 1];
		} else {
			DP[i] = max(DP[i + 1], DP[i + T[i]] + P[i]);
		}
	}
	
	cout << DP[1];
	
	return 0;
}