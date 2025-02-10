#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
#define X first
#define Y second
int bor[502][502];
bool vis[502][502];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	int mx = 0, num = 0;
	// 그림 정보 입력
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> bor[i][j];
	
	// BFS
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) { // 반복 하면서 갯수 세기
			if (bor[i][j] == 0 || vis[i][j]) continue; // 방문 했거나 0이면 패스
			num++; 
			queue<pair<int, int> > q;
			vis[i][j] = 1;
			q.push({i, j});
			int area = 0;
			// 각 그림 넓이 구하기
			while (!q.empty()) {
				area++;
				pair<int, int> cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (vis[nx][ny] || bor[nx][ny] == 0) continue; // 방문 했거나 0이면 패스
					vis[nx][ny] = 1;
					q.push({nx, ny});
				}
			}
			mx = max(mx, area);
		}
	}
	cout << num << "\n" << mx;
	return 0;
}