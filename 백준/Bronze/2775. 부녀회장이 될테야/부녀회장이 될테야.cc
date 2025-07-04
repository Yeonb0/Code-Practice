#include <iostream>
#include <vector>
using namespace std;
int v[100][15];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, k, n;
	cin >> t;
	while(t--) {
		cin >> k >> n;
		for(int i = 1; i <= n; i++) v[0][i] = i;
		for(int i = 1; i <= k; i++) {
			v[i][1] = 1;
			for(int j = 2; j <= n; j++) {
				v[i][j] = v[i][j-1] + v[i-1][j];
			}
		}
		cout << v[k][n] << "\n";
	}
	return 0;
}