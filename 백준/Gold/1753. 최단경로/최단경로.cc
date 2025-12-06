#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 0x3f3f3f3f
int v, e, k;

typedef pair<int, int> node;
vector<node> A[20001];
bool visited[20001];
int len[20001];
priority_queue<node, vector<node>, greater<node>> q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> v >> e >> k;
	fill(len, len + 20001, INF);
	for(int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		A[u].push_back({v, w});
	}
	
	// Dijkstra
	q.push({0, k});
	len[k] = 0;
	
	while(!q.empty()) {
		auto now = q.top();
		q.pop();
		int now_n = now.second;
		if(visited[now_n]) continue; // 이미 방문 했으면 넘어가기
		visited[now_n] = true;
		
		for(int i = 0; i < A[now_n].size(); i++) { // 지금 노드랑 연결된 거 순회하면서
			auto next_n = A[now_n][i].first;  // 노드랑
			auto next_v = A[now_n][i].second; // 값 저장
			
			if(len[next_n] > len[now_n] + next_v) { // 최소 거리 업데이트
				len[next_n] = next_v + len[now_n];
				q.push({len[next_n], next_n});
			}
		}
	}
	for(int i = 1; i <= v; i++) { // 거리 출력
		if(visited[i]) {
			cout << len[i] << "\n";
		} else {
            cout << "INF" << "\n";
        }
	}
	return 0;		
}