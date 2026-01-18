#include <iostream>
typedef long long ll;
using namespace std;
int n, m;
ll tree[1000001];

bool can(ll mid) {
	ll cur = 0;
	for(int i = 0; i < n; i++) {
		ll val = tree[i] - mid;
		if(val > 0) cur += val;
	}
	return cur >= m;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> tree[i];
	ll st = 0;
	ll en = 0x7fffffff;
	while(st < en) {
		ll mid = (st+en+1) / 2;
		if(can(mid)) st = mid;
		else en = mid - 1;
	}
	cout << st;
	return 0;	
}