#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int map[1001][1001];
int dist[1001][1001];
bool vis[1001][1001];
queue<pair<int, int>> q;

void BFS(int x, int y) {
	q.push({x, y});
	vis[x][y] = true;
	
	while(!q.empty()) {
		auto now = q.front();
		q.pop();
		for(int i = 0; i < 4; i++) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if(nx < 0 || ny < 0 || nx > 1000 || ny > 1000) continue;
			if(vis[nx][ny]) continue;
      if(map[nx][ny] == 0) continue;  // 이동 불가
			else if(map[nx][ny] == 1 && !vis[nx][ny]) { // 이동 가능 & 방문 X 라면
				q.push({nx, ny});
				dist[nx][ny] = dist[now.first][now.second] + 1;
				vis[nx][ny] = true;
			}
		}
	}
}
				
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	int sx, sy;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int input;
			cin >> input;
			if(input == 2) {
				sx = i; sy = j;
			}
			map[i][j] = input;
		}
	}
	
	BFS(sx, sy);
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(!vis[i][j] && map[i][j] == 1) cout << "-1 ";
			else cout << dist[i][j] << " ";
		}
        cout << "\n";
	}
	return 0; 
}