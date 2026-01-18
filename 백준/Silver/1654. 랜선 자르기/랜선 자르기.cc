#include <iostream>
typedef long long ll;
using namespace std;
int n, k;
int lan[10001];

bool can(int mid) {
	ll cur = 0;
	for(int i = 0; i < k; i++) {
		cur += lan[i] / mid;
	}
	return cur >= n;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> k >> n;
	for(int i = 0; i < k; i++) cin >> lan[i];
	ll st = 1;
	ll en = 0x7fffffff;
	// 이분 탐색
	while(st < en) {
		ll mid = (st+en+1) / 2;
		if(can(mid)) st = mid;
		else en = mid-1;
	}
	cout << st;
	return 0;
}