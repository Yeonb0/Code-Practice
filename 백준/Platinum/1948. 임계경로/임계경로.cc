#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

vector<pair<int, int>> A[10001]; // 도착 도시, 소요 시간
vector<pair<int, int>> rA[10001]; // 출발 도시, 소요 시간
int deg[10001]; // 진입 차수
int ans[10001]; // 정답 배열
bool visited[10001]; // 방문?

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
    cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int a, b, tme;
		cin >> a >> b >> tme;
		A[a].push_back({b, tme});
		rA[b].push_back({a, tme});
		deg[b]++;
	}	
	
	int h, r; // 한걸음, 로마
	cin >> h >> r;
	
	// Topology Sort (선택받은 사람들이 모두 로마에 도착하는 데 걸리는 시간)
	queue<int> q;
	q.push(h);
	
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		
		for(auto next : A[now]) {
			deg[next.first]--;
			ans[next.first] = max(ans[next.first], ans[now] + next.second); // 차수 저장	
			if(deg[next.first] == 0) q.push(next.first);
		}
	}
	
	// Topology Sort Reverse (황금을 칠해야 할 도로의 수)
	int cnt = 0;
	q.push(r);
	visited[r] = true;
	
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		for(auto next : rA[now]) { // 쉬지 않는 도로 체크
			if(ans[next.first] + next.second == ans[now]) {
				cnt++;
				if(!visited[next.first]) {
					visited[next.first] = true;
					q.push(next.first);
				}
			}
		}
	}
	cout << ans[r] << "\n";
	cout << cnt;
	return 0;
}