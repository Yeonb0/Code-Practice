#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v;
int ans[8];
bool vis[8];

void BT(int len) { // BackTracking
	// break point
	if(len == m) {
		for(int i = 0; i < m; i++) cout << ans[i] << " ";
		cout << "\n";
	}
	int prev = 0;
	for(int i = 0; i < n; i++) {
		if(vis[i]) continue;
		if(prev == v[i]) continue;
		
		vis[i] = true;
		prev = v[i];
        ans[len] = v[i];
		BT(len + 1);
		vis[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	BT(0);
	return 0;
}