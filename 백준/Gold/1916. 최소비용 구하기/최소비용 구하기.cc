#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 0x3f3f3f3f
typedef pair<int, int> node;

int n, m;
vector<node> A[1001];
bool visited[1001];
int cost[1001];
priority_queue<node, vector<node>, greater<node>> q;

int dijkstra(int s, int e) {
	q.push({0, s});
	cost[s] = 0;
	
	while(!q.empty()) {
		auto now_n = q.top();
		q.pop();
		int now = now_n.second;
		
		if(!visited[now]) {
			visited[now] = true;
			
			for(auto n : A[now]) {
				if(cost[n.first] > cost[now] + n.second) {
					cost[n.first] = cost[now] + n.second;
					q.push({cost[n.first], n.first});
				}
			}
		}
	}
	return cost[e];
}				
				
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	fill(cost, cost + 1001, INF);
	
	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		A[u].push_back({v, w});
	}
	int st, en;
	cin >> st >> en;
	int ans = dijkstra(st, en);
	cout << ans;
	return 0;
}