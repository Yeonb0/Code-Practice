#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> A(2000);
vector<bool> visited(2000, false);
bool arrive = false;

void DFS(int node, int depth) {
	if(depth == 5 || arrive) {
		arrive = true;
		return;
	}
	visited[node] = true;
	for(int i : A[node]) {
		if(!visited[i]) {
			DFS(i, depth + 1);
		}
	}
    visited[node] = false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		A[a].push_back(b);
		A[b].push_back(a);
	}
	for(int i = 0; i < n; i++) {
		DFS(i, 1);
		if(arrive) break;
	}
	if(arrive) cout << 1;
	else cout << 0;
	return 0;
}