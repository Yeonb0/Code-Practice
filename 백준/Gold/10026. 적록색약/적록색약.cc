#include <iostream>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

char map[101][101];
bool v1[101][101];
bool v2[101][101];

int n;
int ans1, ans2;

// 적록색약 X
void DFS1(int x, int y, char c) {
  v1[x][y] = true;

  for(int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
    if(v1[nx][ny]) continue;

    if(map[nx][ny] == c) {
      DFS1(nx, ny, c);
    }
  }
}

// 적록색약 O
void DFS2(int x, int y) {
  v2[x][y] = true;

  for(int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
    if(v2[nx][ny]) continue;

    // 현재 칸이 B
    if(map[x][y] == 'B') {
      if(map[nx][ny] == 'B') {
        DFS2(nx, ny);
      }
    }
    // 현재 칸이 R 또는 G
    else {
      if(map[nx][ny] == 'R' || map[nx][ny] == 'G') {
        DFS2(nx, ny);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> map[i][j];
    }
  }

  // 적록색약 X
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(!v1[i][j]) {
        ans1++;
        DFS1(i, j, map[i][j]);
      }
    }
  }

  // 적록색약 O
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(!v2[i][j]) {
        ans2++;
        DFS2(i, j);
      }
    }
  }

  cout << ans1 << " " << ans2;
  return 0;
}
