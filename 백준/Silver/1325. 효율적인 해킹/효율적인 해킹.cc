#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> A[10001];
bool visited[10001];
int ans[10001];

void BFS(int start) {
  queue<int> q;
  q.push(start);
  visited[start] = true;

  while(!q.empty()) {
    int now = q.front();
    q.pop();
    for(int next : A[now]) {
      if(!visited[next]) {
        visited[next] = true;
        ans[start]++;   // start에서 갈 수 있는 노드 증가
        q.push(next);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  // 간선 방향 B -> A
  for(int i = 0; i < m; i++) {
    int s, e;
    cin >> s >> e;
    A[e].push_back(s);
  }

  for(int i = 1; i <= n; i++) {
    fill(visited, visited + n + 1, false);
    BFS(i);
  }

  int maxVal = 0;
  for(int i = 1; i <= n; i++)
    maxVal = max(maxVal, ans[i]);

  for(int i = 1; i <= n; i++)
    if(ans[i] == maxVal)
      cout << i << " ";

  return 0;
}
