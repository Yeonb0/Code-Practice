#include <iostream>
#include <queue>
using namespace std;
char map[601][601];
bool visit[601][601];
queue<pair<int, int>> q;

int n, m;
int ans = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void BFS(int sx, int sy) {
	visit[sx][sy] = true;
	q.push({sx, sy});
	
	while(!q.empty()) {
		auto x = q.front().first;
		auto y = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(map[nx][ny] == 'X') continue;
			else if(map[nx][ny] == 'P' && !visit[nx][ny]) {
				visit[nx][ny] = true;
				ans++;
				q.push({nx, ny});
			} else if(map[nx][ny] == 'O' && !visit[nx][ny]) {
				visit[nx][ny] = true;
				q.push({nx, ny});
			}
		}
	}
}			

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			char c;
			cin >> c;
			if(c == 'I') {
				a = i; b = j;
			}
			map[i][j] = c;
		}
	}
	BFS(a, b);
  if(ans == 0) cout << "TT";
	else cout << ans;
	return 0;
}