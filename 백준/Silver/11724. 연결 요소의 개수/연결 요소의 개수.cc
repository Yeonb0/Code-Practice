#include <iostream>
#include <vector>
using namespace std;

void dfs(int n, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[n] = true; 
	for(int j = 0; j < adj[n].size(); j++) {
    	int next = adj[n][j];
    	if(!visited[next]) {
    		visited[next] = true;
    		dfs(next, adj, visited);
	    }
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// 변수
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n+1);
	vector<bool> visited(n+1, false);
	int ans = 0;
	// 입력
	for(int i = 0; i < m; i++) {
		int a, b; 
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	// 연결 요소 구하기
	for(int i = 1; i <= n; i++) {
		if(!visited[i]) {
			ans++;
			dfs(i, adj, visited);
        }
	}
	cout << ans;
	return 0;
}