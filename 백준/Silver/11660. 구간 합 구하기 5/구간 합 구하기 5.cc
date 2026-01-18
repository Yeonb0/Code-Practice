#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> A(n+1, vector<int>(n+1, 0));
	vector<vector<int>> S(n+1, vector<int>(n+1, 0));
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> A[i][j];
			// 합 배열
			S[i][j] = S[i-1][j] + S[i][j-1] + A[i][j] - S[i-1][j-1];
		}
	}
	for(int i = 0; i < m; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int result = S[x2][y2] - S[x1-1][y2] - S[x2][y1-1] + S[x1-1][y1-1];
		cout << result << "\n";
	}
	return 0;
}