#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void dfs(int v, const vector<vector<int>>& arr, vector<bool>& visit, vector<int>& dfs_res) {
	for (int i = 0; i < arr[v].size(); i++) {
		int next = arr[v][i];
		if (!visit[next]) {
			visit[next] = true;
			dfs_res.push_back(next);
			dfs(next, arr, visit, dfs_res);
		}
	}
}

void bfs(int v, const vector<vector<int>>& arr, vector<bool>& visit, vector<int>& bfs_res) {
	queue<int> q;
	q.push(v);
	visit[v] = true;

	while (!q.empty()) {
		int curr = q.front(); q.pop();
		bfs_res.push_back(curr);

		for (int i = 0; i < arr[curr].size(); i++) {
			int next = arr[curr][i];
			if (!visit[next]) {
				visit[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, v;
	cin >> n >> m >> v;

	vector<vector<int>> adj(n + 1);
	vector<bool> dfs_visit(n + 1, false);
	vector<bool> bfs_visit(n + 1, false);
	vector<int> dfs_result;
	vector<int> bfs_result;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end());
	}

	// DFS
	dfs_visit[v] = true;
	dfs_result.push_back(v);
	dfs(v, adj, dfs_visit, dfs_result);
	for (auto n : dfs_result) cout << n << " ";
	cout << "\n";

	// BFS
	bfs(v, adj, bfs_visit, bfs_result);
	for (auto n : bfs_result) cout << n << " ";
	cout << "\n";

	return 0;
}
