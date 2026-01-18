#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> node;
int n, m, k;
int A[1001][1001];
priority_queue<int> dist[1001];
priority_queue<node, vector<node>, greater<node>> q; // <거리, 노드>

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  for(int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    A[a][b] = c;
  }

  // Dijkstra
  q.push({0, 1});
  dist[1].push(0); // 1번 노드의 첫 번째 경로

  while(!q.empty()) {
    auto now = q.top();
    q.pop();

    for(int nex = 1; nex <= n; nex++) {
      if(A[now.second][nex] != 0) { // 간선 존재
        int newCost = now.first + A[now.second][nex];

        if(dist[nex].size() < k) { // k개 미만 저장되어 있으면 추가
          dist[nex].push(newCost);
          q.push({newCost, nex});
        }
        else if(dist[nex].top() > newCost) { // k개 있지만 더 좋은 경로면 교체
          dist[nex].pop();
          dist[nex].push(newCost);
          q.push({newCost, nex});
        }
      }
    }
  }

  for(int i = 1; i <= n; i++) {
    if(dist[i].size() == k) cout << dist[i].top() << "\n";
    else cout << -1 << "\n";
  }
  return 0;
}
