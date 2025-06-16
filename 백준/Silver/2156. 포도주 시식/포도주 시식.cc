#include <iostream>
#include <algorithm>
using namespace std;
// DP 테이블
int DP[10001];
int g[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, num, sum = 0;
	cin >> n;
	// 포도주 채우기
	for(int i = 1; i <= n; i++) {
		cin >> num;
		g[i] = num;
	}
	DP[1] = g[1]; DP[2] = g[1] + g[2];
	for(int i = 3; i <= n; i++) {
		DP[i] = max(DP[i-2], DP[i-3]+g[i-1]) + g[i];
		DP[i] = max(DP[i], DP[i-1]);
	}
	cout << DP[n];
	
	return 0;
}