#include <iostream>
#include <tuple>
#include <vector>
#include <limits.h>
using namespace std;
typedef tuple<int, int, int> edge; // <start, end, weight>

vector<edge> A;
long dist[51];
long earn[51];
int a, b, n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	fill(dist, dist+51, LONG_MIN);
	cin >> n >> a >> b >> m;
	for(int i = 0; i < m; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		A.push_back({s, e, w});
	}
	for(int i = 0; i < n; i++) {
		cin >> earn[i];
	}
	
	// Bellman-Ford
	dist[a] = earn[a];
	for(int i = 0; i < n + 50; i++) { // pCycle 확산하도록 
		for(int j = 0; j < m; j++) {
			int start = get<0>(A[j]);
			int end = get<1>(A[j]);
			int cost = get<02>(A[j]);
			if(dist[start] == LONG_MIN) continue; // S 미방문이면 continue
			else if(dist[start] == LONG_MAX) dist[end] = LONG_MAX; // S가 pCycle과 연결이면 E도 연결
			else if(dist[end] < dist[start] + earn[end] - cost) { // 더 많은 돈 벌면
				dist[end] = dist[start] + earn[end] - cost;
				if(i >= n-1) { // pCycle 이면
					dist[end] = LONG_MAX;
				}
			}
		}
	}
	if(dist[b] == LONG_MIN) cout << "gg";
	else if(dist[b] == LONG_MAX) cout << "Gee";
	else cout << dist[b];
	return 0;
}