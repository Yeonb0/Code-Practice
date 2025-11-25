#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	long n, k;
	cin >> n >> k;
	long st = 1, en = k;
	long ans = 0;
	
	while(st <= en) { // binary search
		long mid = (st + en + 1) / 2;
		long count = 0;
		
		// mid 보다 작은 수 몇 개?
		for(int i = 1; i <= n; i++) {
			count += min(mid/i, n);
		}
		if(count < k) { // 오른쪽 선택
			st = mid + 1;
		}
		else { // 왼쪽 선택
			ans = mid;
			en = mid - 1;
		}
	}
	cout << ans;
	
	return 0;
}