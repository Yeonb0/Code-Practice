#include <iostream>
#include <vector>
using namespace std;

vector<int> adj;
vector<bool> visited;
vector<bool> finished;
int ans = 0;

void dfs(int n) {
  visited[n] = true;

  int next = adj[n];
  if (!visited[next]) {
    dfs(next);
  } else if (!finished[next]) {
    // 사이클 크기 세기
    for (int i = next; i != n; i = adj[i]) ans++;
    ans++;
  }

  finished[n] = true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    ans = 0;

    adj.assign(n + 1, 0);
    visited.assign(n + 1, false);
    finished.assign(n + 1, false);

    for (int i = 1; i <= n; i++) {
      cin >> adj[i];
    }

    for (int i = 1; i <= n; i++) {
      if (!visited[i]) dfs(i);
    }

    cout << n - ans << "\n";
  }

  return 0;
}
