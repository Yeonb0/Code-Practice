#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#define X first 
#define Y second
using namespace std;
int bor[1002][1002];
int dis[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int m, n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;  
  
  queue<pair<int, int>> q;
  
  for(int i = 1; i <= m; i++) {
    for(int j = 1; j <= n; j++) {
      cin >> bor[i][j];
      if(bor[i][j] == 1) {
        dis[i][j] = 0;
        q.push({i, j}); 
      } else if(bor[i][j] == 0) {
        dis[i][j] = -1;
      } else { // bor[i][j] == -1
        dis[i][j] = -2;
      }
    }
  }
  
  // BFS 실행
  while(!q.empty()) {
    auto cur = q.front(); q.pop();
    for(int i = 0; i < 4; i++) {
      int nx = cur.X + dx[i];
      int ny = cur.Y + dy[i];
      if(nx < 1 || ny < 1 || nx > m || ny > n) continue;
      if(dis[nx][ny] != -1) continue;
      dis[nx][ny] = dis[cur.X][cur.Y] + 1;
      q.push({nx, ny});
    }
  }
  
  // 결과
  int ans = 0;
  for(int i = 1; i <= m; i++) {
    for(int j = 1; j <= n; j++) {
      if(bor[i][j] == 0 && dis[i][j] == -1) { // 익지 않은 곳 존재
        cout << -1;
        return 0;
      }
      if(dis[i][j] >= 0) ans = max(ans, dis[i][j]);
    }
  }
  cout << ans;
  return 0;
}