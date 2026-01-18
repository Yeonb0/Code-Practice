#include <iostream>
#include <queue>
#include <utility>
#define X first
#define Y second
using namespace std;

int bor[102][102];
int dis[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    string line;
    cin >> line;
    for(int j = 1; j <= m; j++) {
      bor[i][j] = line[j-1] - '0';
      dis[i][j] = -1;
    }
  }

  queue<pair<int, int>> q;
  q.push({1, 1});
  dis[1][1] = 0;

  while(!q.empty()) {
    auto cur = q.front(); q.pop();
    for(int i = 0; i < 4; i++) {
      int nx = cur.X + dx[i];
      int ny = cur.Y + dy[i];
      if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
      if(bor[nx][ny] == 0 || dis[nx][ny] != -1) continue;
      dis[nx][ny] = dis[cur.X][cur.Y] + 1;
      q.push({nx, ny});
    }
  }

  cout << dis[n][m] + 1;
  return 0;
}
