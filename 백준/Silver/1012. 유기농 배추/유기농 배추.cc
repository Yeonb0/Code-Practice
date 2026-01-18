#include <iostream>
#include <vector>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int map[52][52];
bool vis[52][52];
int ans;
int m, n, cab;

void dfs(int x, int y) {
	vis[x][y] = true;
	int nx, ny;
	for(int i = 0; i < 4; i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
		else if(!vis[nx][ny] && map[nx][ny] == 1){
			vis[nx][ny] = true;
			dfs(nx, ny);
		}
	}
}
	

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		cin >> m >> n >> cab;
        ans = 0;
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				map[i][j] = 0;
                vis[i][j] = false;
			}
		}
		while(cab--) {
			int a, b;
			cin >> a >> b;
			map[a][b] = 1;
		}
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				if(map[i][j] == 1 && !vis[i][j]){
					ans++;
					dfs(i, j);
				}
			}
		}
        cout << ans << "\n";
	}
}