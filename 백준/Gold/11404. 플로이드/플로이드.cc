#include <iostream>
#include <algorithm>
using namespace std;

long long dist[101][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == j) dist[i][j] = 0;
			else dist[i][j] = 100000001;
		}
	}
	for(int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if(c < dist[a][b]) dist[a][b] = c;
	}
	
	//Floyd-Warshall
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(dist[i][j] == 100000001) cout << "0 ";
			else cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}