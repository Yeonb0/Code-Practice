#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
int n, c;
ll house[200001];

bool can(ll mid) {
	ll count = 1;
	ll prev = house[0];
	for(int i = 1; i < n; i++) {
		if(house[i] - prev >= mid) {
			count++;
			prev = house[i];
		}
	}
	return (count >= c);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> c;
	for(int i = 0; i < n; i++) cin >> house[i];
	sort(house, house+n);
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