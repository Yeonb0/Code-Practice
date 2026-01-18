#include <iostream>
#include <vector>
using namespace std;

void dfs(int n, const vector<vector<int>>& adj, vector<bool>& visited) {
	visited[n] = true;
	for(int i = 0; i < adj[n].size(); i++) {
		int next = adj[n][i];
		if(visited[next] == 0) dfs(next, adj, visited);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; 
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<vector<int>> adj(n+1);
		vector<bool> visited(n+1);
		for(int i = 1; i <= n; i++) {
			int a; 
			cin >> a;
			adj[i].push_back(a); // 방향 그래프 이므로 한 쪽만
		}
		int con = 0;
		for(int i = 1; i <= n; i++) {
			if (visited[i] == false) {
				con++;
				dfs(i, adj, visited);
			}
		}
		cout << con << "\n";
	}
	return 0;
}