#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> DP(500);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) { // 층 
		for(int j = 0; j <= i; j++) { // 칸
			int a;
			cin >> a;
			DP[i].push_back(a);
		}
	}
	
	for(int i = 1; i < n; i++) { // 층
		for(int j = 0; j < DP[i].size(); j++) { // 칸
			if(j == 0) {
				DP[i][j] += DP[i-1][0];
			} else if(j == DP[i].size()-1) {
				DP[i][j] += DP[i-1][j-1];
			} else {
				DP[i][j] = DP[i][j] + max(DP[i-1][j-1], DP[i-1][j]);
			}
		}
	}
	int ans = 0;
	for(int j = 0; j < DP[n-1].size(); j++) { // 칸
		ans = max(ans, DP[n-1][j]);
	}
	cout << ans;
	return 0;
}