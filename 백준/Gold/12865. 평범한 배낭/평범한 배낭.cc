#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int W[102];
int V[102];
int DP[102][100001];

void dp() {
	for (int lim = 1; lim <= k; lim++) {
		for (int i = 1; i <= n; i++) {
			// 넣을 수 없으면
			if (W[i] > lim) 
				DP[i][lim] = DP[i-1][lim];
			// 넣을 수 있으면
			else 
				DP[i][lim] = max(DP[i-1][lim-W[i]] + V[i], DP[i-1][lim]);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++) {
		cin >> W[i] >> V[i];
	}
	
	dp();
	cout << DP[n][k];

	return 0;	
}