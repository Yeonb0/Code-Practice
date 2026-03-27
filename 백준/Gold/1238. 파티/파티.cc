#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> node;
const ll INF = 4e18;

int n, m, x;
vector<node> graph[100001]; 
vector<node> rev_graph[100001];

ll dist[100001];
ll dist_xtoi[100001];
ll dist_itox[100001];
ll ans = 0;

void dijkstra(vector<node> gr[], int start) {
	fill(dist, dist + n + 1, INF);
	
	priority_queue<node, vector<node>, greater<>> pq;
	
	dist[start] = 0;
	pq.push({0, start});
	
	while (!pq.empty()) {
		auto cost = pq.top().first;
        auto now = pq.top().second;
		pq.pop();
		
		if (dist[now] < cost) continue;
		
		for (auto &p : gr[now]) {
            ll w = p.first;
            ll next = p.second;
			ll nextCost = cost + w;
			
			if (dist[next] > nextCost) {
				dist[next] = nextCost;
				pq.push({nextCost, next});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> x;
	
	for (int i = 0; i < m; i++) {
		int s, e, t;
		cin >> s >> e >> t;
		graph[s].push_back({t, e});
		rev_graph[e].push_back({t, s});
	}
	
	// x -> i
	dijkstra(graph, x);     
	for(int i = 1; i <= n; i++) {
		dist_xtoi[i] = dist[i];
	}
	
	// i -> x
	dijkstra(rev_graph, x); 
	for (int i = 1; i <= n; i++) {
		dist_itox[i] = dist[i];
	}
	
	for(int i = 1; i <= n; i++) {
		ll temp = dist_xtoi[i] + dist_itox[i];
		if (dist_xtoi[i] == INF || dist_itox[i] == INF) continue;
		else ans = max(ans, temp);
	}
	cout << ans;
	return 0;
}