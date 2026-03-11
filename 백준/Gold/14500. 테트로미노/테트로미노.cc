#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int A[501][501];
bool vis[501][501];
int ans;
int n, m;

void DFS(int x, int y, int cnt, int tot);
void T(int x, int y);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> A[i][j];
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			vis[i][j] = true;
			DFS(i, j, 1, A[i][j]);
			vis[i][j] = false;
            
            T(i, j);
		}
	}
	cout << ans;
	
	return 0;
}

void DFS(int x, int y, int cnt, int tot) {
	if(cnt == 4) {
		ans = max(ans, tot);
		return;
	}
	
	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx >= n || nx < 0 || ny >= m || ny < 0) continue;
		
		if(!vis[nx][ny]) {
			vis[nx][ny] = true;
			DFS(nx, ny, cnt + 1, tot + A[nx][ny]);
			vis[nx][ny] = false;
		}
	}
}

void T(int x, int y) {
	int cnt = 0; // 이웃 수
	int sum = A[x][y]; // 이웃 합
	int mn = INT_MAX; // 최솟값 이웃
	
	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx >= n || nx < 0 || ny >= m || ny < 0) continue;
		else {
			cnt++;
			sum += A[nx][ny];
			mn = min(mn, A[nx][ny]);
		}
	}
	
	if(cnt == 3) ans = max(ans, sum);
	if(cnt == 4) ans = max(ans, sum-mn);
}