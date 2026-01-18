#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#define X first
#define Y second
using namespace std;

int board[102][102];
int island_id[102][102];  
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;

// 섬을 찾기
void find_island(int x, int y, int id) {
  queue<pair<int, int>> q;
  island_id[x][y] = id;
  q.push({x, y});
  
  while(!q.empty()) {
    auto cur = q.front(); 
    q.pop();
    
    for(int i = 0; i < 4; i++) {
      int nx = cur.X + dx[i];
      int ny = cur.Y + dy[i];
      
      if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
      if(board[nx][ny] == 0 || island_id[nx][ny] != 0) continue;
      
      island_id[nx][ny] = id;
      q.push({nx, ny});
    }
  }
}

// 다리 길이
int find_bridge(int start_island) {
  queue<pair<int, int>> q;
  int dist[102][102];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      dist[i][j] = -1;
    }
  }
  
  // 섬에서부터 시작
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(island_id[i][j] == start_island) {
        q.push({i, j});
        dist[i][j] = 0;
      }
    }
  }
  
  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    
    for(int i = 0; i < 4; i++) {
      int nx = cur.X + dx[i];
      int ny = cur.Y + dy[i];
      if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
      if(dist[nx][ny] != -1) continue;
      
      if(island_id[nx][ny] != 0 && island_id[nx][ny] != start_island) { // 다른 섬
        return dist[cur.X][cur.Y];
      }
      if(island_id[nx][ny] == 0) { // 바다
        dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        q.push({nx, ny});
      }
    }
  }
  return 987654321;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  // 입력
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }
  
  // 섬 찾기
  int island_count = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(board[i][j] == 1 && island_id[i][j] == 0) {
        find_island(i, j, ++island_count);
      }
    }
  }
  
  // 다리 길이
  int answer = 987654321;
  for(int i = 1; i <= island_count; i++) {
    answer = min(answer, find_bridge(i));
  }
  
  cout << answer << "\n";
  
  return 0;
}