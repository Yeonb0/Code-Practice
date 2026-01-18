#include <iostream>
#include <vector>
using namespace std;
vector<int> adj[100001];
int p[100001];

void dfs(int a) {
	for(int next : adj[a]) {
		if(p[a] == next) continue;
		p[next] = a;
		dfs(next);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
    cin >> n;
	for(int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	for(int i = 2; i < n+1; i++) {
		cout << p[i] << "\n";
	}
	return 0;
}