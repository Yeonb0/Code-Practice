#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> A[501];
int t[501];
int deg[501];
int ans[501];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		int tm, b = 0;
		cin >> tm;
		t[i] = tm;
		while(true) {
			cin >> b;
			if(b == -1) break;
			else {
				A[b].push_back(i);
				deg[i]++;
			}
		}
	}
	
	// Topology Sort
	queue<int> q;
	for(int i = 1; i <= n; i++) {
		if(deg[i] == 0) q.push(i);
	}

	while(!q.empty()) {
		int now = q.front();
		q.pop();
		
		for(int nxt : A[now]) {
			deg[nxt]--;
			ans[nxt] = max(ans[nxt], ans[now] + t[now]);
			if(deg[nxt] == 0) q.push(nxt);
		}
	}
	for(int i = 1; i <= n; i++) cout << ans[i] + t[i] << "\n";	
	return 0;
}