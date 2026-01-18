#include <iostream>
#include <tuple>
#include <vector>
#include <limits.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef tuple<int, int, int> edge; // <start, end, weight>

vector<edge> A;
long dist[501];
int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	fill(dist, dist+501, LONG_MAX);
	for(int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		A.push_back({a, b, c});
	}
	
	// Bellman-Ford
	dist[1] = 0;
	for(int i = 1; i < n; i++) { // n-1번 반복
		for(int j = 0; j < m; j++) {
			int start = get<0>(A[j]);	
			int end = get<1>(A[j]);	
			int time = get<2>(A[j]);	
			// 더 가까운 최단 거리 있으면 갱신
			if(dist[start] != LONG_MAX && dist[end] > dist[start] + time) {
				dist[end] = dist[start] + time;
			}
		}
	}
	
	// 음수 사이클 확인
	bool mCycle = false;
	for(int j = 0; j < m; j++) {
		int start = get<0>(A[j]);	
		int end = get<1>(A[j]);	
		int time = get<2>(A[j]);	
		// 더 가까운 최단 거리 있으면 음수 사이클
		if(dist[start] != LONG_MAX && dist[end] > dist[start] + time) {
			mCycle = true;
		}
	}
	
	// 출력
	if(!mCycle) {
		for(int i = 2; i <= n; i++) {
			if(dist[i] == LONG_MAX) cout << -1 << "\n";
			else cout << dist[i] << "\n";
		}
	} else cout << -1;
	return 0;			
}