#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> A[300001];  // 인접 리스트
int visited[300001];     // 방문 표시: -1 = 미방문, 0 이상 = 거리
vector<int> ans;         // 정답 저장
queue<int> q;

void BFS(int node) {
  visited[node] = 0;
  q.push(node);

  while (!q.empty()) {
    int now = q.front();
    q.pop();

    for (auto i : A[now]) {
      if (visited[i] == -1) {
        visited[i] = visited[now] + 1;
        q.push(i);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k, x;
  cin >> n >> m >> k >> x;

  for (int i = 1; i <= n; i++) {
    visited[i] = -1;
  }

  for (int i = 0; i < m; i++) {
    int s, e;
    cin >> s >> e;
    A[s].push_back(e);
  }

  BFS(x);

  for (int i = 1; i <= n; i++) {
    if (visited[i] == k) {
      ans.push_back(i);
    }
  }

  if (ans.empty()) {
    cout << -1;
  } else {
    sort(ans.begin(), ans.end());
    for (int i : ans) cout << i << "\n";
  }

  return 0;
}
