#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int jump[101];
bool vis[101];
int ans;

int BFS(int start);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) { // 사다리
		int x, y;
		cin >> x >> y;
		jump[x] = y;
	}
	
	for(int i = 0; i < m; i++) { // 뱀
		int u, v;
		cin >> u >> v;
		jump[u] = v;
	}
	
	ans = BFS(1);
	cout << ans;
	
	return 0;
}

int BFS(int start) {
	queue<pair<int, int>> q;
	q.push({start, 0});
	vis[start] = true;
	
	while(!q.empty()) {
		auto now = q.front();
		auto count = now.second;
		q.pop();
		
		for(int i = 1; i <= 6; i++) {
			auto next = now.first + i;
			if(next > 100) continue;
			
			if(jump[next] != 0) next = jump[next]; // jump 가능하면 하기
			
			if(!vis[next]) {
				if(next == 100) return count + 1;
				q.push({next, count + 1});
				vis[next] = true;
			}
		}
	}
	return -1;
}