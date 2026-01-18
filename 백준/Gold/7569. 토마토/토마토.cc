#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int dx[6] = {0, 0, 0, 0, 1, -1}; // x: 열 방향
int dy[6] = {0, 0, 1, -1, 0, 0}; // y: 행 방향
int dz[6] = {1, -1, 0, 0, 0, 0}; // z: 높이 방향

int bor[102][102][102]; // 3차원 토마토 상태
int dis[102][102][102]; // 일 수 저장 배열
int m, n, h; // 가로, 세로, 높이

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> m >> n >> h;
  
  for(int z = 1; z <= h; z++) {
    for(int y = 1; y <= n; y++) {
      for(int x = 1; x <= m; x++) {
        cin >> bor[z][y][x];
      }
    }
  }

  queue<tuple<int, int, int>> q;

  for(int z = 1; z <= h; z++) {
    for(int y = 1; y <= n; y++) {
      for(int x = 1; x <= m; x++) {
        if(bor[z][y][x] == 1) {
          q.push({z, y, x});
          dis[z][y][x] = 0;
        } else if(bor[z][y][x] == 0) {
          dis[z][y][x] = -1;
        } else {
          dis[z][y][x] = -2;
        }
      }
    }
  }

  while(!q.empty()) {
    auto cur = q.front(); q.pop();
    int z = get<0>(cur);
    int y = get<1>(cur);
    int x = get<2>(cur);

    for(int i = 0; i < 6; i++) {
      int nz = z + dz[i];
      int ny = y + dy[i];
      int nx = x + dx[i];

      if(nz < 1 || ny < 1 || nx < 1 || nz > h || ny > n || nx > m) continue;
      if(dis[nz][ny][nx] != -1) continue;

      dis[nz][ny][nx] = dis[z][y][x] + 1;
      q.push({nz, ny, nx});
    }
  }

  int ans = 0;
  for(int z = 1; z <= h; z++) {
    for(int y = 1; y <= n; y++) {
      for(int x = 1; x <= m; x++) {
        if(bor[z][y][x] == 0 && dis[z][y][x] == -1) {
          cout << -1;
          return 0;
        }
        if(dis[z][y][x] >= 0)
          ans = max(ans, dis[z][y][x]);
      }
    }
  }

  cout << ans;
  return 0;
}
