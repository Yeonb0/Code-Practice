#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> A[32001];
int deg[32001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		A[a].push_back(b);
		deg[b]++;
	}
	
	// Topology Sort
	queue<int> q;
	for(int i = 1; i <= n; i++) {
		if(deg[i] == 0) q.push(i);
	}
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		cout << now << " ";
		for(int next : A[now]) {
			deg[next]--;
			if(deg[next] == 0) q.push(next);
		}
	}
	return 0;	
}