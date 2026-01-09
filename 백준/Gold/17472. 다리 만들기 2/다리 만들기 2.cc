#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

int n, m;
int island = 1;
int map[101][101];
bool visit[101][101];
bool visit2[101][101];
int p[7];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

typedef struct Edge {
  int s, e, v;
  bool operator>(const Edge& temp) const {
    return v > temp.v;
  }
} Edge;

priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

// 섬 번호 매기기 
void makeIsland(int i, int j) {
  queue<pair<int, int>> q;
  q.push({i, j});
  visit[i][j] = true;
  map[i][j] = island;

  while(!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(int k = 0; k < 4; k++) {
      int nx = x + dx[k];
      int ny = y + dy[k];

      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(visit[nx][ny]) continue;
      if(map[nx][ny] == 0) continue;

      visit[nx][ny] = true;
      map[nx][ny] = island;
      q.push({nx, ny});
    }
  }
}

// 다리 만들기 (직선 탐색) 
void makeBridge(int i, int j) {
  int isNum = map[i][j];

  for(int d = 0; d < 4; d++) {
    int nx = i + dx[d];
    int ny = j + dy[d];
    int len = 0;

    while(nx >= 0 && nx < n && ny >= 0 && ny < m) {
      if(map[nx][ny] == isNum) break;

      if(map[nx][ny] != 0) {
        if(len >= 2) {
          pq.push({isNum, map[nx][ny], len});
        }
        break;
      }

      nx += dx[d];
      ny += dy[d];
      len++;
    }
  }
}

int find(int x) {
  if(x == p[x]) return x;
  return p[x] = find(p[x]);
}

void uni(int a, int b) {
  a = find(a);
  b = find(b);
  if(a != b) p[b] = a;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> map[i][j];
    }
  }

  // 1. 섬 번호 매기기 -> BFS
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(map[i][j] != 0 && !visit[i][j]) {
        makeIsland(i, j);
        island++;
      }
    }
  }

  // 2. 다리 만들기
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(map[i][j] != 0) {
        makeBridge(i, j);
      }
    }
  }

  // 3. 가장 짧은 다리 길이 -> MST && UF
  for(int i = 1; i < island; i++) {
    p[i] = i;
  }

  int used = 0;
  int ans = 0;

  while(!pq.empty()) {
    Edge now = pq.top();
    pq.pop();

    if(find(now.s) != find(now.e)) {
      uni(now.s, now.e);
      ans += now.v;
      used++;
    }
  }

  if(used == island - 2) cout << ans;
  else cout << -1;

  return 0;
}
