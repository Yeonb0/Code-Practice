#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> adj[10001];
vector<bool> visit(10001, false);
int n, k;
int dis; 

void dfs(int node, int cur) {
	visit[node] = true;
	if(cur > dis) {
		dis = cur;
		k = node;
	}
	for(auto next : adj[node]) {
		if(!visit[next.first]) {
			dfs(next.first, cur + next.second);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// 입력
	cin >> n;
	for(int i = 1; i < n; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		adj[a].push_back({b, d});
		adj[b].push_back({a, d});
	}
	
	// dfs
	dfs(1, 0);
	for(int i = 1; i <= n; i++) visit[i] = false;
	dis = 0;
	dfs(k, 0);
	cout << dis;
	return 0;
}