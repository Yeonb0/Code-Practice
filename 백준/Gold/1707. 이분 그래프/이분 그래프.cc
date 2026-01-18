#include <iostream>
#include <vector>
using namespace std;
#define YELLOW 1
#define PURPLE 2

void dfs(int n, const vector<vector<int>>& adj, vector<int>& color) {
	if(color[n] == 0) color[n] = YELLOW; // 첫 노드 색칠
	for(int i = 0; i < adj[n].size(); i++) {
		int next = adj[n][i];
		if(color[next] == 0) {
			color[next] = (color[n] == YELLOW) ? PURPLE : YELLOW;
			dfs(next, adj, color);
        }
	}
}

bool check(int v, const vector<vector<int>>& adj, const vector<int>& color) {
	for(int i = 1; i <= v; i++) {
		for(int j = 0; j < adj[i].size(); j++) {
			int next = adj[i][j];
			if(color[i] == color[next]) return false; 
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int k;
    cin >> k;
	while (k--) {
		int v, e;
		cin >> v >> e;
		vector<vector<int>> adj(v+1);
		vector<int> color(v+1, 0);
		for(int i = 0; i < e; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		for(int i = 1; i <= v; i++) {
			if(color[i] == 0) dfs(i, adj, color);
		}
		if(check(v, adj, color)) cout << "YES\n";
		else cout << "NO\n";
	} 
	return 0;
}