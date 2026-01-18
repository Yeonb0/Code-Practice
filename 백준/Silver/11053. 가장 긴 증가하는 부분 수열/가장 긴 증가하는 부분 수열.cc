#include <iostream>
#include <algorithm>
using namespace std;
// DP 테이블
int DP[1001];
int a[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	DP[1] = 1;
	int ans = 1;
	for(int i = 2; i <= n; i++) {
		DP[i] = 1; // 최소 길이 설정
		for(int j = 1; j < i; j++) {
			if(a[j] < a[i]) DP[i] = max(DP[i], DP[j]+1);
		}
		ans = max(ans, DP[i]);
	}
	cout << ans;
}