#include <iostream>
#include <algorithm>
using namespace std;
// dp 테이블
int a[1001];
int up[1001];
int down[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	up[1] = down[n] = 1;
	// 가장 긴 증가
	for(int i = 2; i <= n; i++) {
		up[i] = 1;
		for(int j = 1; j < i; j++) {
			if(a[j] < a[i]) up[i] = max(up[j] + 1, up[i]);
		}
	}
	// 가장 긴 감소
	for(int i = n-1; i >= 1; i--) {
		down[i] = 1;
		for(int j = n; j > i; j--) {
			if(a[i] > a[j]) down[i] = max(down[j] + 1, down[i]);
		}
	}
	int ans = 1;
	for(int i = 1; i <= n; i++) ans = max(ans, (up[i]+down[i]-1));
	cout << ans;
	return 0;
}