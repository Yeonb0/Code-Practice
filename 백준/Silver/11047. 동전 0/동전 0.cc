#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	int ans = 0;
	int arr[11];
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> arr[i];
	for(int i = n-1; i >= 0; i--) {
		if(arr[i] <= k) {
			ans += k / arr[i];
			k %= arr[i];
		}
	}
	cout << ans;
	return 0;
}