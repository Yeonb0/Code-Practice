#include <iostream>
using namespace std;

int dist[101][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == j) dist[i][j] = 0;
			else dist[i][j] = 1000001;
		}
	}
	
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		dist[a][b] = 1;
		dist[b][a] = 1;
	}
	
	// Floyd-Warshall
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	
	int Min = 100000;
	int ans = -1;
	for(int i = 1; i <= n; i++) {
		int tmp = 0;
		for(int j = 1; j <= n; j++) {
			tmp += dist[i][j];
		}
		if(tmp < Min) {
			Min = tmp;
			ans = i;
		}
	}
	cout << ans;
}