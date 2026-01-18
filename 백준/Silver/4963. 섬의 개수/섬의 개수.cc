#include <iostream>
#define X first
#define Y second
using namespace std;

int bor[52][52];
bool visit[52][52];
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int w, h;

void dfs(int x, int y) {
  visit[x][y] = true;
  for (int dir = 0; dir < 8; dir++) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (nx < 1 || ny < 1 || nx > h || ny > w) continue;
    if (bor[nx][ny] == 1 && !visit[nx][ny]) {
      dfs(nx, ny);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (true) {
    cin >> w >> h;
    if (w == 0 && h == 0) break;

    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) {
        cin >> bor[i][j];
        visit[i][j] = false;
      }
    }

    int ans = 0;
    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) {
        if (bor[i][j] == 1 && !visit[i][j]) {
          dfs(i, j);
          ans++;
        }
      }
    }

    cout << ans << "\n";
  }

  return 0;
}
