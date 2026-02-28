#include <iostream>
#include <algorithm>
using namespace std;

int DP[1001][3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> DP[i][0] >> DP[i][1] >> DP[i][2];
	}
	
	for(int i = 1; i < n; i++) {
		DP[i][0] = DP[i][0] + min(DP[i-1][1], DP[i-1][2]); // R 최소
		DP[i][1] = DP[i][1] + min(DP[i-1][0], DP[i-1][2]); // G 최소
		DP[i][2] = DP[i][2] + min(DP[i-1][0], DP[i-1][1]); // B 최소
	}
	cout << min(min(DP[n-1][0], DP[n-1][1]), DP[n-1][2]);
	return 0;
}