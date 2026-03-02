#include <iostream>
#include <vector>
#include <limits.h>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> edge; // 출발, 도착, 걸리는 시간

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	while(tc--) {
		int n, m, w;
		cin >> n >> m >> w;
		vector<int> Dist(n + 1);
		fill(Dist.begin(), Dist.end(), 0);
		vector<edge> V;
		
		for(int i = 0; i < m; i++) { // 양수 쌍방 간선
			int s, e, t;
			cin >> s >> e >> t;
			V.push_back({s, e, t});
			V.push_back({e, s, t});
		}
		for(int i = 0; i < w; i++) { // 음수 일방 간선
			int s, e, t;
			cin >> s >> e >> t;
			V.push_back({s, e, -t});
		}
		
		// Bellman-Ford
		for(int i = 1; i < n; i++) { // n-1 번 반복
			for(int j = 0; j < 2 * m + w; j++) { // 전체 간선에 대해
				int start = get<0>(V[j]); 
				int end = get<1>(V[j]);
				int time = get<2>(V[j]);
				// 더 가까운 최단 거리 있으면 갱신
				if(Dist[start] != INT_MAX && Dist[end] > Dist[start] + time) {
					Dist[end] = Dist[start] + time;
				}
			}					
		}
		
		// 음수 사이클 체크 (n번째 순회)
		bool mCycle = false;
		for(int j = 0; j < 2 * m + w; j++) {
			int start = get<0>(V[j]); 
			int end = get<1>(V[j]);
			int time = get<2>(V[j]);
			// 더 가까운 최단 거리 있으면 음수 사이클 -> YES
			if(Dist[start] != INT_MAX && Dist[end] > Dist[start] + time) {
				mCycle = true;
				break;
			} 
		}
		if(mCycle) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
